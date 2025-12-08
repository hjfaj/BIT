#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_light_clicked()
{
    // 设置窗口的样式
    this->setStyleSheet("background-color: rgb(240, 240, 240);");
    // 设置输入框的样式
    ui->plainTextEdit->setStyleSheet("background-color: white; color: black;");
    // 设置按钮的样式
    ui->pushButton_light->setStyleSheet("color: black;");
    ui->pushButton_dark->setStyleSheet("color: black;");
}

void Widget::on_pushButton_dark_clicked()
{
    // 设置窗口的样式
    this->setStyleSheet("background-color: black;");
    // 设置输入框的样式
    ui->plainTextEdit->setStyleSheet("background-color: black; color: white;");
    // 设置按钮的样式
    ui->pushButton_light->setStyleSheet("color: white;");
    ui->pushButton_dark->setStyleSheet("color: white;");
}
