#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 先把 QLabel 设置成和窗口一样大, 并且把这个 QLabel 左上角设置到窗口的左上角这里.
    // 让整个 QLabel 铺满整个窗口
    QRect windowRect = this->geometry();
    ui->label->setGeometry(0, 0, windowRect.width(), windowRect.height());

    QPixmap pixmap(":/huaji.png");
    ui->label->setPixmap(pixmap);
    // 启动自动拉伸. 此时图片就能够填充满整个窗口了.
    ui->label->setScaledContents(true);
}

Widget::~Widget()
{
    delete ui;
}

// 此处的形参 event 是非常有用的, 这里就包含了触发这个 resize 事件这一时刻, 窗口的尺寸的数值.
void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
    ui->label->setGeometry(0, 0, event->size().width(), event->size().height());
}

