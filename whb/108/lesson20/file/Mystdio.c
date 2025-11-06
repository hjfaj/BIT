#include "Mystdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#define FILE_MODE 0666

// "w", "a", "r"
_FILE * _fopen(const char*filename, const char *flag)
{
    assert(filename);
    assert(flag);

    int f = 0;
    int fd = -1;
    if(strcmp(flag, "w") == 0) {
        f = (O_CREAT|O_WRONLY|O_TRUNC);
        fd = open(filename, f, FILE_MODE);
    }
    else if(strcmp(flag, "a") == 0) {
        f = (O_CREAT|O_WRONLY|O_APPEND);
        fd = open(filename, f, FILE_MODE);
    }
    else if(strcmp(flag, "r") == 0) {
        f = O_RDONLY;
        fd = open(filename, f);
    }
    else 
        return NULL;

    if(fd == -1) return NULL;

    _FILE *fp = (_FILE*)malloc(sizeof(_FILE));
    if(fp == NULL) return NULL;

    fp->fileno = fd;
    //fp->flag = FLUSH_LINE;
    fp->flag = FLUSH_ALL;
    fp->out_pos = 0;

    return fp;
}

// FILE中的缓冲区的意义是什么？？？？
int _fwrite(_FILE *fp, const char *s, int len)
{
    // "abcd\n"
    memcpy(&fp->outbuffer[fp->out_pos], s, len); // 没有做异常处理, 也不考虑局部问题
    fp->out_pos += len;

    if(fp->flag&FLUSH_NOW)
    {
        write(fp->fileno, fp->outbuffer, fp->out_pos);
        fp->out_pos = 0;
    }
    else if(fp->flag&FLUSH_LINE)
    {
        if(fp->outbuffer[fp->out_pos-1] == '\n'){ // 不考虑其他情况
            write(fp->fileno, fp->outbuffer, fp->out_pos);
            fp->out_pos = 0;
        }
    }
    else if(fp->flag & FLUSH_ALL)
    {
        if(fp->out_pos == SIZE){
            write(fp->fileno, fp->outbuffer, fp->out_pos);
            fp->out_pos = 0;
        }
    }

    return len;
}

void _fflush(_FILE *fp)
{
    if(fp->out_pos > 0){
        write(fp->fileno, fp->outbuffer, fp->out_pos);
        fp->out_pos = 0;
    }
}

void _fclose(_FILE *fp)
{
    if(fp == NULL) return;
    _fflush(fp);
    close(fp->fileno);
    free(fp);
}















