#ifndef LABEL_H
#define LABEL_H

#include <QLabel>


class Label : public QLabel
{
public:
    Label(QWidget* parent);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // LABEL_H
