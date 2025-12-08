#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    total = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::wheelEvent(QWheelEvent *event)
{
    total += event->delta();
    qDebug() << total;
}

