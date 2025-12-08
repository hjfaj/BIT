#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu* menu1 = new QMenu("文件(&F)");
    QMenu* menu2 = new QMenu("视图(&V)");
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);

    // 创建四个菜单项
    QAction* action1 = new QAction("action1 (&Q)");
    QAction* action2 = new QAction("action2 (&W)");
    QAction* action3 = new QAction("action3 (&E)");
    QAction* action4 = new QAction("action4 (&R)");
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu2->addAction(action3);
    menu2->addAction(action4);

    // 不绑定槽函数, 通过快捷键选中也没啥反应~~
    connect(action1, &QAction::triggered, this, &MainWindow::handle1);
    connect(action2, &QAction::triggered, this, &MainWindow::handle2);
    connect(action3, &QAction::triggered, this, &MainWindow::handle3);
    connect(action4, &QAction::triggered, this, &MainWindow::handle4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "handle1";
}

void MainWindow::handle2()
{
    qDebug() << "handle2";
}

void MainWindow::handle3()
{
    qDebug() << "handle3";
}

void MainWindow::handle4()
{
    qDebug() << "handle4";
}

