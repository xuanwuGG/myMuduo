#pragma once
#include "Poller.h"
#include "TimeStamp.h"

#include<vector>
#include<sys/epoll.h>
/*  
epoll的使用
1. epoll_create ,在构造函数中被调用
2. epoll_ctl add/mod/del 在updateChannel中被调用
3. epoll_wait 在poll中被调用
*/
class Channel;
class EpollPoller : public Poller
{
public:
    EpollPoller(EventLoop* loop);
    ~EpollPoller() override;
    //重写基类的抽象方法
    TimeStamp poll(int timeoutMs, ChannelList* activeChannels) override;
    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;    

private:
    static const int kInitEventListSize = 16;
    //填写活跃表
    void fillActiveChannels(int numEvents, ChannelList* activeChannels) const;
    //更新channel通道
    void update(int operation, Channel* channel);
    using ChannelList = std::vector<Channel*>;
    int epollfd_;

    using EventList = std::vector<struct epoll_event>;
    EventList events_;
};