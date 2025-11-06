#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sys/unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <pthread.h>

int main()
{
    std::string s = "hello world";
    for(auto &a : s)
    {
        std::cout << "hello world: " << a << std::endl;
    }

    std::string s;
    std::vector<int> v;
    pthread_t tid;
    pthread_create(&tid, nullptr, start_run, "thread1");

    
    
    return 0;
}