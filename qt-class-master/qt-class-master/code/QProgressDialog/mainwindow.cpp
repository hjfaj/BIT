#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::handleTimeout);

    // 把对话框的初始化逻辑放到了构造函数中.
    dialog = new QProgressDialog(this);
    dialog->setWindowTitle("进度条对话框");
    dialog->setLabelText("当前任务进度为: ");
//    dialog->setMinimum(0);
//    dialog->setMaximum(100);
    dialog->setRange(0, 100);
    // 前面介绍的这些内置对话框都有对应的静态函数, 可以方便很容易的创建出这样的对话框并使用.
    // 但是这个进度条对话框就不行了, 就需要咱们手动创建并设置一些属性.
    dialog->setValue(20);

    connect(dialog, &QProgressDialog::canceled, this, [=]() {
        timer->stop();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 把定时器启动的操作放到按钮槽函数中. 显示了对话框再开始计时.
    // 如果写到构造函数里, 程序启动就开始计时了. 后台偷偷的更新对话框中的数值.
    timer->start(100);
    // 点击按钮只是把对话框显示出来.
    dialog->exec();
}

void MainWindow::handleTimeout()
{
    // 在这个槽函数中要操作对话框~~
    // 更新对话框中的进度条数值.
    int value = dialog->value();
    value += 1;
    dialog->setValue(value);
    if (value >= 100) {
        // 进度条到头了.
        timer->stop();
        return;
    }
}
