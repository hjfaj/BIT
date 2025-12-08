#include "widget.h"
#include "ui_widget.h"

#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 更推荐这种在堆上创建的方式.
    QLabel* label = new QLabel(this);
    // QLabel label(this);
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}

