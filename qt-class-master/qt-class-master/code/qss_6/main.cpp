#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString style = "QComboBox::down-arrow { image: url(:/down.png); }";
    a.setStyleSheet(style);

    Widget w;
    w.show();
    return a.exec();
}
