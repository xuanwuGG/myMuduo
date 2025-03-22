#include "EpollPoller.h"
#include "Logger.h"
#include<errno.h>
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