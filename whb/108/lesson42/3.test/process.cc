#include <iostream>
#include <string>
#include <unistd.h>

int main()
{
    while(true)
    {
        std::cout << "hello ...." << std::endl;
        sleep(1);
    }
    return 0;
}