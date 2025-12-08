#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMoveEvent>
#include <QResizeEvent>

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

void Widget::moveEvent(QMoveEvent *event)
{
    qDebug() << event->pos();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
}

