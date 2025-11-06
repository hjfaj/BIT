#include <iostream>
#include <unistd.h>
#include <signal.h>

using namespace std;

void PrintPending(sigset_t &pending)
{
    for (int signo = 31; signo >= 1; signo--)
    {
        if (sigismember(&pending, signo))
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n\n";
}

void handler(int signo)
{
    cout << "catch a signo: " << signo << endl;
}

int main()
{
    // 4. 我可以将所有的信号都进行屏蔽，信号不就不会被处理了吗？ 肯定的！9
    sigset_t bset, oset;
    sigemptyset(&bset);
    sigemptyset(&oset);
    for (int i = 1; i <= 31; i++)
    {
        sigaddset(&bset, i); // 屏蔽了所有信号吗？？？
    }
    sigprocmask(SIG_SETMASK, &bset, &oset);

    sigset_t pending;
    while (true)
    {
        // 2.1 获取
        int n = sigpending(&pending);
        if (n < 0)
            continue;
        // 2.2 打印
        PrintPending(pending);
        sleep(1);
    }

    // // 0. 对2号信号进行自定义捕捉
    // signal(2, handler);

    // // 1. 先对2号信号进行屏蔽 --- 数据预备
    // sigset_t bset, oset; // 在哪里开辟的空间？？？用户栈上的，属于用户区
    // sigemptyset(&bset);
    // sigemptyset(&oset);
    // sigaddset(&bset, 2); // 我们已经把2好信号屏蔽了吗？并没有设置进入到你的进程的task_struct
    // // 1.2 调用系统调用，将数据设置进内核
    // sigprocmask(SIG_SETMASK, &bset, &oset); // 我们已经把2好信号屏蔽了吗？ok

    // // 2. 重复打印当前进程的pending 0000000000000000000000000
    // sigset_t pending;
    // int cnt = 0;
    // while (true)
    // {
    //     // 2.1 获取
    //     int n = sigpending(&pending);
    //     if (n < 0)
    //         continue;
    //     // 2.2 打印
    //     PrintPending(pending);

    //     sleep(1);
    //     cnt++;
    //     // 2.3 解除阻塞
    //     if(cnt == 20)
    //     {
    //         cout << "unblock 2 signo" << endl;
    //         sigprocmask(SIG_SETMASK, &oset, nullptr); // 我们已经把2好信号屏蔽了吗？ok
    //     }
    // }
    // // 3 发送2号 0000000000000000000000010

    return 0;
}