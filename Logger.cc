#include<iostream>

#include "Logger.h"
#include "TimeStamp.h"

void Logger::setLogLevel(int level){
    logLevel_ = level;
}

//写日志 [级别信息] time : msg
void Logger::log(std::string msg){
    switch (logLevel_)
    {
        case INFO:
            std::cout << "[INFO] ";
            break;
        case ERROR:
            std::cout << "[ERROR] ";
            break;
        case FATAL:
            std::cout << "[FATAL] ";
            break;
        case DEBUG:
            std::cout << "[DEBUG] ";
            break;
    }
    //获取当前时间,muduo库中有封装 
    std::cout<<TimeStamp::now().toString()<<" : "<<msg<<std::endl;
}