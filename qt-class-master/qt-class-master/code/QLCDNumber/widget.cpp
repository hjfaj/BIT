#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置初始值
    ui->lcdNumber->display(10);

    // 创建一个 QTimer 实例
    timer = new QTimer(this);
    // 把 QTimer 的 timeout 信号和咱们自己的槽函数进行连接
    connect(timer, &QTimer::timeout, this, &Widget::handle);
    // 启动定时器, 参数是触发 timeout 的周期. 单位是 ms
    timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    // 先拿到 LCDNumber 中的数字
    int value = ui->lcdNumber->intValue();
    if (value <= 0) {
        // 数字减到 0 了, 停止定时器.
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);
}

