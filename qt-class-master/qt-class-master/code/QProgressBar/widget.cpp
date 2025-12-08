#include "widget.h"
#include "ui_widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::handle);
    // 别忘了启动定时器. 启动操作要在 connect 之后.
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    // 获取到进度条的当前数值.
    int value = ui->progressBar->value();
    if (value >= 100) {
        // 进度条满了, 就可以停止定时器了.
        timer->stop();
        return;
    }
    ui->progressBar->setValue(value + 1);
}

