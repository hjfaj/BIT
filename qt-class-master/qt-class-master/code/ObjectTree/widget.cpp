#include "widget.h"
#include "ui_widget.h"
#include "mylabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用自己定义的 MyLabel 代替原来的 QLabel. 所谓的 "继承" 本质上是扩展. 保持原有功能不变的基础上,
    // 给对象扩展出一个析构函数. 通过这个析构函数, 打印一个自定义的日志. 方便咱们观察程序运行效果.
    MyLabel* label = new MyLabel(this);
    label->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}

