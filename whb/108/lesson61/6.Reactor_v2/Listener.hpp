
#pragma once

#include <iostream>

class TcpServer;
class Connection;

class Listener
{
    void Accepter(std::shared_ptr<Connection> connection)
    {
        while (true)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int sock = ::accept(connection->SockFd(), (struct sockaddr *)&peer, &len);
            if (sock > 0)
            {
                uint16_t peerport = ntohs(peer.sin_port);
                char ipbuf[128];
                inet_ntop(AF_INET, &peer.sin_addr.s_addr, ipbuf, sizeof(ipbuf));
                lg(Debug, "get a new client, get info-> [%s:%d], sockfd : %d", ipbuf, peerport, sock);

                SetNonBlockOrDie(sock);
                connection->_tcp_server_ptr->PushVector();
                // listensock只需要设置_recv_cb, 而其他sock，读，写，异常
                // connection->_tcp_server_ptr->AddConnection(sock, EVENT_IN,
                //               std::bind(&TcpServer::Recver, this, std::placeholders::_1),
                //               std::bind(&TcpServer::Sender, this, std::placeholders::_1),
                //               std::bind(&TcpServer::Excepter, this, std::placeholders::_1),
                //               ipbuf, peerport); // TODO
            }
            else
            {
                if (errno == EWOULDBLOCK)
                    break;
                else if (errno == EINTR)
                    continue;
                else
                    break;
            }
        }
    }
    std::shared_ptr<Sock> _listensock_ptr; // 监听socket， 可以把他移除到外部
}