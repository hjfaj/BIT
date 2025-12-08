#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    QPushButton* button3 = new QPushButton("按钮3");
    QPushButton* button4 = new QPushButton("按钮4");

    QGridLayout* layout = new QGridLayout();
//    layout->addWidget(button1, 0, 0);
//    layout->addWidget(button2, 0, 1);
//    layout->addWidget(button3, 1, 0);
//    layout->addWidget(button4, 1, 1);

    // 这个写法就相当于水平布局了
    // 此时大家的 行数 只要是一样的即可, 不一定非得是 0
//    layout->addWidget(button1, 0, 0);
//    layout->addWidget(button2, 0, 1);
//    layout->addWidget(button3, 0, 2);
//    layout->addWidget(button4, 0, 3);

    // 这个写法就相当于垂直布局了
//    layout->addWidget(button1, 0, 0);
//    layout->addWidget(button2, 1, 0);
//    layout->addWidget(button3, 2, 0);
//    layout->addWidget(button4, 3, 0);

    // 这种写法是每个按钮独占一行和一列
    // 即使设置成 100, 100, 也不会在中间搞出很大的空白空间.
    // 此处设置的行数和列数, 只是用来决定控件之间的相对位置.
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 1, 1);
    layout->addWidget(button3, 2, 2);
    layout->addWidget(button4, 100, 100);

    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}

