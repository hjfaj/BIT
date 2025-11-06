#include <iostream>
#include <unistd.h>
#include <pthread.h>

int cnt = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *Count(void * args)
{
    pthread_detach(pthread_self());
    uint64_t number = (uint64_t)args;
    std::cout << "pthread: " << number << " create success" << std::endl;

    while(true)
    {
        pthread_mutex_lock(&mutex);
        // 我们怎么知道我们要让一个线程去休眠了那？一定是临界资源不就绪，没错，临界资源也是有状态的！！
        // 你怎么知道临界资源是就绪还是不就绪的？你判断出来的！判断是访问临界资源吗？必须是的，也就是判断必须在加锁之后！！！
        pthread_cond_wait(&cond, &mutex);               //？ 为什么在这里？ 1. pthread_cond_wait让线程等待的时候，会自动释放锁！
        // 不管临界资源的状态情况
        std::cout << "pthread: " << number << " ， cnt: " << cnt++ << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    for(uint64_t i = 0; i < 5; i++)
    {
        pthread_t tid;
        pthread_create(&tid, nullptr, Count, (void*)i);
        usleep(1000);
    }
    sleep(3);
    std::cout << "main thread ctrl begin: " << std::endl;

    while(true) 
    {
        sleep(1);
        // pthread_cond_signal(&cond); //唤醒在cond的等待队列中等待的一个线程，默认都是第一个
        pthread_cond_broadcast(&cond);
        std::cout << "signal one thread..." << std::endl;
    }

    return 0;
}



// void *getTicket(void *args)
// {
//     threadData *td = static_cast<threadData *>(args);
//     const char *name = td->threadname.c_str();
//     while (true)
//     {
//         // 线程对于锁的竞争能力可能会不同 --- 一会由例子
//         // pthread_mutex_lock(td->lock); // 申请锁成功，才能往后执行，不成功，阻塞等待。
//         pthread_mutex_lock(&lock); // 申请锁成功，才能往后执行，不成功，阻塞等待。
//         if(tickets > 0)
//         {
//             usleep(1000);
//             printf("who=%s, get a ticket: %d\n", name, tickets); // ?
//             tickets--;
//             pthread_mutex_unlock(td->lock);
//             // pthread_mutex_unlock(&lock);
//         }
//         else{
//             pthread_mutex_unlock(td->lock);
//             // pthread_mutex_unlock(&lock);
//             // wait
//         }
//         usleep(13); // 我们抢到了票，我们会立马抢下一张吗？其实多线程还要执行得到票之后的后续动作。usleep模拟
//     }
//     printf("%s ... quit\n", name);
//     return nullptr;
// }
