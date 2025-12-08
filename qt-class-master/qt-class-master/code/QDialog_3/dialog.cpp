#include "dialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

Dialog::Dialog(QWidget* parent) : QDialog(parent)
{
    // 创建出一些控件, 加入到 Dialog 中. (以 Dialog 作为父窗口)

    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel* label = new QLabel("这是一个对话框", this);
    QPushButton* button = new QPushButton("关闭", this);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &Dialog::handle);
}

void Dialog::handle()
{
    this->close();
}
