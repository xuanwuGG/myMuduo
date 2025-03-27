#include"Channel.h"
#include"Logger.h"
#include"EventLoop.h"

#include<sys/epoll.h>


static const int kNoneEvent = 0;
static const int kReadEvent = EPOLLIN | EPOLLPRI;
static const int kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop* loop, int fd)
    :loop_(loop),
    fd_(fd),
    events_(0),
    revents_(0),
    index_(-1), //此处的-1表示该channel还没有被添加到poller中，在epollpoller可以找到相关定义
    tied_(false)
{
}

Channel::~Channel() //muduo中会判断是否有eventhadling正在处理，当前Loop是否在其所在的线程中被析构
{
}

void Channel::tie(const std::shared_ptr<void>& obj)
{
    tie_ = obj;
    tied_ = true;
}
//当改变channel所表示的fd的状态时，调用update，在poller中更新fd的状态（epoll_ctl）
void Channel::update()
{
    loop_->updateChannel(this);
    //TODO:Channel::loop_->updateChannel(this);
}
//在Channel所属的EventLoop中，把当前的Channel对象从poller中移除
void Channel::remove()
{
    loop_->removeChannel(this);
    //TODO:loop_->removeChannel(this);
}

void Channel::handleEvent(TimeStamp receiveTime)
{
    if(tied_)
    {
        std::shared_ptr<void> guard = tie_.lock();//提升为shared_ptr
        if(guard)
        {
            handleEventWithGuard(receiveTime);
        }
        else{
            handleEventWithGuard(receiveTime);
        }
    }
        
}
//poller通知后，Channerl调用handleEvent
void Channel::handleEventWithGuard(TimeStamp receiveTime)
{
    LOG_INFO("Channel handleEvent revents = %d\n", revents_); //之后调试的时候，可以使用其他宏来使得输出更加详细，比如__FILE__ __LINE__等
    if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN))
    {
        if (closeCallback_) closeCallback_();
    }
    if (revents_ & EPOLLERR)
    {
        if (errorCallback_) errorCallback_();
    }
    if (revents_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP))
    {
        if (readCallback_) readCallback_(receiveTime);
    }
    if (revents_ & EPOLLOUT)
    {
        if (writeCallback_) writeCallback_();
    }
}