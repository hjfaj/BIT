#pragma once

#include <iostream>
#include <string>
#include <pthread.h>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>

#include "Socket.hpp"
#include "Log.hpp"

const std::string wwwroot="wwwroot"; // web 根目录

static const int defaultport = 8082;

class HttpServer;

class ThreadData
{
public:
    ThreadData(int fd) : sockfd(fd)
    {
    }

public:
    int sockfd;
};

class HttpRequest
{
public:
    void Deserialize(std::string req)
    {

    }
public:
    std::vector<std::string> req_header;
    std::string text;
};

class HttpServer
{
public:
    HttpServer(uint16_t port = defaultport) : port_(port)
    {
    }
    bool Start()
    {
        listensock_.Socket();
        listensock_.Bind(port_);
        listensock_.Listen();
        for (;;)
        {
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            if (sockfd < 0)
                continue;
            lg(Info, "get a new connect, sockfd: %d", sockfd);
            pthread_t tid;
            ThreadData *td = new ThreadData(sockfd);
            pthread_create(&tid, nullptr, ThreadRun, td);
        }
    }
    static std::string ReadHtmlContent(const std::string &htmlpath)
    {
        // 坑
        std::ifstream in(htmlpath);
        if(!in.is_open()) return "404";

        std::string content;
        std::string line;
        while(std::getline(in, line))
        {
            content += line;
        }

        in.close();

        return content;
    }
    static void HandlerHttp(int sockfd)
    {
        char buffer[10240];
        ssize_t n = recv(sockfd, buffer, sizeof(buffer) - 1, 0); // bug
        if (n > 0)
        {
            buffer[n] = 0;
            std::cout << buffer; // 假设我们读取到的就是一个完整的，独立的http 请求
            HttpRequest req;
            req.Deserialize(buffer);

            std::string path = wwwroot;
            path += url; // wwwroot/a/a/b/index.html

            // 返回响应的过程
            std::string text = ReadHtmlContent(path);

            std::string response_line = "HTTP/1.0 200 OK\r\n";
            std::string response_header = "Content-Length: ";
            response_header += std::to_string(text.size()); // Content-Length: 11
            response_header += "\r\n";
            std::string blank_line = "\r\n"; // \n

            std::string response = response_line;
            response += response_header;
            response += blank_line;
            response += text;

            send(sockfd, response.c_str(), response.size(), 0);
        }
        close(sockfd);
    }
    static void *ThreadRun(void *args)
    {
        pthread_detach(pthread_self());
        ThreadData *td = static_cast<ThreadData *>(args);
        HandlerHttp(td->sockfd);
        delete td;
        return nullptr;
    }
    ~HttpServer()
    {
    }

private:
    Sock listensock_;
    uint16_t port_;
};
