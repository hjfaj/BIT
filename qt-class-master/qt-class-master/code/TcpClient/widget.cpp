#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 设置窗口标题
    this->setWindowTitle("客户端");
    // 2. 创建 socket 对象的实例
    socket = new QTcpSocket(this);
    // 3. 和服务器建立连接.
    socket->connectToHost("127.0.0.1", 9090);
    // 4. 连接信号槽, 处理响应
    connect(socket, &QTcpSocket::readyRead, this, [=]() {
        // a) 读取出响应内容
        QString response = socket->readAll();
        // b) 把响应内容显示到界面上.
        ui->listWidget->addItem("服务器说: " + response);
    });
    // 5. 等待连接建立的结果. 确认是否连接成功.
    bool ret = socket->waitForConnected();
    if (!ret) {
        QMessageBox::critical(this, "连接服务器出错", socket->errorString());
        exit(1);
    }
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    // 1. 获取到输入框中的内容
    const QString& text = ui->lineEdit->text();
    // 2. 发送数据给服务器.
    socket->write(text.toUtf8());
    // 3. 把发的消息显示到界面上.
    ui->listWidget->addItem("客户端说: " + text);
    // 4. 清空输入框的内容.
    ui->lineEdit->setText("");
}
