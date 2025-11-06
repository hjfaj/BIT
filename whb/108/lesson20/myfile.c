#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    //printf("hello Linux");
    //close(1);

    //return 0;
    const char *fstr = "hello fwrite\n";
    const char *str = "hello write\n";

    // C
    printf("hello printf\n"); // stdout -> 1
    sleep(2);
    fprintf(stdout, "hello fprintf\n"); // stdout -> 1
    sleep(2);
    fwrite(fstr, strlen(fstr), 1, stdout); // fread, stdout->1
    sleep(2);

    // 操作提供的systemcall
    write(1, str, strlen(str)); // 1

    sleep(5);
    //close(1); // ?
    fork();
    return 0;
}
