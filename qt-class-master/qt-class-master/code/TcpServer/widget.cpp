#include "widget.h"
#include "ui_widget.h"
#include <QTcpSocket>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 修改窗口标题.
    this->setWindowTitle("服务器");

    // 2. 创建 QTcpServer 的实例
    tcpServer = new QTcpServer(this);

    // 3. 通过信号槽, 指定如何处理连接.
    connect(tcpServer, &QTcpServer::newConnection, this, &Widget::processConnection);

    // 4. 绑定并监听端口号. 一定要确保准备工作充分了, 再真正开张营业.
    //    这个操作得是初始化的最后一步. 都是需要把如何处理连接, 如何处理请求... 都准备好之后, 才能真正绑定端口并监听.
    bool ret = tcpServer->listen(QHostAddress::Any, 9090);
    if (!ret) {
        QMessageBox::critical(this, "服务器启动失败!", tcpServer->errorString());
        exit(1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processConnection()
{
    // 1. 通过 tcpServer 拿到一个 socket 对象, 通过这个对象来和客户端进行通信.
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    QString log = "[" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "] 客户端上线!";
    ui->listWidget->addItem(log);

    // 2. 通过信号槽, 来处理客户端发来请求的情况.
    connect(clientSocket, &QTcpSocket::readyRead, this, [=]() {
        // a) 读取出请求数据. 此处 readAll 返回的是 QByteArray, 通过赋值转成 QString
        QString request = clientSocket->readAll();
        // b) 根据请求处理响应
        const QString& response = process(request);
        // c) 把响应写回到客户端
        clientSocket->write(response.toUtf8());
        // d) 把上述信息记录到日志中.
        QString log = "[" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "] "
                + " req: " + request + ", resp: " + response;
        ui->listWidget->addItem(log);
    });

    // 3. 通过信号槽, 来处理客户端断开连接的情况.
    connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
        // a) 把断开连接的信息通过日志显示出来.
        QString log = "[" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "] 客户端下线!";
        ui->listWidget->addItem(log);
        // b) 手动释放 clientSocket. 直接使用 delete 是下策, 使用 deleteLater 更加合适的.
        // delete clientSocket;
        clientSocket->deleteLater();
    });
}

// 此处写的是回显服务器.
QString Widget::process(const QString request)
{
    return request;
}

