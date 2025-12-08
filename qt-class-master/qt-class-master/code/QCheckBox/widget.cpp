#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_pushButton_clicked()
{
    QString result = "今天你的安排是: ";
    if (ui->checkBox_study->isChecked()) {
        result += ui->checkBox_study->text() + " ";
    }
    if (ui->checkBox_game->isChecked()) {
        result += ui->checkBox_game->text() + " ";
    }
    if (ui->checkBox_work->isChecked()) {
        result += ui->checkBox_work->text();
    }
    ui->label->setText(result);
}
