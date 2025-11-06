#pragma once
#include <functional>
#include <string>
#include <signal.h>
#include "Log.hpp"
#include "Socket.hpp"

using func_t = std::function<std::string(std::string &package)>;

class TcpServer
{
public:
    TcpServer(uint16_t port, func_t callback) : port_(port), callback_(callback)
    {
    }
    bool InitServer()
    {
        listensock_.Socket();
        listensock_.Bind(port_);
        listensock_.Listen();
        lg(Info, "init server .... done");
        return true;
    }
    void Start()
    {
        signal(SIGCHLD, SIG_IGN);
        signal(SIGPIPE, SIG_IGN);
        while (true)
        {
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            if (sockfd < 0)
                continue;
            lg(Info, "accept a new link, sockfd: %d, clientip: %s, clientport: %d", sockfd, clientip.c_str(), clientport);
            // 提供服务
            if (fork() == 0)
            {
                listensock_.Close();
                std::string inbuffer_stream;
                // 数据计算
                while (true)
                {
                    char buffer[1280];
                    ssize_t n = read(sockfd, buffer, sizeof(buffer));
                    if (n > 0)
                    {
                        buffer[n] = 0;
                        inbuffer_stream += buffer;

                        lg(Debug, "debug:\n%s", inbuffer_stream.c_str());

                        while (true)
                        {
                            std::string info = callback_(inbuffer_stream);
                            if (info.empty())
                                break;
                            lg(Debug, "debug, response:\n%s", info.c_str());
                            lg(Debug, "debug:\n%s", inbuffer_stream.c_str());
                            write(sockfd, info.c_str(), info.size());
                        }
                    }
                    else if (n == 0)
                        break;
                    else
                        break;
                }

                exit(0);
            }
            close(sockfd);
        }
    }
    ~TcpServer()
    {
    }

private:
    uint16_t port_;
    Sock listensock_;
    func_t callback_;
};