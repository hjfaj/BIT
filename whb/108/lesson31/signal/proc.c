#include <stdio.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        printf("I am a process, pid: %d\n", getpid());
        sleep(1);
    }
}
