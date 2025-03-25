#pragma once 
#include<functional>
#include<atomic>
#include<memory>
#include<mutex>

#include "noncopyable.h"
#include "TimeStamp.h"
#include "CurrentThread.h"

class Channel;
class Poller;


//事件循环类 包含Channel Poller（epoll抽象）
class EventLoop:noncopyable
{
public: 
    using Functor = std::function<void()>;


    EventLoop();
    ~EventLoop();
    //开启事件循环
    void loop();
    void quit();

    TimeStamp pollReturnTime() const { return pollReturnTime_; }
    //在当前loop中执行cb
    void runInLoop(Functor cb);
    
    //将cb放入队列中，唤醒loop所在线程
    void queueInLoop(Functor cb);
    
    //mainloop唤醒subloop
    void wakeup();


    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);
    //判断当前线程是否是loop所在线程
    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }
private:
    void handleRead(); 
    void doPendingFunctors(); 
    using ChannelList = std::vector<Channel*>;
    std::atomic<bool> looping_; //原子操作,cas实现
    std::atomic<bool> quit_; //标志是否退出
    std::atomic<bool> callingPendingFunctors_; //是否正在执行回调函数
    const pid_t threadId_; //记录当前loop线程id 
    TimeStamp pollReturnTime_; //记录poll返回时间
    std::unique_ptr<Poller> poller_; 

    int wakeupFd_; //主要当mainloop获取到一个新的channel时，通过轮询算法选择一个subloop
    std::unique_ptr<Channel> wakeupChannel_; 
    ChannelList activeChannels_; //记录当前活跃的channel
    Channel* currentActiveChannel_; //当前正在处理的channel

    std::atomic<bool>  callingPendingFunctors_; //是否正在执行回调函数
    std::vector<Functor> pendingFunctors_; //回调函数队列
    std::mutex mutex_; //互斥锁
};