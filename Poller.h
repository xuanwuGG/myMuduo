#pragma once

//muduo库中多路事件分发器的核心IO服用模块

#include"noncopyable.h"

#include<vector>
#include<unordered_map>

class Channel;
class EventLoop;
class TimeStamp;
class Poller : noncopyable{
public:
    using ChannelList = std::vector<Channel*>;

    Poller(EventLoop* loop);
    virtual ~Poller()=default;
    //给所有IO复用，保留统一接口
    virtual TimeStamp poll(int timeoutMs, ChannelList* activeChannels) = 0;
    virtual void updateChannel(Channel* channel) = 0;
    virtual void removeChannel(Channel* channel) = 0;
    //判断channel是否在当前Poller中
    bool hasChannel(Channel* channel) const;
    //EventLoop可以通过该函数获取默认的IO复用的具体实现
    static Poller* newDefaultPoller(EventLoop* loop);

protected:
    //map的key是文件描述符，value是对应的Channel
    using ChannelMap = std::unordered_map<int, Channel*>;
    ChannelMap channels_;
private:
//定义Poller所属事件循环
    EventLoop* ownerLoop_;

};
