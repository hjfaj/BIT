#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{
    // signal(2, SIG_IGN);
    signal(2, SIG_DFL);

    while(1)
    {
        cout << "hello signal" << endl;
        sleep(1);
    }

    // int a = 10;
    // int b = 0;

    // a /= b;


    // cout << " a = " << a << endl;

    // pid_t id = fork();
    // if(id == 0)
    // {
    //     //child
    //     int cnt = 500;
    //     while(cnt)
    //     {
    //         cout << "i am a child process, pid: " << getpid() << "cnt: " << cnt << endl;
    //         sleep(1);
    //         cnt--;
    //     }

    //     exit(0);
    // }

    // // father
    // int status = 0;
    // pid_t rid = waitpid(id, &status, 0);
    // if(rid == id)
    // {
    //     cout << "child quit info, rid: " << rid << " exit code: " << 
    //         ((status>>8)&0xFF) << " exit signal: " << (status&0x7F) <<
    //             " core dump: " << ((status>>7)&1) << endl; // ? & (0000 0000 ... 0001)
    // }
}






























// void work()
// {
//     cout << "print log..." << endl;
// }

// // 信号为什么会一直被触发？？
// void handler(int signo)
// {
//     // work();
//     cout << "...get a sig, number: " << signo <<endl; //我什么都没干，我只是打印了消息
//     // exit(1);
//     int n = alarm(5);
//     cout << "剩余时间：" << n << endl;
// }

// int main()
// {
//     signal(SIGALRM, handler);
//     int n = alarm(50);

//     while(1)
//     {
//         cout << "proc is running..., pid: " << getpid() << endl;
//         sleep(1);
//     }

//     // signal(SIGSEGV, handler);
//     // cout << "point error before" << endl;

//     // sleep(5);
//     // char buffer[1024];
//     // int n =1024;
//     // n = read(4, buffer, n);
//     // printf("n=%d\n", n);
//     // perror("read");
//     // // int *p = nullptr;
//     // // *p = 100;  // 野指针

//     // // int a = 10;
//     // // a /= 0; // 异常
//     // cout << "point error before" << endl;
//     sleep(1);

//     return 0;
// }