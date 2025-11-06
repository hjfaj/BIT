//#pragma once
#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include <string.h>

#define SIZE 1024

#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_ALL 4

typedef struct IO_FILE{
    int fileno;
    int flag; 
    //char inbuffer[SIZE];
    //int in_pos;
    char outbuffer[SIZE]; // 用一下这个
    int out_pos;
}_FILE;

_FILE * _fopen(const char*filename, const char *flag);
int _fwrite(_FILE *fp, const char *s, int len);
void _fclose(_FILE *fp);




#endif
