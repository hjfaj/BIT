#include <iostream>
#include <pthread.h>
#include <unistd.h>

void *threadRun(void* args)
{
    while(1)
    {
        std::cout << "new thread: " << getpid() << std::endl;
        sleep(1);
    }
    return nullptr;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, nullptr, threadRun, nullptr);


    while(1)
    {
        std::cout << "main thread: " << getpid() << std::endl;
        sleep(1);
    }
}
