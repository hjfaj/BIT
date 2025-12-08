#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置这两个按钮的 toolTip
    ui->pushButton_yes->setToolTip("这是一个 yes 按钮");
    ui->pushButton_yes->setToolTipDuration(3000);

    ui->pushButton_no->setToolTip("这是一个 no 按钮");
    ui->pushButton_no->setToolTipDuration(7000);
}

Widget::~Widget()
{
    delete ui;
}

