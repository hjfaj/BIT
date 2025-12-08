#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QString style = "QPushButton { color: red; font-size: 50px; }";
//    style += "#pushButton_2 { color: green;} ";
//    style += "#pushButton_3 { color: blue;} ";

    QString style = "#pushButton_2, QLineEdit, QLabel { color: red; }";

    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
