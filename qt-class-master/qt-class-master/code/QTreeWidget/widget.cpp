#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置根节点的名字
    ui->treeWidget->setHeaderLabel("动物");

    // 新增顶层节点
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    // 每个节点都可以设置多个列. 此处为了简单就只设置一列了.
    item1->setText(0, "猫");
    // 添加到顶层节点中.
    ui->treeWidget->addTopLevelItem(item1);

    // 新增顶层节点
    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    // 每个节点都可以设置多个列. 此处为了简单就只设置一列了.
    item2->setText(0, "狗");
    // 添加到顶层节点中.
    ui->treeWidget->addTopLevelItem(item2);

    // 新增顶层节点
    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    // 每个节点都可以设置多个列. 此处为了简单就只设置一列了.
    item3->setText(0, "鸟");
    // 添加到顶层节点中.
    ui->treeWidget->addTopLevelItem(item3);

    // 添加一些子节点
    QTreeWidgetItem* item4 = new QTreeWidgetItem();
    item4->setText(0, "中华田园猫");
    item1->addChild(item4);

    QTreeWidgetItem* item5 = new QTreeWidgetItem();
    item5->setText(0, "布偶猫");
    item1->addChild(item5);

    QTreeWidgetItem* item6 = new QTreeWidgetItem();
    item6->setText(0, "暹罗猫");
    item1->addChild(item6);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_insertTopLevelItem_clicked()
{
    // 获取到输入框中的内容
    const QString& text = ui->lineEdit->text();
    // 构造一个 QTreeWidgetItem
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    // 添加到顶层节点中
    ui->treeWidget->addTopLevelItem(item);
}

void Widget::on_pushButton_insertItem_clicked()
{
    // 获取到当前选中的节点
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr) {
        return;
    }
    // 获取到输入框的内容
    const QString& text = ui->lineEdit->text();
    // 构造一个 QTreeWidgetItem
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0, text);
    // 插入到选中节点的子节点中
    currentItem->addChild(item);
}

void Widget::on_pushButton_deleteItem_clicked()
{
    // 获取到选中的元素
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if (currentItem == nullptr) {
        return;
    }
    // 删除选中的元素, 需要先获取到父元素, 通过父元素进行删除
    QTreeWidgetItem* parent = currentItem->parent();
    if (parent == nullptr) {
        // 顶层元素
        int index = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(index);
    } else {
        // 普通元素
        parent->removeChild(currentItem);
    }
}
