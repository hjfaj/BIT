#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::mySignal1, this, &Widget::mySlot1);
    connect(this, &Widget::mySignal1, this, &Widget::mySlot2);
    connect(this, &Widget::mySignal2, this, &Widget::mySlot1);
    connect(this, &Widget::mySignal2, this, &Widget::mySlot3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mySlot1()
{
    qDebug() << "mySlot1";
}

void Widget::mySlot2()
{
    qDebug() << "mySlot2";
}

void Widget::mySlot3()
{
    qDebug() << "mySlot3";
}

