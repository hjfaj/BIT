#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置随机种子. 使用时间戳作为随机种子.
    srand(time(0));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("女神女神, 快来嘴儿一个~, mua~");
}

void Widget::on_pushButton_reject_clicked()
{
    // 这个就不要了.
}

void Widget::on_pushButton_reject_pressed()
{
    // 如果女神点击了这个按钮, 就把这个按钮给挪走.
    // 可以通过生成随机数的方式, 来确定按钮的新的位置.

    // 获取到当前程序窗口的尺寸.
    int width = this->geometry().width();
    int height = this->geometry().height();

    // 重新生成按钮的位置.
    int x = rand() % width;
    int y = rand() % height;

    // 移动按钮的位置.
    ui->pushButton_reject->move(x, y);
}
