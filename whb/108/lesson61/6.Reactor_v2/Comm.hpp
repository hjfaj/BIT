#pragma once

#include <unistd.h>
#include <fcntl.h>

void SetNonBlockOrDie(int sock)
{
    int fl = fcntl(sock, F_GETFL);
    if (fl < 0)
        exit(NON_BLOCK_ERR);
    fcntl(sock, F_SETFL, fl | O_NONBLOCK);
}