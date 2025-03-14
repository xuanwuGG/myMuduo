#pragma once

#include<string>

#include "noncopyable.h"
//定义日志级别
enum LogLevel
{
    INFO,
    ERROR,
    FATAL,
    DEBUG,
};

class Logger : noncopyable{
    public:
    //获取日志唯一实例对象
    static Logger& instance();
    //设置日志级别
    void setLogLevel(int level);
    //写日志
    void log(std::string msg);
    
    
    private: 
    int logLevel_; //习惯手法 ，末尾添加下划线是为了和成员变量区分
    Logger(){

    }
};