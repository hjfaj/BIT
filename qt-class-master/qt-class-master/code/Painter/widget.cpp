#include "widget.h"
#include "ui_widget.h"

#include <QPainter>

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

void Widget::paintEvent(QPaintEvent *event)
{
    (void) event;
    // 绘图工作就会放到这里来执行.

    QPainter painter(this);

//    QFont font("微软雅黑", 24);
//    painter.setFont(font);

    QPen pen;
    // 设置成红色的线条
    pen.setColor(QColor(255, 0, 0));
    // 设置线条的粗细.
    pen.setWidth(5);
    // 设置线条的风格
    pen.setStyle(Qt::DashLine);

    // 让 painter 对象应用 pen 对象
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(QColor(0, 255, 0));
    // brush.setStyle(Qt::SolidPattern);
    brush.setStyle(Qt::CrossPattern);
    painter.setBrush(brush);

    // 画一个线段.
//    painter.drawLine(20, 20, 200, 20);
//    painter.drawLine(QPoint(20, 100), QPoint(200, 100));
    // painter.drawLine(20, 20, 100, 300);

    // 画一个矩形.
    // painter.drawRect(100, 100, 300, 200);

    // 画圆形.
    painter.drawEllipse(200, 200, 400, 100);

    // 绘制文本.
    // painter.drawText(0, 100, "hello");
}

