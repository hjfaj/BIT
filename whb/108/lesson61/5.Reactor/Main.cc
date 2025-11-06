#include <iostream>
#include <functional>
#include <memory>
#include "Log.hpp"
#include "TcpServer.hpp"  // 处理IO的
#include "Calculator.hpp" // 处理业务的

Calculator calculator;

// for debug
void DefaultOnMessage(std::weak_ptr<Connection> conn)
{
    if(conn.expired()) return;
    auto connection_ptr = conn.lock();
    // 对报文进行处理，有bug
    std::cout << "上层得到了数据： " << connection_ptr->Inbuffer() << std::endl;
    std::string response_str = calculator.Handler(connection_ptr->Inbuffer()); // 我们的业务逻辑比较简单，没有特别耗时的操作
    if(response_str.empty()) return;
    lg(Debug, "%s", response_str.c_str());
    // response_str 发送出去
    connection_ptr->AppendOutBuffer(response_str);
    // 正确的理解发送？
    // connection_ptr->_send_cb(connection_ptr);
    
    auto tcpserver = connection_ptr->_tcp_server_ptr.lock();
    tcpserver->Sender(connection_ptr);
}

int main()
{   
    std::shared_ptr<TcpServer> epoll_svr(new TcpServer(8888, DefaultOnMessage));
    epoll_svr->Init();
    epoll_svr->Loop();

    // Epoller ep;
    // // Epoller ep1 = ep;

    return 0;
}