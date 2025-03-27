#include "EventLoop.h"
#include "Logger.h"
#include "Poller.h"
#include "Channel.h"

#include<sys/eventfd.h>
#include<unistd.h>
#include<fcntl.h>
#include<memory>
//防止一个线程创建多个EventLoop，注意__thread是gcc内置的变量，线程局部存储
__thread EventLoop* t_loopInThisThread = nullptr;

//定义默认Poller IO复用的超时时间
const int kPollTimeMs = 10000;

//创建eventfd,用notify唤醒subReactor处理新来的channel
int createEventfd()
{
    int evtfd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if(evtfd < 0)
    {
        LOG_FATAL("Failed in eventfd:%d",errno);
    }    
    return evtfd;
}

EventLoop::EventLoop()
    :looping_(false),
    quit_(false),
    callingPendingFunctors_(false),
    threadId_(CurrentThread::tid()),
    poller_(Poller::newDefaultPoller(this)),
    wakeupFd_(createEventfd()),
    wakeupChannel_(new Channel(this, wakeupFd_))
    {
        LOG_DEBUG("EventLoop created %p in thread %d\n", this, threadId_);
        if(t_loopInThisThread)
        {
            LOG_FATAL("Another EventLoop %p exists in this thread %d\n", t_loopInThisThread, threadId_);
        }
        else
        {
            t_loopInThisThread = this;
        }

        //设置wakeupfd的事件类型以及回调函数
        wakeupChannel_->setReadCallback(std::bind(&EventLoop::handleRead, this));
        //每一个EventLoop对象都关注wakeupChannel_的EPOLLIN事件
        wakeupChannel_->enableReading();
    }

EventLoop::~EventLoop()
{
    wakeupChannel_->disableAll();
    wakeupChannel_->remove();
    ::close(wakeupFd_);
    t_loopInThisThread = nullptr;
}

void EventLoop::handleRead()
{
    uint64_t one = 1;
    ssize_t n = read(wakeupFd_, &one, sizeof one);
    if(n != sizeof one)
    {
        LOG_ERROR("EventLoop::handleRead() reads %ld bytes instead of 8", n);
    }
}

void EventLoop::loop()
{
    looping_ = true;
    quit_ = false;
    LOG_INFO("EventLoop %p start looping\n", this);
    while(!quit_)
    {
        activeChannels_.clear();
        pollReturnTime_ = poller_->poll(kPollTimeMs, &activeChannels_);
        for(Channel* channel : activeChannels_)
        {
            //poller监听哪些channel发生事件，然后上报给EventLoop。通知channel处理事件
            channel->handleEvent(pollReturnTime_);
        }
        //执行当前EventLoop事件循环需要处理的回调函数

        doPendingFunctors();
    }
    LOG_INFO("EventLoop %p stop looping\n", this);
    looping_ = false;
}

void EventLoop::quit()
{
    quit_ = true;
    //如果不是在当前IO线程调用quit()，则需要唤醒loop所在线程
    if(!isInLoopThread())
    {
        wakeup();
    }
}

//在当前线程中执行回调
void EventLoop::runInLoop(Functor cb)
{
    if(isInLoopThread())
    {
        cb();
    }
    else
    {
        queueInLoop(cb);  //在非IO线程中执行回调，就需要唤醒IO线程
    }
}

void EventLoop::queueInLoop(Functor cb)
{
    {
        std::unique_lock<std::mutex> lock(mutex_);
        pendingFunctors_.emplace_back(cb);
    }

    //唤醒需要执行回调函数的IO线程
    if(!isInLoopThread() || callingPendingFunctors_)
    {
        wakeup();
    }
}

void EventLoop::updateChannel(Channel* channel)
{
    poller_->updateChannel(channel);
}

void EventLoop::removeChannel(Channel* channel)
{
    poller_->removeChannel(channel);
}

bool EventLoop::hasChannel(Channel* channel)
{
    return poller_->hasChannel(channel);
}

void EventLoop::wakeup()
{
    uint64_t one = 1;
    ssize_t n = write(wakeupFd_, &one, sizeof one);
    if(n != sizeof one)
    {
        LOG_ERROR("EventLoop::wakeup() writes %ld bytes instead of 8", n);
    }
}

void EventLoop::doPendingFunctors()
{
    std::vector<Functor> functors;
    callingPendingFunctors_ = true;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        functors.swap(pendingFunctors_);
    }
    for(const Functor& functor : functors)
    {
        functor();
    }
    callingPendingFunctors_ = false;
}