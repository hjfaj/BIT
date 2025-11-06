#include <iostream>
#include <functional>
#include <memory>
#include "Log.hpp"
#include "TcpServer.hpp"  // 处理IO的
#include "Calculator.hpp" // 处理业务的

Calculator calculator;

// for debug
void DefaultOnMessage(std::shared_ptr<Connection> connection_ptr)
{
    // 对报文进行处理，有bug
    std::cout << "上层得到了数据： " << connection_ptr->Inbuffer() << std::endl;
    std::string response_str = calculator.Handler(connection_ptr->Inbuffer()); // 我们的业务逻辑比较简单，没有特别耗时的操作
    if(response_str.empty()) return;
    lg(Debug, "%s", response_str.c_str());
    // response_str 发送出去
    connection_ptr->AppendOutBuffer(response_str);
    // 正确的理解发送？
    // connection_ptr->_send_cb(connection_ptr);
    connection_ptr->_tcp_server_ptr->Sender(connection_ptr);
}

void Loop()
{
    std::unique_ptr<TcpServer> server(new TcpServer(8888, DefaultOnMessage));
}

int main()
{
       Listener listener;
       listener.Init();

       std::unique_ptr<TcpServer> base_server(new TcpServer(8888, DefaultOnMessage));
       epoll_svr->AddConnection(listener.fd(), EVENT_IN, std::bind(&listener::Accepter, &listener, std::placeholders::_1), nullptr, nullptr);

       // 2. 创建多线程, for, 创建多个
       std::thread(Loop);


    // std::unique_ptr<TcpServer> epoll_svr(new TcpServer(8888, DefaultOnMessage));
    // epoll_svr->Init();
    // epoll_svr->Loop();

    // Epoller ep;
    // // Epoller ep1 = ep;

    return 0;
}