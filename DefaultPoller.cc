#include "Poller.h"

#include<stdlib.h>

static Poller* newDefaultPoller(EventLoop* loop){
    if(::getenv("MUDUO_USE_POLL")){
        return nullptr; // TODO:生成poll示例
    }else{
        return nullptr; // TODO:生成epoll示例
    }
}
