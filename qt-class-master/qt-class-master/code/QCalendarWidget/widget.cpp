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


void Widget::on_calendarWidget_selectionChanged()
{
    QDate date = ui->calendarWidget->selectedDate();
    qDebug() << date;

    ui->label->setText(date.toString());
}
