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


void Widget::on_pushButton_add_clicked()
{
    float opacity = this->windowOpacity();
    if (opacity >= 1.0) {
        return;
    }
    qDebug() << opacity;
    opacity += 0.1;
    this->setWindowOpacity(opacity);
}

void Widget::on_pushButton_sub_clicked()
{
    float opacity = this->windowOpacity();
    if (opacity <= 0.0) {
        return;
    }
    qDebug() << opacity;
    opacity -= 0.1;
    this->setWindowOpacity(opacity);
}
