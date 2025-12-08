#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_textEdit_textChanged()
{
    qDebug() << "textChanged: " << ui->textEdit->toPlainText();
}

void Widget::on_textEdit_selectionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    qDebug() << "selectionChanged: " << cursor.selectedText();
}

void Widget::on_textEdit_cursorPositionChanged()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    qDebug() << "cursorPositionChanged: " << cursor.position();
}

void Widget::on_textEdit_undoAvailable(bool b)
{
    qDebug() << "undoAvailable: " << b;
}

void Widget::on_textEdit_redoAvailable(bool b)
{
    qDebug() << "redoAvailable: " << b;
}

void Widget::on_textEdit_copyAvailable(bool b)
{
    qDebug() << "copyAvailable: " << b;
}
