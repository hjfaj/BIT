#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建图标对象
    QIcon icon(":/doge.png");
    // 设置图标
    ui->pushButton->setIcon(icon);
    // 设置图标的尺寸
    ui->pushButton->setIconSize(QSize(50, 50));
}

Widget::~Widget()
{
    delete ui;
}

