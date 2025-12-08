#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu* menu = new QMenu("菜单");
    menuBar->addMenu(menu);

    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");
    menu->addAction(action1);
    menu->addSeparator();
    menu->addAction(action2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

