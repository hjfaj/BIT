#include "UdpServer.hpp"
#include <memory>
#include <cstdio>

// "120.78.126.148" 点分十进制字符串风格的IP地址

void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

std::string Handler(const std::string &str)
{
    std::string res = "Server get a message: ";
    res += str;
    std::cout << res << std::endl;

    // pid_t id = fork();
    // if(id == 0)
    // {
    //     // ls -a -l -> "ls" "-a" "-l"
    //     // exec*();
    // }
    return res;
}

std::string ExcuteCommand(const std::string &cmd)
{
    // SafeCheck(cmd);

    FILE *fp = popen(cmd.c_str(), "r");
    if(nullptr == fp)
    {
        perror("popen");
        return "error";
    }
    std::string result;
    char buffer[4096];
    while(true)
    {
        char *ok = fgets(buffer, sizeof(buffer), fp);
        if(ok == nullptr) break;
        result += buffer;
    }
    pclose(fp);

    return result;
}

// ./udpserver port
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t port = std::stoi(argv[1]); //stoi函数把字符串转为整型

    std::unique_ptr<UdpServer> svr(new UdpServer(port));

    svr->Init(/**/);
    svr->Run(ExcuteCommand);

    return 0;
}