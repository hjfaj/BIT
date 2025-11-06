#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//
//int main()
//{
//    char *str = "hello bit";
//    *str = 'H';
//    return 0;
//}


//int g_val = 100;
//
//int main()
//{
//    pid_t id = fork();
//    if(id == 0)
//    {
//        int cnt = 5;
//        // 子进程
//        while(1)
//        {
//            printf("i am child, pid : %d, ppid : %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//            sleep(1);
//            if(cnt) cnt--;
//            else {
//                g_val=200;
//                printf("子进程change g_val : 100->200\n");
//                cnt--;
//            }
//        }
//    }
//    else
//    {
//        // 父进程
//        while(1)
//        {
//            printf("i am parent, pid : %d, ppid : %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//            sleep(1);
//        }
//    }
//}
//
int g_val_1;
int g_val_2 = 100;
////
int main(int argc, char *argv[], char *env[])
{
    printf("code addr: %p\n", main);
    const char *str = "hello bit";
    printf("read only string addr: %p\n", str);
    printf("init global value addr: %p\n", &g_val_2);
    printf("uninit global value addr: %p\n", &g_val_1);
    char *mem = (char*)malloc(100);
    char *mem1 = (char*)malloc(100);
    char *mem2 = (char*)malloc(100);
    printf("heap addr: %p\n", mem);
    printf("heap addr: %p\n", mem1);
    printf("heap addr: %p\n", mem2);
    printf("stack addr: %p\n", &str);
    printf("stack addr: %p\n", &mem);
    static int a = 0;
    int b;
    int c;
    printf("a = stack addr: %p\n", &a);
    printf("stack addr: %p\n", &b);
    printf("stack addr: %p\n", &c);
    int i = 0;
    for(; argv[i]; i++)
        printf("argv[%d]: %p\n", i, argv[i]);

    for(i=0; env[i]; i++)
        printf("env[%d]: %p\n", i, env[i]);

//    char *str = "hello bit";
//    *str = 'H';
//
//    printf("xxx=%s\n", getenv("xxx"));
    return 0;
}
