#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏
    QMenuBar* menuBar = this->menuBar();
    this->setMenuBar(menuBar);

    // 创建菜单
    QMenu* menu = new QMenu("文件");
    menuBar->addMenu(menu);

    // 工具栏是需要手动创建出来的. 自身不会自动创建.
    QToolBar* toolBar = new QToolBar();
    this->addToolBar(toolBar);

    // 创建两个菜单项
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");
    // action1->setToolTip("点击这里保存文件");
    action1->setIcon(QIcon(":/save.png"));
    action2->setIcon(QIcon(":/open.png"));

    // 菜单项还可以放到菜单中
    menu->addAction(action1);
    menu->addAction(action2);

    // 菜单项放到工具栏中
    toolBar->addAction(action1);
    toolBar->addAction(action2);

    connect(action1, &QAction::triggered, this, &MainWindow::handle1);
    connect(action2, &QAction::triggered, this, &MainWindow::handle2);
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

