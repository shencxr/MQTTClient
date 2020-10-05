#ifndef MQTT_H
#define MQTT_H

#include <memory>
#include <cassert>
#include <iostream>
using namespace std;
class MQTT
{
public:
    struct Connect_Variable{
        const struct Protocol_Name{
            uint8_t MSB=0x00;
            uint8_t LSB=0x04;
            uint8_t M='M';
            uint8_t Q='Q';
            uint8_t T1='T';
            uint8_t T2='T';
        }ProtocolName;
        uint8_t ProtocolLevel=0x04;
        uint8_t RESERVED:1;
        uint8_t CleanSession:1;
        uint8_t WillFlag:1;
        uint8_t WillQoS:2;
        uint8_t WillRetain:1;
        uint8_t PasswordFlag:1;
        uint8_t UserNameFlag:1;
        uint8_t KeepAliveMSB=0x01;//KeepAlive=300
        uint8_t KeepAliveLSB=0x2c;

        Connect_Variable():RESERVED(0){}
    };

    enum MESSAGE_FIX{
        CONNECT=0x10,
        CONNACK=0x20,
        PUBLISH=0x30,
        PUBACK=0x40,
        PUBREC=0x50,
        PUBREL=0x60,
        PUBCOMP=0x70,
        SUBSCRIBE=0x82,
        SUBACK=0x90,
        UNSUBSCRIBE=0xA0,
        UNSUBACK=0xB0,
        PINGREQ=0xC0,
        PINGRESP=0xD0,
        DISCONNECT=0xE0,
    };

    //Order:Client Identifier/Will Topic/Will Message/User Name/Password
    //Client Identifier MUST be present in payload of CONNECT

    static pair<shared_ptr<const char>,int64_t> connect(string ClientID,string UserName="",string Password="",string WillTopic="",
                                                 string WillMessage="",bool UserNameFlag=false,bool PasswordFlag=false,bool WillFlag=false,
                                                 bool WillRetain=false,uint8_t WillQoS=0,bool CleanSession=true,uint16_t KeepAlive=300){
        string final;
        Connect_Variable var;
        var.UserNameFlag=UserNameFlag?1:0;
        var.PasswordFlag=UserNameFlag?1:0;
        var.WillFlag=WillFlag?1:0;
        var.WillRetain=WillFlag&&WillRetain?1:0;
        var.WillQoS=WillFlag&&WillQoS?WillQoS:0;
        var.CleanSession=CleanSession?1:0;
//        var.RESERVED=0;
        var.KeepAliveMSB=(KeepAlive>>8)&0xFF;
        var.KeepAliveLSB=KeepAlive&0xFF;

//        cout<<uint32_t(var.UserNameFlag)<<endl;
//        cout<<uint32_t(var.PasswordFlag)<<endl;
//        cout<<uint32_t(var.WillRetain)<<endl;
//        cout<<uint32_t(var.WillQoS)<<endl;
//        cout<<uint32_t(var.WillFlag)<<endl;
//        cout<<uint32_t(var.CleanSession)<<endl;
//        cout<<uint32_t(var.RESERVED)<<endl;

        using puint8_t=uint8_t*;
        uint8_t *p=puint8_t(&var);
        for(size_t i=0;i<sizeof(Connect_Variable);i++){
            final.push_back(char(*p++));
        }

        MQTT_Util_Convert_string_to_UTF8(ClientID);
        final+=ClientID;

        if(WillFlag){
            MQTT_Util_Convert_string_to_UTF8(WillTopic);
            final+=WillTopic;
            MQTT_Util_Convert_string_to_UTF8(WillMessage);
            final+=WillMessage;
        }

        if(UserNameFlag){
            MQTT_Util_Convert_string_to_UTF8(UserName);
            final+=UserName;
        }

        if(PasswordFlag){
            MQTT_Util_Convert_string_to_UTF8(Password);
            final+=Password;
        }

        final.insert(0,MQTT_Util_Calc_remain_len(final));
//        final.insert(0,char(CONNECT));
        final.insert(0,1,CONNECT);


        char *p_raw=new char[final.size()];
        memcpy(p_raw,final.c_str(),final.size());
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,final.size());
    }


//    pair<shared_ptr<const char>,int64_t> connect(const Connect_Variable& Variable,const string& ClientID,const string&UserName="",const string&Password="",const string& WillTopic="",
//                                                 const string&WillMessage="");

    static pair<shared_ptr<const char>,int64_t> subscribe(unsigned short MessageID,string Topic,unsigned char QoS=0){
        string final;
        final.push_back(char((MessageID>>8)&0xFF));
        final.push_back(char(MessageID&0xFF));

        MQTT_Util_Convert_string_to_UTF8(Topic);
        final+=Topic;
        final.push_back(char(QoS&0xFF));

        final.insert(0,MQTT_Util_Calc_remain_len(final));
        final.insert(0,1,char(SUBSCRIBE));

        char *p_raw=new char[final.size()];
        memcpy(p_raw,final.c_str(),final.size());
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,final.size());
    }

    static pair<shared_ptr<const char>,int64_t> publish(string Topic,string Message,unsigned char QoS=0,uint16_t MessageID=0,
                                                        unsigned char DUP=0,unsigned char Retain=0){
        string final;

        MQTT_Util_Convert_string_to_UTF8(Topic);
        final+=Topic;
        final.push_back(char(QoS&0xFF));

        if(QoS!=0){
            final.push_back(char((MessageID>>8)&0xFF));
            final.push_back(char(MessageID&0xFF));
        }

        final+=Message;

        final.insert(0,MQTT_Util_Calc_remain_len(final));
        final.insert(0,1,char(PUBLISH|(QoS!=0?((DUP&1)<<3):0)|((QoS&0x3)<<1)|(Retain&1)));

        char *p_raw=new char[final.size()];
        memcpy(p_raw,final.c_str(),final.size());
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,final.size());
    }

    static void unpack_publish(pair<shared_ptr<const char>,int64_t> pack){

    }

    static pair<shared_ptr<const char>,int64_t> unsubscribe(unsigned short MessageID,string Topic){
        string final;
        final.push_back(char((MessageID>>8)&0xFF));
        final.push_back(char(MessageID&0xFF));

        MQTT_Util_Convert_string_to_UTF8(Topic);
        final+=Topic;


        final.insert(0,MQTT_Util_Calc_remain_len(final));
        final.insert(0,1,char(UNSUBSCRIBE));

        char *p_raw=new char[final.size()];
        memcpy(p_raw,final.c_str(),final.size());
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,final.size());
    }

    static pair<shared_ptr<const char>,int64_t> pingreq(){
        char *p_raw=new char[2];
        p_raw[0]=static_cast<char>(PINGREQ);
        p_raw[1]=0;
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,2);
    }

    static pair<shared_ptr<const char>,int64_t> disconnect(){
        char *p_raw=new char[2];
        p_raw[0]=static_cast<char>(DISCONNECT);
        p_raw[1]=0;
        shared_ptr<const char> d(p_raw,[](const char*p_raw){delete []p_raw;});
        return pair<shared_ptr<const char>,int64_t>(d,2);
    }

    static void MQTT_Util_Convert_string_to_UTF8(string& str){
        size_t len=str.length();
        str.insert(str.begin(),char(len%0xff));
        str.insert(str.begin(),char(len/0xff));
    }

    static string MQTT_Util_Calc_remain_len(const string& str){
        string remain_len;
        size_t len=str.size();
        assert(len<(1<<29));
        size_t _re;
        do{
            _re=len/128;
            remain_len.push_back(char(len%128|(_re>0?(1<<7):0)));
            len=len/128;
        }while(_re!=0);
        return remain_len;
    }

};





#endif // MQTT_H
