#include "thread.h"

Thread::Thread()
{

}

void Thread::run()
{
    // 在这个 run 中, 能否直接去进行修改界面内容呢?
    // 不可以的!!!
    // 虽然不可以修改界面, 但是可以针对时间来进行计时.
    // 当每到了一秒钟的时候, 通过信号槽, 来通知主线程, 负责更新的界面内容.
    for (int i = 0; i < 10; i++) {
        // sleep 本身是 QThread 的成员函数, 就可以直接调用.
        sleep(1);
        // 发送一个信号, 通知主线程.
        emit notify();
    }
}
