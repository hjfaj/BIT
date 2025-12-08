#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("简单的记事本");

    // 获取到菜单栏
    QMenuBar* menuBar = this->menuBar();

    // 添加菜单
    QMenu* menu = new QMenu("文件");
    menuBar->addMenu(menu);

    // 添加菜单项
    QAction* action1 = new QAction("打开");
    QAction* action2 = new QAction("保存");
    menu->addAction(action1);
    menu->addAction(action2);

    // 指定一个输入框.
    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(20);
    edit->setFont(font);
    this->setCentralWidget(edit);

    // 连接 QAction 的信号槽.
    connect(action1, &QAction::triggered, this, &MainWindow::handleAction1);
    connect(action2, &QAction::triggered, this, &MainWindow::handleAction2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleAction1()
{
    // 1. 先弹出 "打开文件" 对话框. 让用户选择打开哪个文件.
    QString path = QFileDialog::getOpenFileName(this);

    // 2. 把文件名显示到状态栏里.
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);

    // 3. 根据用户选择的路径, 构造一个 QFile 对象. 并打开文件
    QFile file(path);
    bool ret = file.open(QFile::ReadOnly);
    if (!ret) {
        // 打开文件失败!
        statusBar->showMessage(path + " 打开失败!");
        return;
    }

    // 4. 读取文件了.
    QString text = file.readAll();

    // 5. 关闭文件!! 千万不要忘记!!
    file.close();

    // 6. 读到的内容设置到输入框中.
    edit->setPlainText(text);
}

void MainWindow::handleAction2()
{
    // 1. 先弹出 "保存文件" 对话框.
    QString path = QFileDialog::getSaveFileName(this);

    // 2. 在状态栏中显示这个文件名.
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);

    // 3. 根据用户选择的路径, 构造一个 QFile 对象, 并打开文件.
    QFile file(path);
    bool ret = file.open(QFile::WriteOnly);
    if (!ret) {
        statusBar->showMessage(path + " 打开失败!");
        return;
    }

    // 4. 写文件.
    const QString& text = edit->toPlainText();
    file.write(text.toUtf8());

    // 5. 关闭文件.
    file.close();
}

