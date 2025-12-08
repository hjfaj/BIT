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

private slots:
    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_pressed();

    void on_radioButton_3_released();

    void on_radioButton_4_toggled(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
