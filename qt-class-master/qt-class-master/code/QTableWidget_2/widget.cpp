#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 先在每个标签页中, 添加一个 Label
    QLabel* label1 = new QLabel(ui->tab);
    label1->setText("标签页1");
    label1->resize(100, 50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页2");
    label2->resize(100, 50);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 使用 addTab 方法来创建新的标签页.
    // 参数1 要指定一个 QWidget.
    // 参数2 指定这个标签页的 text (标题), 此处标题就叫做 Tab + 数字
    int count = ui->tabWidget->count();  // 获取到标签页的数量
    QWidget* w = new QWidget();
    ui->tabWidget->addTab(w, QString("Tab ") + QString::number(count + 1));
    // 添加一个 QLabel 显示内容
    QLabel* label = new QLabel(w);
    label->setText(QString("标签页 ") + QString::number(count + 1));
    label->resize(100, 50);
    // 设置新标签页被选中
    ui->tabWidget->setCurrentIndex(count);
}

void Widget::on_pushButton_2_clicked()
{
    // 获取到当前选中的标签页的下标
    int index = ui->tabWidget->currentIndex();
    // 删除标签页
    ui->tabWidget->removeTab(index);
}

void Widget::on_tabWidget_currentChanged(int index)
{
    qDebug() << "当前选中的标签页是: " << index;
}
