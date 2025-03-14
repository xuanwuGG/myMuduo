#pragma once 
#include<iostream>
#include<string>

class TimeStamp
{
public:
    TimeStamp();
    explicit TimeStamp(int64_t microSecondsSinceEpoch);
    static TimeStamp now(); //获取时间年月日
    std::string toString() const;
private:
    int64_t microSecondsSinceEpoch_;
};