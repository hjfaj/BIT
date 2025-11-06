#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    while(1){
        printf("I am a process, pid: %d\n", getpid());
        sleep(1);
    }

//    pid_t id = fork();
//    if(id == 0)
//    {
//        //child
//        int cnt = 500;
//        while(cnt)
//        {
//            printf("i am child, pid: %d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt);
//            cnt--;
//            sleep(1);
//        }
//        exit(0);
//    }
//    else
//    {
//        int cnt = 5;
//        //father
//        while(cnt--)
//        {
//            printf("i am father, pid: %d, ppid: %d\n", getpid(), getppid());
//            sleep(1);
//        }
//
//        //父进程目前并没有针对子进程干任何事事情
//    }
//








    //int a = 0;
    //printf("Enter# ");
    //scanf("%d", &a);

    //printf("echo : %d\n", a);
    //while(1)
    //{
    //    sleep(1);
    //    printf("hello bit\n");
    //}
    //{
    //    printf("hello bit\n");
    //}

    return 0;
}
