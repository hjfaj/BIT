#include "processBar.h"
#include <unistd.h>

int main()
{
    // 倒计时
    int cnt = 10;

    while(cnt>=0)
    {
        printf("%-2d\r", cnt);
        fflush(stdout);
        cnt--;
        sleep(1);
    }

    printf("\n");

   // printf("hello world"); // 1
   // fflush(stdout);
   // sleep(2);              // 2
    return 0;
}
