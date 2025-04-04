#include "TcpServer.h"
#include "Logger.h"

#include<functional>
static EventLoop *CheckLoopNotNull(EventLoop *loop)
{
    if (loop == nullptr)
    {
        LOG_FATAL("%s:%s:%d mainLoop is null\n",
                  __FILE__,
                  __FUNCTION__,
                  __LINE__);
    }
    return loop;
}
TcpServer::TcpServer(EventLoop *loop,
                     const InetAddress &listenAddr,
                     const std::string &nameArg,
                     Option option)
    : loop_(CheckLoopNotNull(loop)),
      inPort_(listenAddr.toIpPort()),
      name_(nameArg),
      acceptor_(new Acceptor(loop, listenAddr, option == kReusePort)),
      threadPool_(new EventLoopThreadPool(loop, name_)),
      connectionCallback_(),
      messageCallback_(),
      nextConnId_(1)
{
    //有新用户连接时，执行newConnection
    acceptor_->setNewConnectionCallback(
        std::bind(&TcpServer::newConnection, this, std::placeholders::_1, std::placeholders::_2));
}

void TcpServer::setThreadNum(int numThreads)
{
    threadPool_->setThreadNum(numThreads);
}

void TcpServer::start()
{
    if(started_ == false)
    {
        started_ = true;
        threadPool_->start(threadInitCallback_);// 启动线程池
        loop_->runInLoop(std::bind(&Acceptor::listen, acceptor_.get()));//

    }
}


