#include "TcpServer.hpp"
#include <iostream>
#include <memory>

void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

// 下节课：守护进程化
//./tcpserver 8080
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(UsageError);
    }
    uint16_t port = std::stoi(argv[1]);
    lg.Enable(Classfile);
    // std::unique_ptr<TcpServer> tcp_svr(new TcpServer(port, "127.0.0.1"));
    std::unique_ptr<TcpServer> tcp_svr(new TcpServer(port));
    tcp_svr->InitServer();
    tcp_svr->Start();

    return 0;
}