#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏
    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    // 创建菜单
    QMenu* menu1 = new QMenu("文件 (&F)");
    QMenu* menu2 = new QMenu("编辑 (&E)");
    QMenu* menu3 = new QMenu("视图 (&V)");
    QMenu* menu4 = new QMenu("关于 (&A)");
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);
    menuBar->addMenu(menu3);
    menuBar->addMenu(menu4);

    // 创建菜单项
    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");
    QAction* action3 = new QAction("菜单项3");
    QAction* action4 = new QAction("菜单项4");
    menu1->addAction(action1);
    menu2->addAction(action2);
    menu3->addAction(action3);
    menu4->addAction(action4);
}

MainWindow::~MainWindow()
{
    delete ui;
}

