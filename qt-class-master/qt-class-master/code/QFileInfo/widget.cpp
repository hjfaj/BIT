#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>

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


void Widget::on_pushButton_clicked()
{
    // 弹出文件对话框, 并获取到文件的属性信息.
    QString path = QFileDialog::getOpenFileName(this);
    // 构造出一个 QFileInfo 对象
    QFileInfo fileInfo(path);
    // 打印相关属性
    qDebug() << fileInfo.fileName();
    qDebug() << fileInfo.suffix();
    qDebug() << fileInfo.path();
    qDebug() << fileInfo.size();
    qDebug() << fileInfo.isFile();
    qDebug() << fileInfo.isDir();

    // ......
}
