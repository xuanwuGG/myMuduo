#include<iostream>

#include "Logger.h"
#include "TimeStamp.h"
//LOG_INFO("%s %d", arg1, arg2) 
#define LOG_INFO(logmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf); \
    } while(0)

#define LOG_ERROR(logmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf); \
    } while(0)

#define LOG_FATAL(logmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf); \
    } while(0)

#ifdef MUDEBUG
#define LOG_DEBUG(logmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(DEBUG); \
        char buf[1024] = {0}; \
        snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__); \
            logger.log(buf); \
    } while(0)

Logger& Logger::instance(){
    static Logger logger;
    return logger;
}
#else
#define LOG_DEBUG(logmsgFormat, ...)
#endif

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