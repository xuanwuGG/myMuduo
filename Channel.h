#pragma once
#include<functional>
#include<memory>

#include"TimeStamp.h"
#include"noncopyable.h"
//通道，封装sockfd和感兴趣的event（epollin、epollout），以及返回具体事件

class EventLoop;

class Channel:noncopyable
{
public:
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(TimeStamp)>;
    Channel(EventLoop* loop, int fd);
    ~Channel();
    //fd得到poller通知后，调用handleEvent
    void handleEvent(TimeStamp receiveTime);

    //设置回调函数
    void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
    void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
    void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
    void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }

    //防止channel被销毁时，还在调用回调函数
    void tie(const std::shared_ptr<void>&);

    int fd() const { return fd_; }
    int events() const { return events_; }
    void set_revents(int revt) { revents_ = revt; } //poller监听后用来设置具体事件

    //设置fd相应的状态
    void enableReading() { events_ |= kReadEvent; update(); }
    void disableReading() { events_ &= ~kReadEvent; update(); }
    void enableWriting() { events_ |= kWriteEvent; update(); }
    void disableWriting() { events_ &= ~kWriteEvent; update(); }
    void disableAll() { events_ = kNoneEvent; update(); }

    //返回fd当前状态
    bool isWriting() const { return events_ & kWriteEvent; }
    bool isReading() const { return events_ & kReadEvent; }
    bool isNoneEvent() const { return events_ == kNoneEvent; }


    int index() { return index_; }
    void set_index(int idx) { index_ = idx; }

    EventLoop* ownerLoop() { return loop_; }
    //移除channel
    void remove();

    private:

    void update();
    void handleEventWithGuard(TimeStamp receiveTime); 
    //表达fd状态
    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;
    //事件循环
    EventLoop* loop_;
    //poller监听的对象
    const int fd_;
    //注册fd感兴趣的事件
    int events_;
    //poller返回的具体事件
    int revents_;
    int index_;

    std::weak_ptr<void> tie_;
    //是否绑定了tie
    bool tied_;
    //channel可以获知fd发生的具体事件，所以负责调用具体事件的回调函数
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;
};