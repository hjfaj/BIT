#include "widget.h"
#include "ui_widget.h"

#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    int value = ui->lcdNumber->intValue();
//    while (true) {
//        // 先休眠 1s
//        std::this_thread::sleep_for(std::chrono::seconds(1));
//        if (value <= 0) {
//            break;
//        }
//        value -= 1;
//        ui->lcdNumber->display(value);
//    }

    std::thread t([this] () {
        int value = this->ui->lcdNumber->intValue();
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (value <= 0) {
                break;
            }
            value -= 1;
            ui->lcdNumber->display(value);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

