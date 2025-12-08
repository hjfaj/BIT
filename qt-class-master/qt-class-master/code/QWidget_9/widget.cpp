#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor(Qt::WaitCursor);
    // ui->pushButton->setCursor(cursor);
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}

