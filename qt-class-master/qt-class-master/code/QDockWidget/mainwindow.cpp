#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 给主窗口添加一个子窗口.
    QDockWidget* dockWidget = new QDockWidget();
    // 使用 addDockWidget 方法, 把浮动窗口加入到子窗口中.
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    // 浮动窗口也是可以设置标题的.
    dockWidget->setWindowTitle("这是浮动窗口");

    // 给浮动窗口内部, 添加一些其他的控件.
    // 不能直接给这个浮动窗口添加子控件, 而是需要创建出一个单独的 QWidget, 把要添加的控件加入到 QWidget 中.
    // 然后再把这个 QWidget 设置到 dockWidget 中.
    QWidget* container = new QWidget();
    dockWidget->setWidget(container);

    // 创建布局管理器, 把布局管理器设置到 QWidget 中
    QVBoxLayout* layout = new QVBoxLayout;
    container->setLayout(layout);

    // 创建其他控件添加到 layout 中.
    QLabel* label = new QLabel("这是一个 QLabel");
    QPushButton* button = new QPushButton("这是按钮");
    layout->addWidget(label);
    layout->addWidget(button);

    // 设置浮动窗口允许停靠的位置
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::TopDockWidgetArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

