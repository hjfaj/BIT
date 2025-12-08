#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 通过 ui->pushButton 获取到界面上拖上去的这个按钮.
    // connect(ui->pushButton, &QPushButton::clicked, this, &);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_click()
{
    this->setWindowTitle("按钮已经按下!");
}
