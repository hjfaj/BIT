#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 此处直接针对 widget 对象来使用 geometry 和 frameGeometry . 观察区别.

//    QRect rect1 = this->geometry();
//    QRect rect2 = this->frameGeometry();
//    qDebug() << rect1;
//    qDebug() << rect2;

    QPushButton* button = new QPushButton(this);
    button->setText("按钮");
    button->move(100, 100);

    connect(button, &QPushButton::clicked, this, &Widget::handle);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle()
{
    QRect rect1 = this->geometry();
    QRect rect2 = this->frameGeometry();
    qDebug() << rect1;
    qDebug() << rect2;
}

