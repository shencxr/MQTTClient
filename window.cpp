#include <QDebug>
#include "window.h"
#include "ui_window.h"
#include <QRegExp>
#include <QValidator>
#include <QRegExpValidator>
#include <QHostAddress>
#include <algorithm>
#include <QTime>
#include <QTimer>
#include "mqtt.h"
using namespace std;
Window::Window(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::Form),client(new QTcpSocket(this)),Heart_Timer(new QTimer(this))
{
    ui->setupUi(this);

//    ui->Remote_IP_lineEdit->setValidator(new QRegExpValidator(QRegExp("(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\.(\\d|[1-9]\\d|1\\d\\d|2[0-4]\\d|25[0-5])\\:"),this));
//    ui->Remote_IP_lineEdit->setInputMask("000\\.000\\.000\\.000;_");

    ui->Message_ID_lineEdit->setPlaceholderText("HEX:XXXX");
    ui->Message_ID_lineEdit->setValidator(new QRegExpValidator(QRegExp("[\\da-fA-F]{4}"),this));

    client->bind(QHostAddress(QHostAddress::Any));
    setCentralWidget(ui->widget);

    connect(client,&QTcpSocket::connected,this,&Window::deal_ClientConnected);
    connect(client,&QTcpSocket::disconnected,this,[&](){
        ui->Connect_label->setText("disconnected");
        ui->Connect_pushButton->setEnabled(true);
        ui->Disconnect_pushButton->setEnabled(false);
        ui->Publish_pushButton->setEnabled(false);
        ui->Subscribe_pushButton->setEnabled(false);
        ui->Cancl_Subscribe_pushButton->setEnabled(false);
        ui->Heart_beat_pushButton->setEnabled(false);

        Heart_Timer->stop();
        disconnect(Heart_Timer,&QTimer::timeout,this,&Window::_Heart_beat);
    });
    connect(client,&QTcpSocket::readyRead,this,[&](){
        QByteArray pack=client->readAll();
        ui->Receive_textEdit->append(QTime::currentTime().toString("hh:mm:ss.zzz")+" : ");
        ui->Receive_textEdit->append(pack.toHex(' '));
    });



    ui->Connect_pushButton->setEnabled(true);
    ui->Disconnect_pushButton->setEnabled(false);
    ui->Publish_pushButton->setEnabled(false);
    ui->Subscribe_pushButton->setEnabled(false);
    ui->Cancl_Subscribe_pushButton->setEnabled(false);
    ui->Heart_beat_pushButton->setEnabled(false);
}

void Window::on_Connect_pushButton_clicked()
{

    if(ui->Remote_IP_lineEdit->text().isEmpty()){
        return;
    }
    QStringList info=ui->Remote_IP_lineEdit->text().split(":");
    client->connectToHost(info[0],info[1].toUShort());
}

void Window::on_Disconnect_pushButton_clicked()
{
//    client->disconnectFromHost();
    pair<shared_ptr<const char>,int64_t> con=MQTT::disconnect();
    client->write(con.first.get(),con.second);
//    client->close();
}

//#include <memory>
//using namespace std;
void Window::deal_ClientConnected()
{
    ui->Host_IP_label->setText(client->peerAddress().toString()+" : "+QString("%1").arg(client->peerPort()));
    ui->Connect_label->setText("connected");
    ui->Connect_pushButton->setEnabled(false);
    ui->Disconnect_pushButton->setEnabled(true);
    ui->Publish_pushButton->setEnabled(true);
    ui->Subscribe_pushButton->setEnabled(true);
    ui->Cancl_Subscribe_pushButton->setEnabled(true);
    ui->Heart_beat_pushButton->setEnabled(true);
//    if(!ui->Client_ID_lineEdit->text().isEmpty())
    pair<shared_ptr<const char>,int64_t> con=MQTT::connect(ui->Client_ID_lineEdit->text().toStdString(),
                      ui->User_Name_lineEdit->text().toStdString(),ui->Password_lineEdit->text().toStdString(),"","",true,true);
    client->write(con.first.get(),con.second);

}

void Window::on_Heart_beat_pushButton_clicked()
{
//    qDebug()<<ui->Heart_Interval_comboBox->currentText().compare("No");
    if(ui->Heart_Interval_comboBox->currentText().compare("No")==0){
        _Heart_beat();
    }
    else{
        if(Heart_Timer->isActive()){
            disconnect(Heart_Timer,&QTimer::timeout,this,&Window::_Heart_beat);
            Heart_Timer->stop();
        }
        else{
            _Heart_beat();
            connect(Heart_Timer,&QTimer::timeout,this,&Window::_Heart_beat);
            Heart_Timer->start(ui->Heart_Interval_comboBox->currentText().toUInt());
        }
    }
}


void Window::_Heart_beat()
{
    pair<shared_ptr<const char>,int64_t> con=MQTT::pingreq();
    client->write(con.first.get(),con.second);
}

void Window::on_Subscribe_pushButton_clicked()
{
    pair<shared_ptr<const char>,int64_t> con=MQTT::subscribe(ui->Message_ID_lineEdit->text().toUShort(nullptr,16),
                                                                                ui->Topic_lineEdit->text().toStdString(),
                                                                                uint8_t(ui->QoS_comboBox->currentText().toUInt()));
    client->write(con.first.get(),con.second);
}

void Window::on_Cancl_Subscribe_pushButton_clicked()
{
    pair<shared_ptr<const char>,int64_t> con=MQTT::unsubscribe(ui->Message_ID_lineEdit->text().toUShort(nullptr,16),
                                                             ui->Topic_lineEdit->text().toStdString());
    client->write(con.first.get(),con.second);
}


