#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>

using namespace std;

void *threadRun(void *arg)
{
    while (true)
    {
        std::cout << "hello world" << std::endl;
        sleep(1);
    }
}

int main()
{
    pthread_t tid;
    pthread_create()
    return 0;
}