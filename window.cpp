#include <QDebug>
#include "window.h"
#include "ui_window.h"
#include <QRegExp>
#include <QValidator>
#include <QRegExpValidator>
#include <QHostAddress>
#include <algorithm>
#include <QTime>
using namespace std;
Window::Window(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::Form),client(new QTcpSocket(this))
{
    ui->setupUi(this);

//    ui->Remote_IP_lineEdit->setValidator(new QRegExpValidator(QRegExp("(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\:"),this));
//    ui->Remote_IP_lineEdit->setInputMask("000\\.000\\.000\\.000;_");
    client->bind(QHostAddress(QHostAddress::Any));
    setCentralWidget(ui->widget);

    connect(client,&QTcpSocket::connected,this,[&](){
        ui->Host_IP_label->setText(client->peerAddress().toString()+" : "+QString("%1").arg(client->peerPort()));
        ui->Connect_label->setText("connected");
        ui->Connect_pushButton->setEnabled(false);
        ui->Disconnect_pushButton->setEnabled(true);
    });
    connect(client,&QTcpSocket::disconnected,this,[&](){
        ui->Connect_label->setText("disconnected");
        ui->Connect_pushButton->setEnabled(true);
        ui->Disconnect_pushButton->setEnabled(false);
    });
    connect(client,&QTcpSocket::readyRead,this,[&](){
        QByteArray pack=client->readAll();
        ui->Receive_textEdit->append(QTime::currentTime().toString("hh:mm:ss.zzz")+" : ");
        ui->Receive_textEdit->append(pack.toHex(' '));
    });
}

void Window::on_Connect_pushButton_clicked()
{

    if(ui->Remote_IP_lineEdit->text().isEmpty()){
        return;
    }
    QStringList info=ui->Remote_IP_lineEdit->text().split(":");
//    auto host_ip=host.splitRef(":");
//    for_each(host_ip.begin(),host_ip.end(),[](QStringRef str){qDebug()<<str;});
    client->connectToHost(info[0],info[1].toUShort());
}

void Window::on_Disconnect_pushButton_clicked()
{
//    client->disconnectFromHost();
    client->close();
}
