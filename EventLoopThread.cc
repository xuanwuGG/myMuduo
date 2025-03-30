#include"EventLoopThread.h"
#include"EventLoop.h"

EventLoopThread::EventLoopThread(const ThreadInitCallback& cb, const std::string& name)
    :loop_(nullptr),
    exiting_(false),
    thread_(std::bind(&EventLoopThread::threadFunc, this), name),
    mutex_(),
    cond_(),
    callback_(cb)
{
}

EventLoopThread::~EventLoopThread()
{
    exiting_ = true;
    if(loop_ != nullptr)
    {
        loop_->quit();
        thread_.join();
    }
}

EventLoop* EventLoopThread::startLoop()
{
    thread_.start();
    EventLoop* loop = nullptr;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        while(loop_ == nullptr)
        {
            cond_.wait(lock);  
        }
        loop = loop_;
    }
    return loop;  
}


//这个方法是在新线程中执行的
void EventLoopThread::threadFunc()
{
    EventLoop loop;  //该Loop是和上面创建的那个线程是一一对应的
    if(callback_)
    {
        callback_(&loop);  
    }
    {
        std::unique_lock<std::mutex> lock(mutex_);
        loop_ = &loop;
        cond_.notify_one();  
    }
    loop.loop();
    std::unique_lock<std::mutex> lock(mutex_);
    loop_ = nullptr;  
}    