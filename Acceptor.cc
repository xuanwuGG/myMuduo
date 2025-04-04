#include"Acceptor.h"
#include"Logger.h"
#include"InetAddress.h"

#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
static int createNonblocking(){
    int sockfd = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, IPPROTO_TCP);
    if (sockfd < 0){
        LOG_FATAL("%s:%d listen socket create error:%d\n", __FILE__, __LINE__, errno);
    }
    return sockfd;
}
Acceptor::Acceptor(EventLoop* loop, const InetAddress& listenAddr, bool reuseport)
    : loop_(loop),
        acceptSocket_(createNonblocking()),
        acceptChannel_(loop, acceptSocket_.fd()),
        listenning_(false)
        {
            acceptSocket_.setReuseAddr(true);
            acceptSocket_.setReusePort(true);
            acceptSocket_.bindAddress(listenAddr);
            acceptChannel_.setReadCallback(std::bind(&Acceptor::handleRead, this));
        }

Acceptor::~Acceptor(){
    acceptChannel_.disableAll();
    acceptChannel_.remove();
    ::close(acceptSocket_.fd());
}

void Acceptor::listen(){
    listenning_ = true;
    acceptSocket_.listen();
    acceptChannel_.enableReading();
}



//listenfd有事件发生，于是有新用户连接
void Acceptor::handleRead(){
    InetAddress peerAddr;
    int connfd = acceptSocket_.accept(&peerAddr);
    if (connfd >= 0){
        if (newConnectionCallback_){
            newConnectionCallback_(connfd, peerAddr);
        } else {
            ::close(connfd);
        }
    } else {
        LOG_ERROR("%s:%d accept error:%d\n", __FILE__, __LINE__, errno);
        if (errno == EMFILE){
            LOG_ERROR("%s:%d socket file descriptor limit reached\n", __FILE__, __LINE__);
        }
    }
}
    