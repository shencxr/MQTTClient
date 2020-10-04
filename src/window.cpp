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
#include <json.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

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
    connect(client,&QTcpSocket::readyRead,this,&Window::deal_ReadyRead);



    ui->Connect_pushButton->setEnabled(true);
    ui->Disconnect_pushButton->setEnabled(false);
    ui->Publish_pushButton->setEnabled(false);
    ui->Subscribe_pushButton->setEnabled(false);
    ui->Cancl_Subscribe_pushButton->setEnabled(false);
    ui->Heart_beat_pushButton->setEnabled(false);

    on_QoS_comboBox_currentIndexChanged(0);
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

void Window::deal_ReadyRead()
{

    QByteArray pack=client->readAll();
    ui->Receive_textEdit->append(QTime::currentTime().toString("hh:mm:ss.zzz")+" : ");
    ui->Receive_textEdit->append(pack.toHex(' '));

    if(((pack[0])&0xF0)==(MQTT::PUBLISH)){
        ui->Receive_textEdit->append("PUBLIC MESSAGE");

        bool DUP=(pack[0]&0b00001000)>>3;
        uint8_t QoS=(pack[0]&0b00000110)>>1;
        bool Retain=(pack[0]&0b00000001);

        ui->Receive_textEdit->append(QString("DUP = %1").arg(DUP));
        ui->Receive_textEdit->append(QString("QoS = %1").arg(QoS));
        ui->Receive_textEdit->append(QString("Retain = %1").arg(Retain));


        size_t len=0,t=0;
        char *tmp=pack.data();
        do {
            tmp++;
            len+=((*tmp)&0x7F)<<((t++)*7);
        }while(*tmp&0x80);
        ui->Receive_textEdit->append(QString("total len = %1").arg(len));

        size_t topic_len=(*++tmp)<<8;
        topic_len+=(*++tmp);
        string topic(++tmp,topic_len);
        tmp+=topic_len;
        ui->Receive_textEdit->append(QString("topic:%1").arg(topic.c_str()));
        ui->Receive_textEdit->append(QString("topic len:%1").arg(topic_len));
        if(QoS==1||QoS==2){
            ushort message_id=(*tmp++)<<8;
            message_id+=(*tmp++);
            ui->Receive_textEdit->append(QString("message id:%1").arg(message_id));
        }
        ui->Receive_textEdit->append(QString("message:%1").arg(tmp));
        QJsonParseError err;
        QByteArray json(tmp,len-2-topic_len-(QoS?2:0));

        QJsonDocument mesg=QJsonDocument::fromJson(json,&err);

        if(err.error!=QJsonParseError::NoError){
            ui->Receive_textEdit->append(QString("message parse error:%1").arg(err.error));
        }
        else{
            ui->Receive_textEdit->append(QString("message :\n%1").arg(QString(mesg.toJson(QJsonDocument::Indented))));

        }

    }


}

void Window::on_Heart_beat_pushButton_clicked()
{
//    qDebug()<<ui->Heart_Interval_comboBox->currentText().compare("No");
    if(ui->Heart_Interval_comboBox->currentText().compare("No")==0){
        _Heart_beat();
    }
    else{
        if(Heart_Timer->isActive()){
            qDebug()<<"Heart_Timer Active";
            disconnect(Heart_Timer,&QTimer::timeout,this,&Window::_Heart_beat);
            Heart_Timer->stop();
        }
        else{
            qDebug()<<"Heart_Timer UNActive";
            _Heart_beat();
            connect(Heart_Timer,&QTimer::timeout,this,&Window::_Heart_beat);
            Heart_Timer->start(ui->Heart_Interval_comboBox->currentText().toUInt());
        }
    }
}


void Window::_Heart_beat()
{
    qDebug()<<"_Heart_beat";
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



void Window::on_Publish_pushButton_clicked()
{
    QJsonParseError err;
    QJsonDocument send=QJsonDocument::fromJson(ui->Send_textEdit->toPlainText().toUtf8(),&err);

    if(err.error!=QJsonParseError::NoError){
        ui->Receive_textEdit->append(QString("send message parse error:%1").arg(err.error));
    }
    else {
//        ui->Receive_textEdit->append(QString("message :\n%1").arg(QString(send.toJson(QJsonDocument::Indented))));
//        ui->Receive_textEdit->append(QString("message :\n%1").arg(QString(send.toJson(QJsonDocument::Compact).toHex(' '))));
        pair<shared_ptr<const char>,int64_t> con=MQTT::publish(ui->Topic_lineEdit->text().toStdString(),send.toJson(QJsonDocument::Compact).toStdString(),ui->QoS_comboBox->currentText().toUInt(),
                      ui->Message_ID_lineEdit->text().toUShort(nullptr,16),
                      (ui->DUP_Button->isChecked()?1:0),
                      (ui->Retain_Button->isChecked()?1:0));

        ui->Send_textEdit->append("public : ");
        ui->Send_textEdit->append(QByteArray(con.first.get(),con.second).toHex(' '));

        client->write(con.first.get(),con.second);
    }
}

void Window::on_QoS_comboBox_currentIndexChanged(int index)
{
    if(index!=0){
        ui->DUP_Button->setCheckable(true);
        ui->Retain_Button->setCheckable(true);
    }
    else{
        ui->DUP_Button->setCheckable(false);
        ui->Retain_Button->setCheckable(false);
    }
}
