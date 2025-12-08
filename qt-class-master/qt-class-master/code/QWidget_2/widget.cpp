#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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


void Widget::on_pushButton_clicked()
{
    qDebug() << "执行了槽函数";
}

void Widget::on_pushButton_enable_clicked()
{
    // 切换第一个按钮的禁用状态.
    // 1. 先获取到第一个按钮当前的可用状态
    bool enable = ui->pushButton->isEnabled();
    if (enable) {
        ui->pushButton->setEnabled(false);
    } else {
        ui->pushButton->setEnabled(true);
    }
}
