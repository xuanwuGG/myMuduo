#include"Buffer.h"

#include<errno.h>
#include<sys/uio.h>
#include<unistd.h>

ssize_t Buffer::readFd(int fd, int* saveErrno)
{
    char extraBuf[65536]= {0};
    struct iovec vec[2];
    const size_t writable = writableBytes();
    vec[0].iov_base = begin() + writeIndex_;
    vec[0].iov_len = writable;

    vec[1].iov_base = extraBuf;
    vec[1].iov_len = sizeof(extraBuf);
    const int iovcnt = (writable < sizeof(extraBuf)) ? 2 : 1;
    const ssize_t n = readv(fd, vec, iovcnt);
    if (n < 0)
    {
        *saveErrno = errno;
    }
    else if (static_cast<size_t>(n) <= writable)
    {
        writeIndex_ += n;
    }
    else
    {
        writeIndex_ = buffer_.size();
        append(extraBuf, n - writable);
    }
    return n;
}

ssize_t Buffer::writeFd(int fd, int* saveErrno)
{
    ssize_t n = ::write(fd, peek(), readableBytes());
    if (n < 0)
    {
        *saveErrno = errno;
    }
    return n;
}