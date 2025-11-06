#include "UdpServer.hpp"
#include <memory>
#include <cstdio>
#include <vector>

// "120.78.126.148" 点分十进制字符串风格的IP地址

void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

// std::string Handler(const std::string &info, const std::string &clientip, uint16_t clientport)
// {
//     std::cout << "[" << clientip << ":" << clientport << "]# " << info << std::endl;
//     std::string res = "Server get a message: ";
//     res += info;
//     std::cout << res << std::endl;

//     // pid_t id = fork();
//     // if(id == 0)
//     // {
//     //     // ls -a -l -> "ls" "-a" "-l"
//     //     // exec*();
//     // }
//     return res;
// }

// bool SafeCheck(const std::string &cmd)
// {
//     int safe = false;
//     std::vector<std::string> key_word = {
//         "rm",
//         "mv",
//         "cp",
//         "kill",
//         "sudo",
//         "unlink",
//         "uninstall",
//         "yum",
//         "top",
//         "while"
//     };
//     for(auto &word : key_word)
//     {
//         auto pos = cmd.find(word);
//         if(pos != std::string::npos) return false;
//     }

//     return true;
// }

// std::string ExcuteCommand(const std::string &cmd)
// {
//     std::cout << "get a request cmd: " << cmd << std::endl;
//     if(!SafeCheck(cmd)) return "Bad man";

//     FILE *fp = popen(cmd.c_str(), "r");
//     if(nullptr == fp)
//     {
//         perror("popen");
//         return "error";
//     }
//     std::string result;
//     char buffer[4096];
//     while(true)
//     {
//         char *ok = fgets(buffer, sizeof(buffer), fp);
//         if(ok == nullptr) break;
//         result += buffer;
//     }
//     pclose(fp);

//     return result;
// }

// ./udpserver port
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t port = std::stoi(argv[1]);

    std::unique_ptr<UdpServer> svr(new UdpServer(port));

    svr->Init(/**/);
    svr->Run();

    return 0;
}