#include "widget.h"
#include "./ui_widget.h"

#include <QDebug>

#include <QGrpcChannelOptions>
#include <QGrpcHttp2Channel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 创建客户端
    client = new helloworld::Greeter::Client(parent);

    // 2. 连接信号槽, 处理出错情况
    connect(client, &QAbstractGrpcClient::errorOccurred, this, [=](const QGrpcStatus& status) {
        qDebug() << "error: " << status.code() << ", " << status.message();
    });

    // 3. 创建 channel
    QUrl url("http://47.108.28.88:8089");
    QGrpcChannelOptions options(url);
    std::shared_ptr<QAbstractGrpcChannel> channel = std::make_shared<QGrpcHttp2Channel>(options);

    // 4. 客户端关联到 channel
    client->attachChannel(channel);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 1. 获取到文本
    const QString& text = ui->lineEdit->text();
    // 2. 构造请求
    helloworld::HelloRequest req;
    req.setName(text);
    // 3. 调用远程方法
    std::shared_ptr<QGrpcCallReply> grpcReply = client->SayHello(req);
    // 4. 通过信号槽处理响应
    connect(grpcReply.get(), &QGrpcCallReply::errorOccurred, this, [=](const QGrpcStatus& status) {
        qDebug() << "error: " << status.code() << ", " << status.message();
    });
    connect(grpcReply.get(), &QGrpcCallReply::finished, this, [=]{
        const helloworld::HelloReply& resp = grpcReply->read<helloworld::HelloReply>();
        qDebug() << "resp: " << resp.message();
    });
}

