#pragma once
#include<vector>
#include<string>
#include<algorithm>
class Buffer
{
    public:
    static const size_t kCheapPrepend = 8;// 8字节的预留空间
    static const size_t kInitialSize = 1024;// buffer初始大小

    explicit Buffer(size_t initialSize = kInitialSize)
        : buffer_(kCheapPrepend + initialSize),
          readIndex_(kCheapPrepend),
          writeIndex_(kCheapPrepend)
    {}
    //从fd中读取数据
    ssize_t readFd(int fd, int* saveErrno);
    ssize_t writeFd(int fd, int* saveErrno);

    void append(const char* data, size_t len)
    {
        ensureWritableBytes(len);
        std::copy(data, data + len, beginWrite() + writeIndex_);
        writeIndex_ += len;
    }
    char* beginWrite()
    {
        return begin() + writeIndex_;
    }
    const char* beginWrite() const
    {
        return begin() + writeIndex_;
    }


    size_t readableBytes() const
    {
        return writeIndex_ - readIndex_;
    }

    size_t writableBytes() const
    {
        return buffer_.size() - writeIndex_;
    }
    size_t prependableBytes() const
    {
        return readIndex_;
    }

    const char* peek() const
    {
        return begin() + readIndex_;
    }
    void retrieve(size_t len)
    {
        if (len < readableBytes())
        {
            readIndex_ += len;
        }
        else
        {
           retrieveAll();
        }
    }

    void retrieveAll()
    {
        readIndex_ = kCheapPrepend;
        writeIndex_ = kCheapPrepend;
    }
    std::string retrieveAllAsString()
    {
        return retrieveAsString(readableBytes());
    }

    std::string retrieveAsString(size_t len)
    {
        std::string result(peek(), len);
        retrieve(len);
        return result;
    }
    void ensureWritableBytes(size_t len)
    {
        if (writableBytes() < len)
        {
            makeSpace(len);
        }
    }
    private:
    char* begin() { return &*buffer_.begin(); }
    const char* begin() const { return &*buffer_.begin(); }
    void makeSpace(size_t len)
    {
        if (writableBytes() + prependableBytes() < len + kCheapPrepend)
        {
            buffer_.resize(writeIndex_ + len);
        }
        else
        {
            size_t readable = readableBytes();
            std::copy(begin() + readIndex_,
                      begin() + writeIndex_,
                      begin() + kCheapPrepend);
            readIndex_ = kCheapPrepend;
            writeIndex_ = readIndex_ + readable;
        }
    }


    std::vector<char> buffer_;
    size_t readIndex_;
    size_t writeIndex_;
};