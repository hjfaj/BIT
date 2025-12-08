#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button = new QPushButton(this);
    button->setGeometry(0, 0, 100, 100);
    button->setText("按钮");
    button->setStyleSheet("QPushButton { border: 5px solid red; margin: 20px;} ");

    qDebug() << button->geometry();
}

Widget::~Widget()
{
    delete ui;
}

