#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    this->setWindowTitle("修改窗口的标题");
    qDebug() << "handleClick";
}

void Widget::handleClick2()
{
    this->setWindowTitle("修改窗口的标题2");
    qDebug() << "handleClick2";
}


void Widget::on_pushButton_2_clicked()
{
    // 1. 先断开 pushButton 原来的信号槽
    //    如果没有 disconnect, 就会构成 一个信号绑定了两个槽函数. 触发信号的时候, 两个槽函数都会执行.
    // disconnect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick);
    // 2. 重新绑定信号槽
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::handleClick2);
}
