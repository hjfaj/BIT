#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int result = QInputDialog::getInt(this, "整数输入对话框", "请输入一个整数: ");
    qDebug() << result;
}

void MainWindow::on_pushButton_2_clicked()
{
    double result = QInputDialog::getDouble(this, "浮点数输入对话框", "请输入一个浮点数: ");
    qDebug() << result;
}

void MainWindow::on_pushButton_3_clicked()
{
    QStringList items;
    items.push_back("111");
    items.push_back("222");
    items.push_back("333");
    items.push_back("444");
    QString item = QInputDialog::getItem(this, "条目输入对话框", "请输入条目: ", items);
    qDebug() << item;
}
