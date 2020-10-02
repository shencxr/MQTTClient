/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *Host_label;
    QLabel *Host_IP_label;
    QLabel *Connect_label;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *Remote_IP_label;
    QLineEdit *Remote_IP_lineEdit;
    QLabel *Client_ID_label;
    QLineEdit *Client_ID_lineEdit;
    QLabel *User_Name_label;
    QLineEdit *User_Name_lineEdit;
    QLabel *Password_label;
    QLineEdit *Password_lineEdit;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_4;
    QPushButton *Connect_pushButton;
    QPushButton *Disconnect_pushButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *Publish_pushButton;
    QPushButton *Heart_beat_pushButton;
    QPushButton *Subscribe_pushButton;
    QComboBox *Heart_Interval_comboBox;
    QPushButton *Cancl_Subscribe_pushButton;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *Topic_label;
    QLineEdit *Topic_lineEdit;
    QLabel *Message_ID_label;
    QLineEdit *Message_ID_lineEdit;
    QLabel *QoS_label;
    QComboBox *QoS_comboBox;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *Send_textEdit;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *Clear_Recv_pushButton;
    QPushButton *Clear_Send_pushButton;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *Receive_textEdit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(787, 431);
        widget = new QWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 10, 721, 421));
        verticalLayout_6 = new QVBoxLayout(widget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Host_label = new QLabel(widget);
        Host_label->setObjectName(QString::fromUtf8("Host_label"));
        Host_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(Host_label);

        Host_IP_label = new QLabel(widget);
        Host_IP_label->setObjectName(QString::fromUtf8("Host_IP_label"));
        Host_IP_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(Host_IP_label);

        Connect_label = new QLabel(widget);
        Connect_label->setObjectName(QString::fromUtf8("Connect_label"));
        Connect_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(Connect_label);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Remote_IP_label = new QLabel(widget);
        Remote_IP_label->setObjectName(QString::fromUtf8("Remote_IP_label"));

        gridLayout->addWidget(Remote_IP_label, 0, 0, 1, 1);

        Remote_IP_lineEdit = new QLineEdit(widget);
        Remote_IP_lineEdit->setObjectName(QString::fromUtf8("Remote_IP_lineEdit"));

        gridLayout->addWidget(Remote_IP_lineEdit, 0, 1, 1, 1);

        Client_ID_label = new QLabel(widget);
        Client_ID_label->setObjectName(QString::fromUtf8("Client_ID_label"));

        gridLayout->addWidget(Client_ID_label, 1, 0, 1, 1);

        Client_ID_lineEdit = new QLineEdit(widget);
        Client_ID_lineEdit->setObjectName(QString::fromUtf8("Client_ID_lineEdit"));

        gridLayout->addWidget(Client_ID_lineEdit, 1, 1, 1, 1);

        User_Name_label = new QLabel(widget);
        User_Name_label->setObjectName(QString::fromUtf8("User_Name_label"));

        gridLayout->addWidget(User_Name_label, 2, 0, 1, 1);

        User_Name_lineEdit = new QLineEdit(widget);
        User_Name_lineEdit->setObjectName(QString::fromUtf8("User_Name_lineEdit"));

        gridLayout->addWidget(User_Name_lineEdit, 2, 1, 1, 1);

        Password_label = new QLabel(widget);
        Password_label->setObjectName(QString::fromUtf8("Password_label"));

        gridLayout->addWidget(Password_label, 3, 0, 1, 1);

        Password_lineEdit = new QLineEdit(widget);
        Password_lineEdit->setObjectName(QString::fromUtf8("Password_lineEdit"));

        gridLayout->addWidget(Password_lineEdit, 3, 1, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);

        Connect_pushButton = new QPushButton(widget);
        Connect_pushButton->setObjectName(QString::fromUtf8("Connect_pushButton"));

        verticalLayout_4->addWidget(Connect_pushButton);

        Disconnect_pushButton = new QPushButton(widget);
        Disconnect_pushButton->setObjectName(QString::fromUtf8("Disconnect_pushButton"));

        verticalLayout_4->addWidget(Disconnect_pushButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        Publish_pushButton = new QPushButton(widget);
        Publish_pushButton->setObjectName(QString::fromUtf8("Publish_pushButton"));

        verticalLayout_5->addWidget(Publish_pushButton);

        Heart_beat_pushButton = new QPushButton(widget);
        Heart_beat_pushButton->setObjectName(QString::fromUtf8("Heart_beat_pushButton"));

        verticalLayout_5->addWidget(Heart_beat_pushButton);

        Subscribe_pushButton = new QPushButton(widget);
        Subscribe_pushButton->setObjectName(QString::fromUtf8("Subscribe_pushButton"));

        verticalLayout_5->addWidget(Subscribe_pushButton);

        Heart_Interval_comboBox = new QComboBox(widget);
        Heart_Interval_comboBox->addItem(QString());
        Heart_Interval_comboBox->addItem(QString());
        Heart_Interval_comboBox->addItem(QString());
        Heart_Interval_comboBox->addItem(QString());
        Heart_Interval_comboBox->addItem(QString());
        Heart_Interval_comboBox->setObjectName(QString::fromUtf8("Heart_Interval_comboBox"));
        Heart_Interval_comboBox->setEditable(true);
        Heart_Interval_comboBox->setFrame(true);

        verticalLayout_5->addWidget(Heart_Interval_comboBox);

        Cancl_Subscribe_pushButton = new QPushButton(widget);
        Cancl_Subscribe_pushButton->setObjectName(QString::fromUtf8("Cancl_Subscribe_pushButton"));

        verticalLayout_5->addWidget(Cancl_Subscribe_pushButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);


        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Topic_label = new QLabel(widget);
        Topic_label->setObjectName(QString::fromUtf8("Topic_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Topic_label->sizePolicy().hasHeightForWidth());
        Topic_label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Topic_label);

        Topic_lineEdit = new QLineEdit(widget);
        Topic_lineEdit->setObjectName(QString::fromUtf8("Topic_lineEdit"));

        horizontalLayout->addWidget(Topic_lineEdit);

        Message_ID_label = new QLabel(widget);
        Message_ID_label->setObjectName(QString::fromUtf8("Message_ID_label"));

        horizontalLayout->addWidget(Message_ID_label);

        Message_ID_lineEdit = new QLineEdit(widget);
        Message_ID_lineEdit->setObjectName(QString::fromUtf8("Message_ID_lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Message_ID_lineEdit->sizePolicy().hasHeightForWidth());
        Message_ID_lineEdit->setSizePolicy(sizePolicy1);
        Message_ID_lineEdit->setMaximumSize(QSize(80, 16777215));
        Message_ID_lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        Message_ID_lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(Message_ID_lineEdit);

        QoS_label = new QLabel(widget);
        QoS_label->setObjectName(QString::fromUtf8("QoS_label"));

        horizontalLayout->addWidget(QoS_label);

        QoS_comboBox = new QComboBox(widget);
        QoS_comboBox->addItem(QString());
        QoS_comboBox->addItem(QString());
        QoS_comboBox->addItem(QString());
        QoS_comboBox->addItem(QString());
        QoS_comboBox->setObjectName(QString::fromUtf8("QoS_comboBox"));
        QoS_comboBox->setMaximumSize(QSize(40, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        QoS_comboBox->setPalette(palette);
        QoS_comboBox->setMouseTracking(false);
        QoS_comboBox->setEditable(false);

        horizontalLayout->addWidget(QoS_comboBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Send_textEdit = new QTextEdit(widget);
        Send_textEdit->setObjectName(QString::fromUtf8("Send_textEdit"));

        horizontalLayout_2->addWidget(Send_textEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Clear_Recv_pushButton = new QPushButton(widget);
        Clear_Recv_pushButton->setObjectName(QString::fromUtf8("Clear_Recv_pushButton"));

        verticalLayout->addWidget(Clear_Recv_pushButton);

        Clear_Send_pushButton = new QPushButton(widget);
        Clear_Send_pushButton->setObjectName(QString::fromUtf8("Clear_Send_pushButton"));

        verticalLayout->addWidget(Clear_Send_pushButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        Receive_textEdit = new QTextEdit(widget);
        Receive_textEdit->setObjectName(QString::fromUtf8("Receive_textEdit"));

        horizontalLayout_2->addWidget(Receive_textEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_4);


        retranslateUi(Form);
        QObject::connect(Clear_Recv_pushButton, SIGNAL(clicked()), Receive_textEdit, SLOT(clear()));
        QObject::connect(Clear_Send_pushButton, SIGNAL(clicked()), Send_textEdit, SLOT(clear()));

        Heart_Interval_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        Host_label->setText(QCoreApplication::translate("Form", "host:", nullptr));
        Host_IP_label->setText(QString());
        Connect_label->setText(QCoreApplication::translate("Form", "disconnect", nullptr));
        Remote_IP_label->setText(QCoreApplication::translate("Form", "Remote_IP:", nullptr));
        Remote_IP_lineEdit->setInputMask(QString());
        Remote_IP_lineEdit->setText(QCoreApplication::translate("Form", "a1iTuQEv1U6.iot-as-mqtt.cn-shanghai.aliyuncs.com:1883", nullptr));
        Client_ID_label->setText(QCoreApplication::translate("Form", "Client_ID:", nullptr));
        Client_ID_lineEdit->setText(QCoreApplication::translate("Form", "dev1|securemode=3,signmethod=hmacsha1|", nullptr));
        User_Name_label->setText(QCoreApplication::translate("Form", "User_Name\357\274\232", nullptr));
        User_Name_lineEdit->setText(QCoreApplication::translate("Form", "dev1&a1iTuQEv1U6", nullptr));
        Password_label->setText(QCoreApplication::translate("Form", "Password:", nullptr));
        Password_lineEdit->setText(QCoreApplication::translate("Form", "fd5840dbf1e74132d6d7043241e7aa6a79ec7902", nullptr));
        Connect_pushButton->setText(QCoreApplication::translate("Form", "Connect", nullptr));
        Disconnect_pushButton->setText(QCoreApplication::translate("Form", "Disconnect", nullptr));
        Publish_pushButton->setText(QCoreApplication::translate("Form", "Publish", nullptr));
        Heart_beat_pushButton->setText(QCoreApplication::translate("Form", "Heart_beat", nullptr));
        Subscribe_pushButton->setText(QCoreApplication::translate("Form", "Subscribe", nullptr));
        Heart_Interval_comboBox->setItemText(0, QCoreApplication::translate("Form", "No", nullptr));
        Heart_Interval_comboBox->setItemText(1, QCoreApplication::translate("Form", "10", nullptr));
        Heart_Interval_comboBox->setItemText(2, QCoreApplication::translate("Form", "20", nullptr));
        Heart_Interval_comboBox->setItemText(3, QCoreApplication::translate("Form", "50", nullptr));
        Heart_Interval_comboBox->setItemText(4, QCoreApplication::translate("Form", "100", nullptr));

        Cancl_Subscribe_pushButton->setText(QCoreApplication::translate("Form", "Cancl_Subscribe", nullptr));
        Topic_label->setText(QCoreApplication::translate("Form", "Topic:", nullptr));
        Message_ID_label->setText(QCoreApplication::translate("Form", "MessageID", nullptr));
        QoS_label->setText(QCoreApplication::translate("Form", "QoS", nullptr));
        QoS_comboBox->setItemText(0, QCoreApplication::translate("Form", "0", nullptr));
        QoS_comboBox->setItemText(1, QCoreApplication::translate("Form", "1", nullptr));
        QoS_comboBox->setItemText(2, QCoreApplication::translate("Form", "2", nullptr));
        QoS_comboBox->setItemText(3, QCoreApplication::translate("Form", "3", nullptr));

        Clear_Recv_pushButton->setText(QCoreApplication::translate("Form", "Clear\342\206\222", nullptr));
        Clear_Send_pushButton->setText(QCoreApplication::translate("Form", "\342\206\220Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
