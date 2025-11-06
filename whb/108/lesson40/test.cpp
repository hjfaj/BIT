#include <iostream>
#include <unistd.h>

class Init{
public:
    Init()
    {
        std::cout << "hello world" << std::endl;
    }
};

Init t;
Init t1;
Init t2;
Init t3;
Init t4;
Init t5;
Init t6;
Init t7;

int main()
{
    sleep(3);
    sleep(3);

    return 0;
}