#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>

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
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("对话框的标题");
    // 设置对话框的尺寸
    dialog->resize(400, 300);
    // 通过 show 方法就可以显示出对话框.
    dialog->show();

    // delete dialog;
    // 正确做法应该是把 delete 和关闭按钮的点击信号关联起来.
    // 在用户点击关闭的时候, 触发 delete.
    // Qt 为了让咱们写的方便, 直接给 QDialog 设置了一个属性, 可以通过设置属性, 完成上述效果.
    dialog->setAttribute(Qt::WA_DeleteOnClose);
}
