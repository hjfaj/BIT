#include "label.h"
#include <QDebug>
#include <QMouseEvent>

Label::Label(QWidget* parent) : QLabel(parent)
{

}

void Label::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "按下左键";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "按下右键";
    }
    // 当前 event 对象就包含了鼠标点击位置的坐标.
    // qDebug() << event->x() << ", " << event->y();
    // globalX 和 globalY 是以屏幕左上角为原点, 获取的坐标.
    // qDebug() << event->globalX() << ", " << event->globalY();
}

void Label::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "释放左键";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "释放右键";
    }
}

void Label::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        qDebug() << "双击左键";
    } else if (event->button() == Qt::RightButton) {
        qDebug() << "双击右键";
    }
}
