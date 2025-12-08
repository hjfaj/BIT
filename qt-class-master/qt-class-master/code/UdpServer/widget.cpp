#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QNetworkDatagram>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建出这个对象.
    socket = new QUdpSocket(this);

    // 设置窗口标题
    this->setWindowTitle("服务器");

    // 连接信号槽.
    connect(socket, &QUdpSocket::readyRead, this, &Widget::processRequest);

    // 绑定端口号.
    bool ret = socket->bind(QHostAddress::Any, 9090);
    if (!ret) {
        // 绑定失败!
        QMessageBox::critical(this, "服务器启动出错", socket->errorString());
        return;
    }
}

Widget::~Widget()
{
    delete ui;
}

// 这个函数完成的逻辑, 就是服务器的最核心逻辑了.
void Widget::processRequest()
{
    // 1. 读取请求并解析.
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    // 2. 根据请求计算响应. (由于是回显服务器. 响应不需要计算, 就是请求本身).
    const QString& response = process(request);
    // 3. 把响应写回给客户端.
    QNetworkDatagram responseDatagram(response.toUtf8(), requestDatagram.senderAddress(), requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);
    // 把这次交互的信息, 显示到界面上.
    QString log = "[" + requestDatagram.senderAddress().toString() + ":" + QString::number(requestDatagram.senderPort())
            + "] req: " + request + ", resp: " + response;
    ui->listWidget->addItem(log);
}

QString Widget::process(const QString &request)
{
    // 由于当前是回显服务器, 响应就是和请求完全一样.
    // 对于一个成熟的商业服务器, 这里请求->响应的计算过程可能是非常复杂的. (业务逻辑).
    return request;
}

