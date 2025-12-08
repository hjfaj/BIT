#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton->setStyleSheet("QPushButton { font-size: 50px; }");

    ui->pushButton_2->setStyleSheet("QPushButton { color: green; }");
}

Widget::~Widget()
{
    delete ui;
}

