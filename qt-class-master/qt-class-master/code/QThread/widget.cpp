#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 连接信号槽, 通过槽函数更新界面.
    connect(&thread, &Thread::notify, this, &Widget::handle);

    // 要启动一下线程.
    thread.start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    // 此处修改界面内容.
    int value = ui->lcdNumber->intValue();
    value--;
    ui->lcdNumber->display(value);
}

