#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
//#include "ui_window.h"
#include <QLineEdit>
#include <QTcpSocket>
namespace Ui {
class Form;
}


class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:

public slots:

private slots:
    void on_Connect_pushButton_clicked();

    void on_Disconnect_pushButton_clicked();

    void deal_ClientConnected();

    void deal_ReadyRead();

    void on_Heart_beat_pushButton_clicked();

    void on_Subscribe_pushButton_clicked();

    void on_Cancl_Subscribe_pushButton_clicked();

    void _Heart_beat();

    void on_Publish_pushButton_clicked();

    void on_QoS_comboBox_currentIndexChanged(int index);

private:
    Ui::Form *ui;
    QTcpSocket *client;
    QTimer* Heart_Timer;
};

#endif // WINDOW_H
