#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = "QPushButton { color: red; } ";
    style += "QPushButton:hover { color: green; } ";
    style += "QPushButton:pressed { color: blue; }";
    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
