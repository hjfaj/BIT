#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>

template <class T>
class BlockQueue
{
    static const int defalutnum = 20;
public:
    BlockQueue(int maxcap = defalutnum):maxcap_(maxcap)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&c_cond_, nullptr);
        pthread_cond_init(&p_cond_, nullptr);
        // low_water_ = maxcap_/3;
        // high_water_ = (maxcap_*2)/3;
    }

    // 谁来唤醒呢？
    T pop()
    {
        pthread_mutex_lock(&mutex_);
        while(q_.size() == 0) // 因为判断临界资源调试是否满足，也是在访问临界资源！判断资源是否就绪，是通过再临界资源内部判断的。
        {
            // 如果线程wait时，被误唤醒了呢？？
            pthread_cond_wait(&c_cond_, &mutex_); // 你是持有锁的！！1. 调用的时候，自动释放锁，因为唤醒而返回的时候，重新持有锁
        }
        
        T out = q_.front(); // 你想消费，就直接能消费吗？不一定。你得先确保消费条件满足
        q_.pop();

        // if(q_.size()<low_water_) pthread_cond_signal(&p_cond_);
        pthread_cond_signal(&p_cond_); // pthread_cond_broadcast
        pthread_mutex_unlock(&mutex_);

        return out;
    }

    void push(const T &in)
    {
        pthread_mutex_lock(&mutex_);
        while(q_.size() == maxcap_){ // 做到防止线程被伪唤醒的情况
            // 伪唤醒情况
            pthread_cond_wait(&p_cond_, &mutex_); //1. 调用的时候，自动释放锁 2.？
        }
        // 1. 队列没满 2.被唤醒 
        q_.push(in);                    // 你想生产，就直接能生产吗？不一定。你得先确保生产条件满足
        // if(q_.size() > high_water_) pthread_cond_signal(&c_cond_);
        pthread_cond_signal(&c_cond_);
        pthread_mutex_unlock(&mutex_);
    }

    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&c_cond_);
        pthread_cond_destroy(&p_cond_);
    }
private:
    std::queue<T> q_; // 共享资源, q被当做整体使用的，q只有一份，加锁。但是共享资源也可以被看做多份！
    //int mincap_;
    int maxcap_;      // 极值
    pthread_mutex_t mutex_;
    pthread_cond_t c_cond_;
    pthread_cond_t p_cond_;

    // int low_water_;
    // int high_water_;
};