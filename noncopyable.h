#pragma once
/*
*noncopyable被继承的派生类可以支持构造和析构，但是不能拷贝构造和赋值
*/
class noncopyable
{
    public:
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
    protected:
        noncopyable() = default;
        ~noncopyable() = default;    
};