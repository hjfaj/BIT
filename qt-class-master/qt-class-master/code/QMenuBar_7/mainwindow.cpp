#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QMenuBar* menuBar = new QMenuBar();
    QMenuBar* menuBar = this->menuBar();
    this->setMenuBar(menuBar);

    QMenu* menu = new QMenu("菜单");
    menu->setIcon(QIcon(":/open.png"));
    menuBar->addMenu(menu);

    QAction* action1 = new QAction("菜单项1");
    action1->setIcon(QIcon(":/open.png"));
    QAction* action2 = new QAction("菜单项2");
    action2->setIcon(QIcon(":/save.png"));
    menu->addAction(action1);
    menu->addAction(action2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

