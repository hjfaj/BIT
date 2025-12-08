#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = "QLabel { border: 20px dashed green; padding-left: 50px; }";
    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
