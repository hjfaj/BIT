#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 往这里添加一些元素
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");

    // 在 QListWidgetItem 中, 可以设置字体属性, 设置图标, 设置文字大小, 设置是否被选中等状态~~
//    ui->listWidget->addItem(new QListWidgetItem("C++"));
//    ui->listWidget->addItem(new QListWidgetItem("Java"));
//    ui->listWidget->addItem(new QListWidgetItem("Python"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insert_clicked()
{
    // 1. 先获取到输入框中的内容.
    const QString& text = ui->lineEdit->text();
    // 2. 添加到 QListWidget 中
    ui->listWidget->addItem(text);
}

void Widget::on_pushButton_delete_clicked()
{
    // 1. 先获取到被选中的元素是哪个.
    int row = ui->listWidget->currentRow();
    if (row < 0) {
        return;
    }
    // 2. 按照行号来删除元素
    ui->listWidget->takeItem(row);
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // 通过这个槽函数来感知到变化.
    if (current != nullptr) {
        qDebug() << "当前选中的元素: " << current->text();
    }
    if (previous != nullptr) {
        qDebug() << "上次选中的元素: " << previous->text();
    }
}
