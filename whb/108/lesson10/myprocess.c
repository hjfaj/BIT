#include <stdio.h>
#include <unistd.h>

int main()
{
    fopen("log.txt", "w");
    while(1)
    {
        printf("我是一个进程啦...\n");
        sleep(1);
    }
    return 0;
}
