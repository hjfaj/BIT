#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

// 必须得等待吗？？？必须得调用 wait吗？？
// void handler(int signo)
// {
//     sleep(5);
//     pid_t rid;
//     while ((rid = waitpid(-1, nullptr, WNOHANG)) > 0)
//     {
//         cout << "I am proccess: " << getpid() << " catch a signo: " << signo << "child process quit: " << rid << endl;
//     }
// }

int main()
{
    signal(17, SIG_IGN); // SIG_DFL -> action -> IGN

    // srand(time(nullptr));
    // signal(17, handler);
    // 如果我们有10个子进程呢？？如果同时退出呢？
    // 如果退出一半呢？
    for (int i = 0; i < 10; i++)
    {
        pid_t id = fork();
        if (id == 0)
        {
            while (true)
            {
                cout << "I am child process: " << getpid() << ", ppid: " << getppid() << endl;
                sleep(5);
                break;
            }
            cout << "child quit!!!" << endl;
            exit(0);
        }
        // sleep(rand()%5+3);
        sleep(1);
    }
    // father
    while (true)
    {
        cout << "I am father process: " << getpid() << endl;
        sleep(1);
    }

    return 0;
}

// volatile int flag = 0;

// void handler(int signo)
// {
//     cout << "catch a signal: " << signo << endl;
//     flag = 1;
// }

// int main()
// {
//     signal(2, handler);
//     // 在优化条件下， flag变量可能被直接优化到CPU内的寄存器中
//     while(!flag); // flag 0, !falg 真

//     cout << "process quit normal" << endl;
//     return 0;
// }

// 问题1： pending位图，什么时候从1->0. 执行信号捕捉方法之前，先清0，在调用
// 问题2： 信号被处理的时候，对应的信号也会被添加到block表中，防止信号捕捉被嵌套调用

// void PrintPending()
// {
//     sigset_t set;
//     sigpending(&set);

//     for (int signo = 1; signo <= 31; signo++)
//     {
//         if (sigismember(&set, signo))
//             cout << "1";
//         else
//             cout << "0";
//     }
//     cout << "\n";
// }

// void handler(int signo)
// {
//     cout << "catch a signal, signal number : " << signo << endl;
//     while (true)
//     {
//         PrintPending();
//         sleep(1);
//     }
// }

// int main()
// {
//     // struct sigaction act, oact;
//     // memset(&act, 0, sizeof(act));
//     // memset(&oact, 0, sizeof(oact));

//     // sigemptyset(&act.sa_mask);
//     // sigaddset(&act.sa_mask, 1);
//     // sigaddset(&act.sa_mask, 3);
//     // sigaddset(&act.sa_mask, 4);
//     // act.sa_handler = handler; // SIG_IGN SIG_DFL
//     // sigaction(2, &act, &oact);

//     // while (true)
//     // {
//     //     cout << "I am a process: " << getpid() << endl;
//     //     sleep(1);
//     // }

//     return 0;
// }