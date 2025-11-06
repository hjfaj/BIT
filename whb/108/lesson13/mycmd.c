#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// ./mycmd /a/b/c/
int main()
{
    extern char **environ;
    int i = 0;
    for(; environ[i]; i++)
    {
        printf("%d: %s\n", i, environ[i]);
    }



//    if(strcmp(argv[1], "cd")==0)
//    {
//        chdir(argv[1]);
//    }
//    sleep(30);
//    printf("change begin\n");
//    if(argc == 2)
//    {
//        chdir(argv[1]);
//    }
//
//    printf("change end\n");
//    sleep(30);
//

    //printf("MYVAL: %s\n", getenv("MYVAL"));
   // int i = 0;
   // for(; env[i]; i++)
   // {
   //     printf("env[%d]->%s\n", i, env[i]);
   // }
   // int i = 0;
   // for(; argv[i]; i++)
   // {
   //     printf("argv[%d]->%s\n", i, argv[i]);
   // }
// //   if(argc != 2) 
//    {
//        printf("Usage: %s -[a|b|c|d]\n", argv[0]);
//        return 0;
//    }
//    if(strcmp(argv[1], "--help")==0)
//    {
//        printf("Usage: %s -[a|b|c|d]\n", argv[0]);
//    }
//    else if(strcmp(argv[1], "-a") == 0)
//    {
//        printf("功能1\n");
//    }
//    else if(strcmp(argv[1], "-b") == 0)
//    {
//        printf("功能2\n");
//    }
//    else if(strcmp(argv[1], "-c") == 0)
//    {
//        printf("功能3\n");
//    }
//    else if(strcmp(argv[1], "-d") == 0)
//    {
//        printf("功能4\n");
//    }
//    else
//    {
//        printf("default功能\n");
//    }
//


   // char who[32];
   // strcpy(who, getenv("USER"));

   // if(strcmp(who, "root") == 0)
   // {
   //     printf("让他做任何事情");
   // }
   // else
   // {
   //     printf("你就是一个普通用户，受权限约束\n");
   // }

    //int i = 0; 
    //for(; i < 10; i++)
    //{
    //    printf("hello %d\n", i);
    //}
    //printf("PATH: %s\n", getenv("PATH"));
    return 0;
}
