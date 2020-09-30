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

private:
    Ui::Form *ui;
    QTcpSocket *client;
};

#endif // WINDOW_H
