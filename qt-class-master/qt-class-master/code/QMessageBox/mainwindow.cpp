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
    // 创建 QMessageBox
    QMessageBox* messageBox = new QMessageBox(this);
    messageBox->setWindowTitle("对话框窗口标题");
    messageBox->setText("这是对话框的文本");
    messageBox->setIcon(QMessageBox::Warning);
    // 标准按钮中, 根本就没法进行信号槽的连接. (按钮是 QMessageBox 自己生成的)
    messageBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);

//    QPushButton* button = new QPushButton("按钮", messageBox);
//    messageBox->addButton(button, QMessageBox::AcceptRole);

    // connect 连接信号槽, 来针对当前点击的按钮进行一些相关操作.

    // 非模态的弹框. QMessageBox 使用场景更多的是模态的.
    // messageBox->show();
    // 弹出模态对话框, 当对话框处于弹出状态的时候, 代码就会在 exec 这里阻塞. 一直到对话框被关闭.
    // 用户点击按钮, 使对话框关闭之后, 此时就能通过 exec 的返回值, 来知道用户点击的是哪个按钮, 从而执行一些对应的逻辑了.
    int result = messageBox->exec();
    if (result == QMessageBox::Ok) {
        qDebug() << "OK";
    } else if (result == QMessageBox::Save) {
        qDebug() << "Save";
    } else if (result == QMessageBox::Cancel) {
        qDebug() << "Cancel";
    }

    // delete messageBox;
    messageBox->setAttribute(Qt::WA_DeleteOnClose);
}
