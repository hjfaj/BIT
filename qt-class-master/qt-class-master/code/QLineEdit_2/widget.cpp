#include "widget.h"
#include "ui_widget.h"
#include <QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 就需要给单行输入框设置验证器. 基于正则表达式来完成验证的~~
    QRegExp regExp("^1\\d{10}$");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &text)
{
    QString content = text;
    int pos = 0;
    if (ui->lineEdit->validator()->validate(content, pos) == QValidator::Acceptable) {
        // 验证通过
        ui->pushButton->setEnabled(true);
    } else {
        // 验证不通过
        ui->pushButton->setEnabled(false);
    }
}
