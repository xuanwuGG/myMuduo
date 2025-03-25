#include "EpollPoller.h"
#include "Channel.h"

#include "Logger.h"
#include<errno.h>
#include<unistd.h>
#include<string.h>
namespace//表示channel在poller的状态
{
    const int kNew = -1;
    const int kAdded = 1;
    const int kDeleted = 2;
}

EpollPoller::EpollPoller(EventLoop* loop)
    : Poller(loop),
      epollfd_(::epoll_create1(EPOLL_CLOEXEC)),
      events_(kInitEventListSize)
{
    if(epollfd_ < 0)
    {
        LOG_FATAL("EpollPoller::EpollPoller() err:%d", errno);
    }
}   

EpollPoller::~EpollPoller()
{
    ::close(epollfd_);
}

void EpollPoller::updateChannel(Channel* channel)
{
    const int index = channel->index();
    LOG_INFO("func=%s => fd=%d events=%d index=%d \n", __FUNCTION__, channel->fd(), channel->events(), index);
    if(index == kNew || index == kDeleted)
    {
        if(index == kNew)
        {
            int fd = channel->fd();
            channels_[fd] = channel;
        }
        channel->set_index(kAdded);
        update(EPOLL_CTL_ADD, channel);
    }
    else
    {
        int fd = channel->fd();
        if(channel->isNoneEvent())
        {
            update(EPOLL_CTL_DEL, channel);
            channel->set_index(kDeleted);
        }
        else
        {
            update(EPOLL_CTL_MOD, channel);
        }
    }
    if(index == kNew || index == kDeleted)
    {
        if(index == kNew)
        {
            int fd = channel->fd();
            channels_[fd] = channel;
        }
        channel->set_index(kAdded);
        update(EPOLL_CTL_ADD, channel);
    }
    else //channel已经在epoll中注册
    {
        int fd = channel->fd();
        if(channel->isNoneEvent())
        {
            update(EPOLL_CTL_DEL, channel);
            channel->set_index(kDeleted);
        }
        else
        {
            update(EPOLL_CTL_MOD, channel);
        }
    }
}

//更新channel通道， epoll_ctl add/mod/del
void EpollPoller::update(int operation, Channel* channel)
{
    epoll_event event;
    bzero(&event, sizeof event);
    event.events = channel->events();
    event.data.ptr = channel;
    event.data.fd = channel->fd();
    int fd = channel->fd();

    if(::epoll_ctl(epollfd_, operation, fd, &event) < 0)
    {
        if(operation == EPOLL_CTL_DEL)
        {
            LOG_ERROR("epoll_ctl del error:%d", errno);
        }
        else
        {
            LOG_FATAL("epoll_ctl add/mod error:%d", errno);
        }
    }

}
//从poller中移除channel
void EpollPoller::removeChannel(Channel* channel)
{
    LOG_INFO("func=%s => fd = %d",__FUNCTION__, channel->fd());
    int fd = channel->fd();
    int index = channel->index();
    channels_.erase(fd);
    if(index == kAdded)
    {
        update(EPOLL_CTL_DEL, channel);
    }
    channel->set_index(kNew);
}

TimeStamp EpollPoller::poll(int timeoutMs, ChannelList* activeChannels)
{
    //log_debug输出日志更合理
    LOG_INFO("func=%s => fd total count:%d\n", __FUNCTION__, static_cast<int>(channels_.size()));

    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), static_cast<int>(events_.size()), timeoutMs);
    int saveErrno = errno;
    TimeStamp now(TimeStamp::now());
    if(numEvents > 0)
    {
        LOG_INFO("%d events happened\n", numEvents);
        fillActiveChannels(numEvents, activeChannels);
        if(numEvents == events_.size())
        {
            events_.resize(events_.size() * 2);
        }
    }
    else if(numEvents == 0)
    {
        LOG_INFO("%s timeout!\n", __FUNCTION__);
    }
    else
    {
        if(saveErrno != EINTR)
        {
            errno = saveErrno;
            LOG_FATAL("EpollPoller::poll() err");
        }
    }
    return now;
}

void EpollPoller::fillActiveChannels(int numEvents, ChannelList* activeChannels) const
{
    for(int i = 0; i < numEvents; ++i)
    {
        Channel* channel = static_cast<Channel*>(events_[i].data.ptr);
        channel->set_revents(events_[i].events);
        activeChannels->push_back(channel);//eventloop拿到了poller返回的活跃channel列表
    }
}