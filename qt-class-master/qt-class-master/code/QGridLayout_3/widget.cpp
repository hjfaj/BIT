#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建 6 个按钮. 按照 3 行 2 列的方式进行排列
    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    QPushButton* button3 = new QPushButton("按钮3");
    QPushButton* button4 = new QPushButton("按钮4");
    QPushButton* button5 = new QPushButton("按钮5");
    QPushButton* button6 = new QPushButton("按钮6");

    button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 创建 layout 并把按钮添加进去
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(button1, 0, 0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0);
    layout->addWidget(button4, 1, 1);
    layout->addWidget(button5, 2, 0);
    layout->addWidget(button6, 2, 1);

    // 把 layout 设置到窗口中
    this->setLayout(layout);

    // 设置拉伸系数
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 1);
    layout->setRowStretch(2, 2);
}

Widget::~Widget()
{
    delete ui;
}

