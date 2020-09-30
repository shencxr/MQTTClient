#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTcpSocket>
#include <iostream>
#include <iomanip>
using namespace std;

void MQTT_Util_Convert_string_to_UTF8(string& str){
    size_t len=str.length();
    str.insert(str.begin(),char(len%0xff));
    str.insert(str.begin(),char(len/0xff));
}

string MQTT_Util_Calc_remain_len(const string& str){
    string remain_len;
    size_t len=str.size();
    assert(len<(1<<29));
//    remain_len.push_back(char(len%128))
//    len%128
    size_t _re;
    do{
        _re=len/128;
        remain_len.push_back(char(len%128|(_re>0?(1<<7):0)));
        len=len/128;
    }while(_re!=0);
    return remain_len;
}

string MQTT_Util_Packet(const string& fix,const string& variable,const string& payload=string()){
    return fix+variable+payload;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTcpSocket client;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Send_clicked()
{
//    QByteArray topic=ui->Topic->text().toLatin1();
//    qDebug()<<topic;

//    qDebug()<<*topic.begin();
    string str1=ui->Topic->text().toStdString();
    MQTT_Util_Convert_string_to_UTF8(str1);
    string str2=ui->Topic_2->text().toStdString();
    MQTT_Util_Convert_string_to_UTF8(str2);
    string str3=ui->Topic_3->text().toStdString();
    MQTT_Util_Convert_string_to_UTF8(str3);

    string str=str1+str2+str3;
//    str.push_back(char(255));
//    str.push_back(char(255));
//    cout<<str.back()<<endl;
    size_t n=0;
//    for_each(str.begin(),str.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
//    cout<<endl;
//    QByteArray ar(str.c_str(),int(str.size()));
//    qDebug()<<ar.size();
//    qDebug()<<ar;
//    ar.push_back(56);
//    qDebug()<<ar;
//    qDebug("%d",ar.back().operator char());

    str.insert(str.begin(),{0x00,0x04,0x4D,0x51,0x54,0x54,0x04,char(0xC2),0x00,0x64});
    str.insert(str.begin(),{0x00,0x04,0x4D,0x51,0x54,0x54,0x04,char(0xC2),0x00,0x64});
    str.insert(str.begin(),{0x00,0x04,0x4D,0x51,0x54,0x54,0x04,char(0xC2),0x00,0x64});
    for_each(str.begin(),str.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<uppercase<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
    cout<<endl;
    cout<<"n = "<<n<<endl;
    cout<<"str.size = "<<dec<<str.size()<<endl;
    auto str_r=MQTT_Util_Calc_remain_len(str);
    n=0;
    for_each(str_r.begin(),str_r.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<uppercase<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
    cout<<endl;

    n=0;
    str.insert(1,str_r);
    for_each(str.begin(),str.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<uppercase<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
    cout<<endl;
//    string test(65536,'c');
//    str_r=MQTT_Util_Calc_remain_len(test);
//    n=0;
//    for_each(str_r.begin(),str_r.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<uppercase<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
//    cout<<endl;
//    cout<<hex<<str<<endl;
}
