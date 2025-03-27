#include "Poller.h"
#include "EpollPoller.h"
#include<stdlib.h>

static Poller* newDefaultPoller(EventLoop* loop){
    if(::getenv("MUDUO_USE_POLL")){
        return nullptr; // TODO:生成poll示例
    }else{
        return new EpollPoller(loop); // TODO:生成epoll示例
    }
}
