#include "widget.h"

#include <QApplication>
#include <QFile>

QString loadQSS() {
    QFile file(":/style.qss");
    file.open(QFile::ReadOnly);
    QString style = file.readAll();
    file.close();
    return style;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 设置全局样式
    a.setStyleSheet(loadQSS());

    Widget w;
    w.show();
    return a.exec();
}
