#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void mySignal1();
    void mySignal2();
    void mySignal3();

public slots:
    void mySlot1();
    void mySlot2();
    void mySlot3();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
