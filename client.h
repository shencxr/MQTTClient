#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:
private:
    QTcpSocket *_client;
};

#endif // CLIENT_H
