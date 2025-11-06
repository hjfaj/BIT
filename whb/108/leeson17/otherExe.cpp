#include <iostream>

using namespace std;


int main(int argc, char *argv[], char *env[])
{
    cout << argv[0] << " begin running" << endl;
    cout << "这是命令行参数: \n";
    for(int i=0; argv[i]; i++)
    {
        cout << i << " : " << argv[i] << endl;
    }
    cout << "这是环境变量信息: \n";
    for(int i = 0; env[i]; i++)
    {
        cout << i << " : " << env[i] << endl; 
    }
    cout << argv[0] << " stop running" << endl;
    return 0;
}
