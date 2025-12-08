#include "widget.h"
#include "ui_widget.h"
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置成 3 行 2 列.
    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    // 创建 3 个 label 作为第一列
    QLabel* label1 = new QLabel("姓名");
    QLabel* label2 = new QLabel("年龄");
    QLabel* label3 = new QLabel("电话");

    // 创建 3 个 输入框 作为第二列
    QLineEdit* edit1 = new QLineEdit();
    QLineEdit* edit2 = new QLineEdit();
    QLineEdit* edit3 = new QLineEdit();

    // 把上述控件添加到表单布局中
    layout->addRow(label1, edit1);
    layout->addRow(label2, edit2);
    layout->addRow(label3, edit3);

    // 创建一个 "提交按钮"
    QPushButton* button = new QPushButton("提交");
    layout->addRow(nullptr, button);
}

Widget::~Widget()
{
    delete ui;
}

