#include "mainwindow.h"
#include <QApplication>
#include "mqtt.h"
#include <iomanip>
#include "window.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

//    MQTT a;
//    MQTT::Connect_Variable a;
//    cout<<sizeof (a)<<endl;
//    uint8_t *p=(uint8_t*)(&a);
//    for(int i=0;i<10;i++){
//        cout<<hex<<setw(2)<<uint32_t(*p++)<<endl;
//    }
//    cout<<"seprator---------"<<endl;

//    cout<<uint(a.UserNameFlag)<<endl;
//    cout<<uint(a.PasswordFlag)<<endl;
//    cout<<uint(a.WillRetain)<<endl;
//    cout<<uint(a.WillQoS)<<endl;
//    cout<<uint(a.WillFlag)<<endl;
//    cout<<uint(a.CleanSession)<<endl;
//    cout<<uint(a.RESERVED)<<endl;

    auto con=MQTT::connect("dev1|securemode=3,signmethod=hmacsha1|",
                  "dev1&a1iTuQEv1U6","fd5840dbf1e74132d6d7043241e7aa6a79ec7902","","",true,true);
    string c(con.first.get(),size_t(con.second));
    cout<<"c.size = "<<c.size()<<endl;
    int n=0;
    for_each(c.begin(),c.end(),[&n](char c){cout<<hex<<setw(2)<<setfill('0')<<uppercase<<static_cast<unsigned int>(c&0xff)<<" ";n++;if(n>=18){cout<<endl;n=0;}});
    cout<<endl;


    Window w;
    w.show();

    return a.exec();
}
