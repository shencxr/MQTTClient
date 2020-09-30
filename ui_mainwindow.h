/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *Topic;
    QPushButton *Send;
    QLineEdit *Topic_2;
    QLineEdit *Topic_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(556, 407);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Topic = new QLineEdit(centralWidget);
        Topic->setObjectName(QString::fromUtf8("Topic"));
        Topic->setGeometry(QRect(50, 50, 381, 20));
        Send = new QPushButton(centralWidget);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setGeometry(QRect(110, 190, 75, 23));
        Topic_2 = new QLineEdit(centralWidget);
        Topic_2->setObjectName(QString::fromUtf8("Topic_2"));
        Topic_2->setGeometry(QRect(50, 80, 381, 20));
        Topic_3 = new QLineEdit(centralWidget);
        Topic_3->setObjectName(QString::fromUtf8("Topic_3"));
        Topic_3->setGeometry(QRect(50, 110, 381, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 556, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Topic->setText(QApplication::translate("MainWindow", "dev1|securemode=3,signmethod=hmacsha1|", nullptr));
        Send->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Topic_2->setText(QApplication::translate("MainWindow", "dev1&a1iTuQEv1U6", nullptr));
        Topic_3->setText(QApplication::translate("MainWindow", "fd5840dbf1e74132d6d7043241e7aa6a79ec7902", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
