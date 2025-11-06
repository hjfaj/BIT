#include <stdio.h>

void Print3()
{
    printf("hello printf1\n");
}
void Print2()
{
    printf("hello printf1\n");
    Print3();
}
void Print1()
{
    printf("hello printf1\n");
    Print2();
}

int addToTop(int top)
{
    int res = 0;
    int i = 1;
    for(; i <= top; i++)
    {
        res += i;
    }
    Print1();
    return res;
}

int main()
{
    printf("debug begin\n");

    int top = 100;
    int sum = addToTop(top);

    printf("sum: %d\n", sum);

    printf("debug end\n");
    return 0;
}
