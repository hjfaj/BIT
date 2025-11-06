#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

using namespace std;

void Usage(string proc)
{
    cout << "Usage:\n\t" << proc << " signum pid\n\n";
}

void myhandler(int signo)
{
    cout << "process get a signal: " << signo <<endl;
    // exit(1);
}

// mykill signum pid
int main(int argc, char *argv[])
{
    // signal(2, myhandler);
    
    signal(SIGABRT, myhandler);
    int cnt = 0;
    while (true)
    {
        cout << "I am a process, pid: " << getpid() << endl;
        sleep(1);
        cnt++;
        if(cnt % 2 == 0) 
        {
            //kill(getpid(), 2);
            //raise(2);
            //abort();
            // kill(getpid(), 6);
        }
    }

    // if(argc != 3)
    // {
    //     Usage(argv[0]);
    //     exit(1);
    // }
    // int signum = stoi(argv[1]);
    // pid_t pid = stoi(argv[2]);

    // int n = kill(pid, signum);
    // if(n == -1)
    // {
    //     perror("kill");
    //     exit(2);
    // }

    return 0;
}

// // int: 收到了哪一个信号
// void myhandler(int signo)
// {
//     cout << "process get a signal: " << signo <<endl;
//     // exit(1);
// }

// int main()
// {
//     // signal(SIGINT, myhandler); // 只需要设置一次，往后都有效！
//     // signal(3, myhandler);
//     // signal(19, myhandler);
//     // 信号的产生和我们自己的代码的运行时异步的

//     // for(int i = 1; i <= 31; i++)
//     // {
//     //     signal(i, myhandler);
//     // }

//     // while(true)
//     // {
//     //     cout << "I am a crazy process : " << getpid() << endl;
//     //     sleep(1);
//     // }
// }