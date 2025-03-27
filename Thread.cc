#include "Thread.h"
#include "CurrentThread.h"

#include<semaphore.h>

std::atomic_int Thread::numCreated_ = 0;
Thread::Thread(ThreadFunc func, const std::string &name)
    : started_(false),
      joined_(false),
      tid_(0),
      func_(std::move(func)),
        name_(name)
{
    setDefalutName();
}

Thread::~Thread()
{
    if(started_ && !joined_)
    {
        thread_->detach();
    }
}
//启动线程
void Thread::start()
{
    started_ = true;
    sem_t sem;;
    sem_init(&sem, 0, 0);
    thread_ = std::make_shared<std::thread>(new std::thread([&](){
        tid_ = CurrentThread::tid();
        sem_post(&sem);
        func_(); //开启新线程，专门执行func_函数
    }));
    sem_wait(&sem); //需要等待新线程运行后，才能继续执行
}

void Thread::join()
{
    joined_ = true;
    thread_->join();
}

bool Thread::started() const
{
}

void Thread::setDefalutName()
{
    int num = numCreated_++;

}