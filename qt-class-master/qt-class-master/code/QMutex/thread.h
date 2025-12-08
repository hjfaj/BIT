#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();

    // 添加一个 static 成员.
    static int num;
    // 创建锁对象
    static QMutex mutex;

    void run();
};

#endif // THREAD_H
