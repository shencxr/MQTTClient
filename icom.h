#ifndef ICOM_H
#define ICOM_H

#include <QTcpSocket>
#include <string>
#include <QString>
using namespace std;
class IPackage{
public:
    virtual ~IPackage();

    virtual int64_t length(void) const =0;
    virtual bool push(void)=0;
    virtual const char* get(void) const =0;
};

class ICom{
public:
    virtual ~ICom();

    virtual bool connect(const string&host,uint16_t port)=0;
    virtual bool disconnect(void)=0;
    virtual bool send(const IPackage&)=0;
    virtual bool receive(IPackage&)=0;
};

class TcpSocket:public QTcpSocket,public ICom{
    bool connect(const string&host,uint16_t port);
    bool disconnect(void)=0;
    bool send(const IPackage&)=0;
    bool receive(IPackage&)=0;
};


bool TcpSocket::connect(const string&host,uint16_t port){
    connectToHost(host.c_str(),port);
    return waitForConnected(20);
}
bool TcpSocket::disconnect(void){
    disconnectFromHost();
    return waitForDisconnected(20);
}
bool TcpSocket::send(const IPackage& pack){
    int64_t len=pack.length();
    return len==write(pack.get(),len)?true:false;
}
bool TcpSocket::receive(IPackage&){

}


#endif // ICOM_H
