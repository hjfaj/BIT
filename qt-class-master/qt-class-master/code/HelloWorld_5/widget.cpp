#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->myButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    // 当按钮被点击之后, 就把按钮中的文本, 进行切换.
    if (ui->myButton->text() == QString("hello world")) {
        ui->myButton->setText("hello qt");
    } else {
        ui->myButton->setText("hello world");
    }
}

