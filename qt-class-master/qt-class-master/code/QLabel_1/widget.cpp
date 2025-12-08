#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 把第一个 label 设置成显示纯文本.
    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setText("# 这是一段纯文本");

    // 把第二个 label 设置成显示富文本
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<b>这是一段富文本</b>");

    // 把第三个 label 设置成显示 markdown
    ui->label_3->setTextFormat(Qt::MarkdownText);
    ui->label_3->setText("# 这是 markdown 文本");
}

Widget::~Widget()
{
    delete ui;
}

