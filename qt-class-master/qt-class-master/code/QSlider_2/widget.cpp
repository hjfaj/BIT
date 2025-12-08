#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用快捷键, 需要用到 QShortCut 类
    // 需要两个快捷键, - 进行减少, = 进行增加 (= 和 + 是一个按钮)
    QShortcut* shortCut1 = new QShortcut(this);
    shortCut1->setKey(QKeySequence("-"));
    QShortcut* shortCut2 = new QShortcut(this);
    shortCut2->setKey(QKeySequence("="));

    // 使用信号槽, 感知到快捷键被按下.
    connect(shortCut1, &QShortcut::activated, this, &Widget::subValue);
    connect(shortCut2, &QShortcut::activated, this, &Widget::addValue);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText("当前的值为: " + QString::number(value));
}

void Widget::subValue()
{
    // 获取到当前的值
    int value = ui->horizontalSlider->value();
    if (value <= ui->horizontalSlider->minimum()) {
        return;
    }
    ui->horizontalSlider->setValue(value - 5);
}

void Widget::addValue()
{
    // 获取到当前值
    int value = ui->horizontalSlider->value();
    if (value >= ui->horizontalSlider->maximum()) {
        return;
    }
    ui->horizontalSlider->setValue(value + 5);
}
