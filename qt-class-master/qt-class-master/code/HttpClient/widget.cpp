#include "widget.h"
#include "ui_widget.h"
#include <QNetworkReply>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");

    manager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 1. 获取到输入框中的 url.
    QUrl url(ui->lineEdit->text());
    // 2. 构造一个 HTTP 请求对象
    QNetworkRequest request(url);
    // 3. 发送请求
    QNetworkReply* response = manager->get(request);
    // 4. 通过信号槽, 来处理响应
    connect(response, &QNetworkReply::finished, this, [=]() {
        if (response->error() == QNetworkReply::NoError) {
            // 响应正确获取到了.
            QString html = response->readAll();
            ui->plainTextEdit->setPlainText(html);
        } else {
            // 响应出错了
            ui->plainTextEdit->setPlainText(response->errorString());
        }
        // 还需要对 response 进行释放.
        response->deleteLater();
    });
}
