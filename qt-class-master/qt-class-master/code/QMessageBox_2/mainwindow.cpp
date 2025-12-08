#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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
    int result = QMessageBox::information(this, "对话框标题", "对话框文本", QMessageBox::Ok | QMessageBox::Cancel);
    if (result == QMessageBox::Ok) {
        qDebug() << "Ok";
    } else if (result == QMessageBox::Cancel) {
        qDebug() << "Cancel";
    }
}
