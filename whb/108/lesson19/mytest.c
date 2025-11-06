#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define filename "log.txt"

int main()
{
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");
    fprintf(stdout, "hello normal message\n");

    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");
    fprintf(stderr, "hello error message\n");



//    int fd = open(filename, O_CREAT|O_WRONLY|O_APPEND, 0666);
////    int fd = open(filename, O_RDONLY);
//    if(fd < 0)
//    {
//        perror("open");
//        return 1;
//    }
    //dup2(fd, 1);
    //close(fd);
    //printf("fd: %d\n", fd); // stdin->1
    //printf("hello printf!\n");
    //fprintf(stdout, "hello fprintf\n");
    //char inbuffer[1024];
    //ssize_t s = read(0, inbuffer, sizeof(inbuffer)-1);
    //if(s>0)
    //{
    //    inbuffer[s] = '\0';
    //    printf("echo# %s\n", inbuffer);
    //}

    // 重定向
    //dup2(fd, 1);
    //close(fd);
    //printf("fd: %d\n", fd);
    
   // const char *msg = "hello Linux\n";
   // int cnt = 5;
   // while(cnt)
   // {
   //     write(1, msg, strlen(msg));
   //     cnt--;
   // }
    return 0;
}
