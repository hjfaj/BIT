#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(100);
    ui->horizontalSlider->setMaximum(2000);
    ui->horizontalSlider->setValue(800);
    ui->horizontalSlider->setSingleStep(50);

    ui->verticalSlider->setMinimum(100);
    ui->verticalSlider->setMaximum(1500);
    ui->verticalSlider->setValue(600);
    ui->verticalSlider->setSingleStep(50);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    const QRect& rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), value, rect.height());
}

void Widget::on_verticalSlider_valueChanged(int value)
{
    const QRect& rect = this->geometry();
    this->setGeometry(rect.x(), rect.y(), rect.width(), value);
}
