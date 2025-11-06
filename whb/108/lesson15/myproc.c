#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    printf("you can see me!");
    sleep(1);

    _exit(11);
}


//void show()
//{
//    printf("hello show!\n");
//    printf("hello show!\n");
//    printf("hello show!\n");
//    printf("hello show!\n");
//    printf("hello show!\n");
//    printf("hello show!\n");
//    //return;
//    //exit(13); // 在任意地方被调用，都表示调用进程直接退出 return 只表示当前函数返回
//    _exit(14);
//    printf("end show \n");
//    printf("end show \n");
//    printf("end show \n");
//    printf("end show \n");
//}
//
//int main()
//{
//    show();
//    printf("hello Linux\n");
//
//    //exit(12);
//    return 12;
// //   while(1)
// //   {
// //       printf("hello Linux!: pid:%d\n", getpid());
// //       sleep(1);
// //   }
//    //int a = 10;
//    //a /= 0;
//  //  char *p = NULL;
//  //  *p = 100;
//  //  //int ret = 0;
//    //char *p = (char*)malloc(1000*1000*1000*4);
//    //if(p == NULL)
//    //{
//    //    printf("malloc error, %d: %s\n", errno, strerror(errno));
//    //    ret = errno;
//    //}
//    //else{
//    //    // 使用申请的内存
//    //    printf("malloc success\n");
//    //}
//
//    //return ret;
//}
//
////const char *errString[] = {
////    "success",
////    "error 1",
////    "error 2",
////    "error 3",
////    "error 4",
////    "error 5"
////};
////
////int main()
////{
////
////   // printf("模拟一个逻辑的实现\n");
////    for(int i = 0 ; i < 200; i++)
////    {
////        printf("%d: %s\n", i, strerror(i));
////    }
////    return 0; // 进程的退出码，表征进程的运行结果是否正确. 0->success
////}
////
//////#define N 5
//////
//////void runChild()
//////{
//////    int cnt = 10;
//////    while(cnt)
//////    {
//////        printf("I am child: %d, ppid:%d\n", getpid(), getppid());
//////        sleep(1);
//////        cnt--;
//////    }
//////}
//////
//////int main()
//////{
//////    for(int i = 0; i < N; i++)
//////    {
//////        pid_t id = fork();
//////        if(id == 0)
//////        {
//////            runChild();
//////            exit(0);
//////        }
//////    }
//////
//////    sleep(1000);
//////
//////    return 0; // 为什么main函数总是会返回return 0? 1? 2?, 这个东西给谁了？为什么要返回这个值？
//////    //printf("pid: %d before!\n", getpid());
//////    //fork();
//////    //printf("pid: %d after!\n", getpid());
//////}
