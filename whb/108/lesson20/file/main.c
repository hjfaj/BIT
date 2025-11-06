#include "Mystdio.h"
#include <unistd.h>

#define myfile "test.txt"

int main()
{
    _FILE *fp = _fopen(myfile, "a");
    if(fp == NULL) return 1;

    const char *msg = "hello world\n";
    int cnt = 10;
    while(cnt){
        _fwrite(fp, msg, strlen(msg));
        // fflush(fp);
        sleep(1);
        cnt--;
    }

    _fclose(fp);

    return 0;
}
