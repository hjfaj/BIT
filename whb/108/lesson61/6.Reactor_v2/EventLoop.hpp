#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <cerrno>
#include <ctime>
#include <functional>
#include <unordered_map>
#include "Log.hpp"
#include "nocopy.hpp"
#include "Epoller.hpp"
#include "Socket.hpp"
#include "Comm.hpp"

class Connection;
class TcpServer;

uint32_t EVENT_IN = (EPOLLIN | EPOLLET);
uint32_t EVENT_OUT = (EPOLLOUT | EPOLLET);
const static int g_buffer_size = 128;

using func_t = std::function<void(std::shared_ptr<Connection>)>;
using except_func = std::function<void(std::weak_ptr<Connection>)>;

class Connection
{
public:
    Connection(int sock, std::shared_ptr<TcpServer> tcp_server_ptr) : _sock(sock), _tcp_server_ptr(tcp_server_ptr), last_active_time(time())
    {
    }
    void SetHandler(func_t recv_cb, func_t send_cb, except_func except_cb)
    {
        _recv_cb = recv_cb;
        _send_cb = send_cb;
        _except_cb = except_cb;
    }
    int SockFd() { return _sock; }
    void AppendInBuffer(const std::string &info)
    {
        _inbuffer += info;
    }
    void AppendOutBuffer(const std::string &info)
    {
        _outbuffer += info;
    }
    std::string &Inbuffer() // for debug
    {
        return _inbuffer;
    }
    std::string &OutBuffer()
    {
        return _outbuffer;
    }
    ~Connection()
    {
    }

private:
    int _sock;
    std::string _inbuffer; // string 二进制流，vector
    std::string _outbuffer;

public:
    func_t _recv_cb;
    func_t _send_cb;
    except_func _except_cb;

    // 添加一个回指指针
    // std::weak_ptr<TcpServer> _tcp_server_ptr; // std::weak_ptr<> // bug??
    std::shared_ptr<TcpServer> _tcp_server_ptr; // std::weak_ptr<>

    std::string _ip;
    uint16_t _port;

    time_t last_active_time;
};

class TcpServer : public nocopy
{
    static const int num = 64;

public:
    TcpServer(uint16_t port, func_t OnMessage)
        : _port(port),
          _OnMessage(OnMessage),
          _quit(true),
          _epoller_ptr(new Epoller()),
          _listensock_ptr(new Sock())
    {
    }
    void Init()
    {
        _listensock_ptr->Socket();
        SetNonBlockOrDie(_listensock_ptr->Fd());
        _listensock_ptr->Bind(_port);
        _listensock_ptr->Listen();
        lg(Info, "create listen socket success: %d", _listensock_ptr->Fd());
        AddConnection(_listensock_ptr->Fd(),
                      EVENT_IN, std::bind(&TcpServer::Accepter, this, std::placeholders::_1), nullptr, nullptr);
    }
    void AddConnection(int sock, uint32_t event, func_t recv_cb, func_t send_cb, except_func except_cb,
                       const std::string &ip = "0.0.0.0", uint16_t port = 0)
    {
        // 1. 给sock也建立一个connection对象，将listensock添加到Connection中，同时，listensock和Connecion放入_connections
        // std::shared_ptr<Connection> new_connection = std::make_shared<Connection>(sock, std::shared_ptr<TcpServer>(this));
        std::shared_ptr<Connection> new_connection = std::make_shared<Connection>(sock, std::shared_ptr<TcpServer>(this));
        new_connection->SetHandler(recv_cb, send_cb, except_cb);
        new_connection->_ip = ip;
        new_connection->_port = port;
        // 2. 添加到unordered_map
        _connections.insert(std::make_pair(sock, new_connection));
        // 3. 我们添加对应的事件，除了要加到内核中，fd， event
        _epoller_ptr->EpllerUpdate(EPOLL_CTL_ADD, sock, event);

        // 4. 给每一个连接添加一个定时器
        Timer timer;
        time_manager.push(timer);

        lg(Debug, "add a new connection success, sockfd is : %d", sock);
    }
    // 链接管理器
    // void Accepter(std::shared_ptr<Connection> connection)
    // {
    //     while (true)
    //     {
    //         struct sockaddr_in peer;
    //         socklen_t len = sizeof(peer);
    //         int sock = ::accept(connection->SockFd(), (struct sockaddr *)&peer, &len);
    //         if (sock > 0)
    //         {
    //             uint16_t peerport = ntohs(peer.sin_port);
    //             char ipbuf[128];
    //             inet_ntop(AF_INET, &peer.sin_addr.s_addr, ipbuf, sizeof(ipbuf));
    //             lg(Debug, "get a new client, get info-> [%s:%d], sockfd : %d", ipbuf, peerport, sock);

    //             SetNonBlockOrDie(sock);
    //             // listensock只需要设置_recv_cb, 而其他sock，读，写，异常
    //             AddConnection(sock, EVENT_IN,
    //                           std::bind(&TcpServer::Recver, this, std::placeholders::_1),
    //                           std::bind(&TcpServer::Sender, this, std::placeholders::_1),
    //                           std::bind(&TcpServer::Excepter, this, std::placeholders::_1),
    //                           ipbuf, peerport); // TODO
    //         }
    //         else
    //         {
    //             if (errno == EWOULDBLOCK)
    //                 break;
    //             else if (errno == EINTR)
    //                 continue;
    //             else
    //                 break;
    //         }
    //     }
    // }
    // 事件管理器
    // 应不应该关心数据的格式？？？不应该！！服务器只要IO数据就可以，有没有读完，报文的格式细节，你不用管。
    void Recver(std::shared_ptr<Connection> connection)
    {
        connection->last_active_time = time(nullptr);
        // std::cout << "haha, got you!!!!, sockfd: " << connection->SockFd() << std::endl;
        int sock = connection->SockFd();
        while (true)
        {
            char buffer[g_buffer_size];
            memset(buffer, 0, sizeof(buffer));
            ssize_t n = recv(sock, buffer, sizeof(buffer) - 1, 0); // 非阻塞读取
            if (n > 0)
            {
                connection->AppendInBuffer(buffer);
            }
            else if (n == 0)
            {
                lg(Info, "sockfd: %d, client info %s:%d quit...", sock, connection->_ip.c_str(), connection->_port);
                connection->_except_cb(connection);
            }
            else
            {
                if (errno == EWOULDBLOCK)
                    break;
                else if (errno == EINTR)
                    continue;
                else
                {
                    lg(Warning, "sockfd: %d, client info %s:%d recv error...", sock, connection->_ip.c_str(), connection->_port);
                    connection->_except_cb(connection);
                    return;
                }
            }
        }
        // 数据有了，但是不一定全，1. 检测 2. 如果有完整报文，就处理
        _OnMessage(connection); // 你读到的sock所有的数据connection
    }
    void Sender(std::shared_ptr<Connection> connection)
    {
        connection->last_active_time = time(nullptr);

        auto &outbuffer = connection->OutBuffer();
        while(true)
        {
            ssize_t n = send(connection->SockFd(), outbuffer.c_str(), outbuffer.size(), 0);
            if(n > 0)
            {
                outbuffer.erase(0, n);
                if(outbuffer.empty()) break;
            }
            else if(n == 0)
            {
                return;
            }
            else
            {
                if(errno == EWOULDBLOCK) break;
                else if(errno == EINTR) continue;
                else{
                    lg(Warning, "sockfd: %d, client info %s:%d send error...", connection->SockFd(), connection->_ip.c_str(), connection->_port);
                    connection->_except_cb(connection);
                    return;
                }
            }
        }
        if(!outbuffer.empty())
        {
            // 开启对写事件的关心
            EnableEvent(connection->SockFd(), true, true);
        }
        else
        {
            // 关闭对写事件的关心
            EnableEvent(connection->SockFd(), true, false);
        }
    }
    void Excepter(std::weak_ptr<Connection> connection)
    {
        if(connection.expired()) return;
        auto conn = connection.lock();

        int fd = conn->SockFd();
        lg(Warning, "Excepter hander sockfd: %d, client info %s:%d excepter handler",
           conn->SockFd(), conn->_ip.c_str(), conn->_port);
        // 1. 移除对特定fd的关心
        // EnableEvent(connection->SockFd(), false, false);
        _epoller_ptr->EpllerUpdate(EPOLL_CTL_DEL, fd, 0);
        // 2. 关闭异常的文件描述符
        lg(Debug, "close %d done...\n", fd);
        close(fd);
        // 3. 从unordered_map中移除
        lg(Debug, "remove %d from _connections...\n", fd);
        // TODO bug
        // auto iter = _connections.find(fd);
        // if(iter == _connections.end()) return;
        // _connections.erase(iter);
        // _connections[fd].reset();
        // _connections.erase(fd);
    }
    void EnableEvent(int sock, bool readable, bool writeable)
    {
        uint32_t events = 0;
        events |= ((readable ? EPOLLIN : 0) | (writeable ? EPOLLOUT : 0) | EPOLLET);
        _epoller_ptr->EpllerUpdate(EPOLL_CTL_MOD, sock, events);
    }
    bool IsConnectionSafe(int fd)
    {
        auto iter = _connections.find(fd);
        if (iter == _connections.end())
            return false;
        else
            return true;
    }
    void Dispatcher(int timeout)
    {
        int n = _epoller_ptr->EpollerWait(revs, num, timeout);
        for (int i = 0; i < n; i++)
        {
            uint32_t events = revs[i].events;
            int sock = revs[i].data.fd;
            // 统一把事件异常转换成为读写问题
            if (events & EPOLLERR)
                events |= (EPOLLIN | EPOLLOUT);
            if (events & EPOLLHUP)
                events |= (EPOLLIN | EPOLLOUT);
            // 只需要处理EPOLLIN EPOLLOUT
            if ((events & EPOLLIN) && IsConnectionSafe(sock))
            {
                if (_connections[sock]->_recv_cb)
                    _connections[sock]->_recv_cb(_connections[sock]);
            }
            if ((events & EPOLLOUT) && IsConnectionSafe(sock))
            {
                if (_connections[sock]->_send_cb)
                    _connections[sock]->_send_cb(_connections[sock]);
            }
        }
    }
    void do_other_thing()
    {
        // 检测最小堆 top(); 是否超时
        // 没有超时: int timeout = top()->expired - now();
        // 如果超时：top()->cb(); pop(); 
        // for (auto &connection : _connections)
        // {
        //     // 如果一个连接长时间不动？
        //     timeout = time(nullptr) + 5000000;
        //     if(connection->last_active_time > timeout)
        //     {
        //         // connection->Excepter();
        //     }
        // }
    }
    void Loop()
    {
        _quit = false;

        // AddConnection();

        while (!_quit)
        {
            Dispatcher(1000); //  Dispatcher(timeout);
            // Dispatcher(-1);
            do_other_thing();
            // PrintConnection();
        }

        _quit = true;
    }
    void PrintConnection()
    {
        std::cout << "_connections fd list: ";
        for (auto &connection : _connections)
        {
            std::cout << connection.second->SockFd() << ", ";
            std::cout << "inbuffer: " << connection.second->Inbuffer().c_str();
        }
        std::cout << std::endl;
    }
    ~TcpServer()
    {
    }

private:
    std::shared_ptr<Epoller> _epoller_ptr; // 内核
    // std::shared_ptr<Sock> _listensock_ptr; // 监听socket， 可以把他移除到外部
    std::unordered_map<int, std::shared_ptr<Connection>> _connections;
    struct epoll_event revs[num];
    uint16_t _port;
    bool _quit;

    TimeManager time_manager;

    // 让上层处理信息
    func_t _OnMessage;

    std::vector<int> fds;
};