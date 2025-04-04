#include"TcpConnection.h"
#include"Logger.h"
#include"Channel.h"
#include"Socket.h"
#include"EventLoop.h"

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

TcpConnection::TcpConnection(EventLoop *loop,
                               const std::string &nameArg,
                               int sockfd,
                               const InetAddress &localAddr,
                               const InetAddress &peerAddr)
    : loop_(CheckLoopNotNull(loop)),
      name_(nameArg),
      state_(kConnecting),
      socket_(new Socket(sockfd)),
      channel_(new Channel(loop, sockfd)),
      localAddr_(localAddr),
      peerAddr_(peerAddr),
      highWaterMark_(64 * 1024 * 1024) // 64MB
{
    channel_->setReadCallback(
        std::bind(&TcpConnection::handleRead, this, std::placeholders::_1));
    channel_->setWriteCallback(
        std::bind(&TcpConnection::handleWrite, this));
    channel_->setCloseCallback(
        std::bind(&TcpConnection::handleClose, this));
    channel_->setErrorCallback(
        std::bind(&TcpConnection::handleError, this));
        LOG_INFO("TcpConnection::ctor[%s] at fd=%d\n",
              name_.c_str(),
              sockfd);
    }
TcpConnection::~TcpConnection()
{
    LOG_INFO("TcpConnection::dtor[%s] at fd=%d\n",
              name_.c_str(),
              channel_->fd());
}

void TcpConnection::handleRead(TimeStamp receiveTime)
{
    int savedErrno = 0;
    ssize_t n = inputBuffer_.readFd(channel_->fd(), &savedErrno);
    if (n > 0)
    {
        messageCallback_(shared_from_this(), &inputBuffer_, receiveTime);
    }
    else if (n == 0)
    {
        handleClose();
    }
    else
    {
        errno = savedErrno;
        LOG_ERROR("TcpConnection::handleRead ");
        handleError();
    }
}

void TcpConnection::handleWrite()
{
    if (channel_->isWriting()){
        int savedErrno = 0;
        ssize_t n = outputBuffer_.writeFd(channel_->fd(), &savedErrno);
        if (n > 0)
        {
            outputBuffer_.retrieve(n);
            if (outputBuffer_.readableBytes() == 0)
            {
                channel_->disableWriting();
                if (writeCompleteCallback_)
                {
                    loop_->queueInLoop(
                        std::bind(writeCompleteCallback_, shared_from_this()));
                }
            }
        }
        else
        {
            LOG_ERROR("TcpConnection::handleWrite ");
        }
    }
    else
    {
        LOG_ERROR("TcpConnection fd=%d is down, no more writing\n",
                  channel_->fd());
    }
}

void TcpConnection::handleClose()
{
    LOG_INFO("TcpConnection::handleClose fd=%d state=%d\n",
              channel_->fd(),
              static_cast<int>(state_));
    setState(TcpConnection::kDisconnected);
    channel_->disableAll();
    TcpConnectionPtr guardThis(shared_from_this());
    closeCallback_(guardThis);
}

void TcpConnection::handleError()
{
    int optval;
    socklen_t optlen = sizeof(optval);
    int err = 0;
    if (getsockopt(channel_->fd(), SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0)
    {
        err = errno;
    }
    else
    {
        err = optval;
    }
    LOG_ERROR("TcpConnection::handleError name=%s - SO_ERROR=%d\n",
              name_.c_str(),
              err);

}