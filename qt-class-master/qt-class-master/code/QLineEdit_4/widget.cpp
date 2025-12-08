#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始情况下, 输入框按照密码方式来显示.
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_toggled(bool checked)
{
    if (checked) {
        // true 则是 "显示密码" 状态, 就把输入框的显示模式, 设为 Normal
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        // false 则是 "隐藏密码" 状态, 就把输入框的显示模式, 设为 Password
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}
