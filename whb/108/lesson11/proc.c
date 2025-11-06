#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("begin: 我是一个进程, pid: %d, ppid: %d\n", getpid(), getppid());

    sleep(5);
    pid_t id = fork();

    //printf("我是后续的代码\n");
    //sleep(1);
    if(id == 0)
    {
        // 子进程
        while(1)
        {
            printf("我是子进程, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else if(id > 0)
    {
        //父进程
        while(1)
        {
            printf("我是父进程，pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        //error
    }

    //pid_t id = getpid();
    //while(1)
    //{
    //    printf("I am a process, my id is: %d, parent:%d\n", getpid(), getppid());
    //    sleep(1);
    //}
    return 0;
}
