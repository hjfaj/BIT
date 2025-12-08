#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 在构造函数中, 给这几个 label 设置不同的属性.

    // 设置对齐方式
    ui->label->setText("这是一段文本");
    ui->label->setAlignment(Qt::AlignRight | Qt::AlignTop);

    // 设置自动换行
    ui->label_2->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_2->setWordWrap(true);

    // 设置缩进
    ui->label_3->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);

    // 设置边距
    ui->label_4->setText("这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本这是一段很长的文本");
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(50);
}

Widget::~Widget()
{
    delete ui;
}

