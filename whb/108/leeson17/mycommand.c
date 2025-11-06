#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    extern char **environ;
    putenv("PRIVATE_ENV=666666");
    pid_t id = fork();
    if(id == 0){ //child
        //char *const myargv[] = {
        //    "ls",
        //    "-l",
        //    "-a",
        //    NULL
        //};
        printf("before: I am a process, pid: %d, ppid:%d\n", getpid(), getppid());
        //sleep(5);
        // 这类方法的标准写法
        //execl("/usr/bin/ls", "ls", "-a", "-l", NULL);
        //execlp("ls", "ls", "-a", "-l", NULL);
        //execl("/usr/bin/top", "top", NULL);
        
        //execv("/usr/bin/ls", myargv);
        //execvp("ls", myargv);
        //无论是我们的可执行程序，还是脚本，为什么能跨语言调用呢？？
        //所有语言运行起来，本质都是进程！！！
        char*const myargv[] = {
            "otherExe",
            "-a",
            "-b",
            "-c",
            NULL
        };
        char *const myenv[] = {
            "MYVAL=1111",
            "MYPATH=/usr/bin/XXX",
            NULL
        };
        execle("./otherExe", "otherExe", "-a", "-w", "-v", NULL, myenv);
        //execle("./otherExe", "otherExe", "-a", "-w", "-v", NULL, environ);
        //execv("./otherExe", myargv);
        //execl("/usr/bin/bash", "bash", "test.sh", NULL);
        //execl("/usr/bin/python3", "python3", "test.py", NULL);
        printf("after: I am a process, pid: %d, ppid:%d\n", getpid(), getppid());
        exit(1);
    }
    //father
    pid_t ret = waitpid(id, NULL, 0);
    if(ret > 0) printf("wait success, father pid: %d, ret id: %d\n", getpid(), ret);

    sleep(5);
    return 0;
}
