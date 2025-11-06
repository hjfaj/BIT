#pragma once
#include <queue>
#include "EventLoop.hpp"

class Timer
{
    uint64_t expired_time;
    bool type;
    func_t cb;
    TcpServer *sp;
    Connection *conn;
};


class TimeManager
{
private:
    std::priority_queue<std::vector<Timer>...>  pq; //堆
}