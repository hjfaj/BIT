#include <stdio.h>

#define M 100

int main()
{
#ifdef DEBUG
    printf("hello debug!\n");
#else 
    printf("hello release\n");
#endif

    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: aaa\n");
    printf("hello bit: bbb: %d\n", M);
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
   // printf("hello bit: \n");
    printf("hello bit: ccc\n");
    return 0;
}
