#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建垂直的布局管理器
    QVBoxLayout* vlayout = new QVBoxLayout();
    this->setLayout(vlayout);

    // 添加两个按钮进去
    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    vlayout->addWidget(button1);
    vlayout->addWidget(button2);

    // 创建水平的布局管理器
    QHBoxLayout* hlayout = new QHBoxLayout();

    // 添加两个按钮进去
    QPushButton* button3 = new QPushButton("按钮3");
    QPushButton* button4 = new QPushButton("按钮4");
    hlayout->addWidget(button3);
    hlayout->addWidget(button4);

    // 把水平布局管理器添加到垂直布局管理器内部
    vlayout->addLayout(hlayout);
}

Widget::~Widget()
{
    delete ui;
}

