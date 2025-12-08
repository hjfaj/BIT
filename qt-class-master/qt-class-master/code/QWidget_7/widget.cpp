#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置图标
    // QIcon icon("d:/rose.jpg");
    QIcon icon(":/rose.jpg");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}

