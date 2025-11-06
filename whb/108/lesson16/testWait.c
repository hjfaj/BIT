#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 10

//void RunChild()
//{
//    int cnt = 5;
//    while(cnt)
//    {
//        printf("I am Child Process, pid: %d, ppid:%d\n", getpid(), getppid());
//        sleep(1);
//        cnt--;
//    }
//}


#define TASK_NUM 10

typedef void(*task_t)();
task_t tasks[TASK_NUM];

void task1()
{
    printf("这是一个执行打印日志的任务, pid: %d\n", getpid());
}

void task2()
{
    printf("这是一个执行检测网络健康状态的一个任务, pid: %d\n", getpid());
}

void task3()
{
    printf("这是一个进行绘制图形界面的任务, pid: %d\n", getpid());
}

int AddTask(task_t t);

// 任务的管理代码
void InitTask()
{
    for(int i = 0; i < TASK_NUM; i++) tasks[i] = NULL;
    AddTask(task1);
    AddTask(task2);
    AddTask(task3);
}

int AddTask(task_t t)
{
    int pos = 0;
    for(; pos < TASK_NUM; pos++) {
        if(!tasks[pos]) break;
    }
    if(pos == TASK_NUM) return -1;
    tasks[pos] = t;
    return 0;
}

void DelTask()
{}

void CheckTask()
{}

void UpdateTask()
{}

void ExecuteTask()
{
    for(int i = 0; i < TASK_NUM; i++)
    {
        if(!tasks[i]) continue;
        tasks[i]();
    }
}


int main()
{
//    //wait / waitpid
//    for(int i = 0; i < N; i++)
//    {
//        pid_t id = fork();
//        if(id == 0)
//        {
//            RunChild();
//            exit(i);
//        }
//        printf("create child process: %d success\n", id); // 这句话只有父进程才会执行
//    }
//
//    //sleep(10);
//
//    // 等待
//    for(int i = 0; i < N; i++)
//    {
//        // wait当任意一个子进程退出的时候，wait回收子进程
//        // 如果任意一个子进程都不退出呢？
//        //pid_t id = wait(NULL);
//        int status = 0;
//        pid_t id = waitpid(-1, &status, 0);
//        if(id > 0)
//        {
//            printf("wait %d success, exit code: %d\n", id, WEXITSTATUS(status));
//        }
//    }
//
//    sleep(5);

    pid_t id = fork();
    if(id < 0) {
        perror("fork");
        return 1;
    }
    else if(id == 0)
    {
        //int *p = NULL;
        // child
        int cnt = 5;
        while(cnt)
        {
            printf("I am child, pid:%d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
            cnt--;
            sleep(1);
            //*p = 100;
        }
        exit(11);
    }
    else
    {
        // parent
       // int cnt = 5;
       // while(cnt)
       // {
       //     printf("I am father, pid:%d, ppid:%d, cnt: %d\n", getpid(), getppid(), cnt);
       //     cnt--;
       //     sleep(1);
       // }
        // 目前为止，进程等待是必须的！
        // wait是等待任意一个子进程退出
        int status = 0;
        InitTask();
//        pid_t ret = wait(NULL);
        //pid_t ret = waitpid(id, &status, 0);
        while(1){ //轮询
            pid_t ret = waitpid(id, &status, WNOHANG); //非阻塞
            if(ret > 0)
            {
                // 7F: 0111 1111
                // printf("wait success, ret: %d, exit sig: %d, exit code: %d\n", ret, status&0x7F, (status>>8)&0xFF);
                if(WIFEXITED(status))
                {
                    printf("进程是正常跑完的, 退出码:%d\n", WEXITSTATUS(status));
                }
                else{
                    printf("进程出异常了\n");
                }
                break;
            }
            else if(ret < 0)
            {
                printf("wait failed!\n");
                break;
            }
            else
            {
                //ret == 0
                //printf("你好了没？子进程还没有退出，我在等等...\n");
                //sleep(1);
                ExecuteTask();
                usleep(500000);
            }
        }
    }

    return 12;
}


