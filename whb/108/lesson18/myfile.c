#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    close(1);
    int n = printf("stdin->fd: %d\n", stdin->_fileno);
    printf("stdout->fd: %d\n", stdout->_fileno);
    printf("stderr->fd: %d\n", stderr->_fileno);


    fprintf(stderr, "printf ret: %d\n", n);

    //char buffer[1024];
    //ssize_t s = read(0, buffer, sizeof(buffer));
    //if(s < 0) return 1;
    //buffer[s] = '\0';
    //printf("echo : %s\n", buffer);

    //const char *msg = "hello Linux\n";
    //write(1, msg, strlen(msg));
    //write(2, msg, strlen(msg));

   // umask(0); // file descriptor: 文件描述符, fd , int
   // // int fd = open("log.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
   // int fd1 = open("log1.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
   // int fd2 = open("log2.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
   // int fd3 = open("log3.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
   // int fd4 = open("log4.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
   // if(fd1 < 0)
   // {
   //     printf("open file error\n");
   //     return 1;
   // }
   // printf("fd1: %d\n", fd1);
   // printf("fd2: %d\n", fd2);
   // printf("fd3: %d\n", fd3);
   // printf("fd4: %d\n", fd4);
    //const char *message = "xxx";
    ///write(fd, message, strlen(message)); // +1?

    ///close(fd);
    return 0;
}



//#define ONE (1<<0) // 1
//#define TWO (1<<1) // 2
//#define THREE (1<<2) // 4
//#define FOUR (1<<3) // 8
//
//void show(int flags)
//{
//    if(flags&ONE) printf("hello function1\n");
//    if(flags&TWO) printf("hello function2\n");
//    if(flags&THREE) printf("hello function3\n");
//    if(flags&FOUR) printf("hello function4\n");
//}
//
//
//
//int main()
//{
//    printf("-----------------------------\n");
//    show(ONE);
//    printf("-----------------------------\n");
//    show(TWO);
//    printf("-----------------------------\n");
//
//    show(ONE|TWO);
//    printf("-----------------------------\n");
//    show(ONE|TWO|THREE);
//    printf("-----------------------------\n");
//    show(ONE|THREE);
//    printf("-----------------------------\n");
//    show(THREE|FOUR);
//    printf("-----------------------------\n");
//}
//


//int main()
//{
//    //chdir("/home/whb");
//    printf("Pid: %d\n", getpid());
//    // 打开文件的路径和文件名，默认在当前路径下新建一个文件？
//    FILE *fp = fopen("log.txt", "a");
//    if(fp == NULL){
//        perror("fopen");
//        return 1;
//    }
//
//    const char *message = "abcd";
//    // strlen(message) ? 为什么? 字符串以\0结尾，是你C语言的规定，和我文件有什么关系？
//    //fwrite(message, strlen(message), 1, stdout);
//    //fprintf(stdout, "%s: %d\n", message, 1234);
//    fprintf(stderr, "%s: %d\n", message, 1234);
//    fclose(fp);
//
//    //sleep(1000);
//    return 0;
//}
