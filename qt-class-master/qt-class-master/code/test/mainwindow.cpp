#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QDockWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->menuBar();

    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    QMenu* menu1 = new QMenu("文件 (&F)");
    menuBar->addMenu(menu1);
    menu1->setIcon(QIcon(":/open.png"));

    QMenu* menu2 = new QMenu("打开最近文件 (&O)");
    menu2->setIcon(QIcon(":/save.png"));
    menu1->addMenu(menu2);
    menu1->addSeparator();

    QAction* action1 = new QAction("aaa.txt");
    QAction* action2 = new QAction("bbb.txt");
    action1->setIcon(QIcon(":/open.png"));
    action2->setIcon(QIcon(":/save.png"));
    menu2->addAction(action1);
    menu2->addAction(action2);

    QToolBar* toolBar = new QToolBar();
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    toolBar->addAction(action1);
    toolBar->addAction(action2);
    // toolBar->setMovable(false);
    toolBar->setFloatable(false);

    QToolBar* toolBar2 = new QToolBar();
    this->addToolBar(toolBar2);
    toolBar2->addAction(action1);

    QDockWidget* dockWidget = new QDockWidget();
    dockWidget->setStyleSheet("background-color: green;");
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    QWidget* widget = new QWidget();
    dockWidget->setWidget(widget);

    QVBoxLayout* layout = new QVBoxLayout();
    widget->setLayout(layout);

    QLabel* label = new QLabel("label");
    QPushButton* button = new QPushButton("按钮");
    layout->addWidget(label);
    layout->addWidget(button);
}

MainWindow::~MainWindow()
{
    delete ui;
}

