#include "mylabel.h"
#include <iostream>

#include <QDebug>

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{

}

MyLabel::~MyLabel()
{
    // std::cout << "MyLabel 被销毁!" << std::endl;
    qDebug() << "MyLabel 被销毁!";
}
