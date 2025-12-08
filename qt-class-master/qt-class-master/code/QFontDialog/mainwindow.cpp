#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
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
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok);
    qDebug() << "ok = " << ok;
    // qDebug() << font;
    qDebug() << font.family();
    qDebug() << font.pointSize();
    qDebug() << font.bold();
    qDebug() << font.italic();

    ui->pushButton->setFont(font);
}
