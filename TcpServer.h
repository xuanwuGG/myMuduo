#pragma once

#include"EventLoop.h"
#include"Acceptor.h"
#include"InetAddress.h"
#include"noncopyable.h"
#include"EventLoopThreadPool.h"
#include"Callbacks.h"

#include<atomic>
#include<map>
#include<functional>
class TcpServer : noncopyable
{
public:
    using ThreadInitCallback = std::function<void(EventLoop*)>;

    enum Option
    {
        kNoReusePort,
        kReusePort,
    };

    TcpServer(EventLoop* loop,
        const InetAddress& listenAddr,
        const std::string& nameArg,
        Option option = kNoReusePort);
    ~TcpServer();
    void setThreadInitCallback(const ThreadInitCallback& cb)
    {
        threadInitCallback_ = cb;
    }
    void setConnectionCallback(const ConnectionCallback& cb)
    {
        connectionCallback_ = cb;
    }
    void setMessageCallback(const MessageCallback& cb)
    {
        messageCallback_ = cb;
    }
    void setWriteCompleteCallback(const WriteCompleteCallback& cb)
    {
        writeCompleteCallback_ = cb;
    }
    //设置subloop个数
    void setThreadNum(int numThreads);
    
    void start();
private:
    void newConnection(int sockfd, const InetAddress& peerAddr);
    void removeConnection(const TcpConnectionPtr& conn);
    void removeConnectionInLoop(const TcpConnectionPtr& conn);

    using ConnectionMap = std::map<std::string, TcpConnectionPtr>;
    
    EventLoop* loop_;
    const std::string inPort_;
    const std::string name_;
    std::unique_ptr<Acceptor> acceptor_;// 监听器
    std::unique_ptr<EventLoopThreadPool> threadPool_;

    ConnectionCallback connectionCallback_;
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;

    ThreadInitCallback threadInitCallback_;
    std::atomic<bool> started_;
    int nextConnId_;
    ConnectionMap connections_; // 连接池

};