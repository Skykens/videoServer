#ifndef HOSTADDRESS_H
#define HOSTADDRESS_H

#pragma once   /*ÿ��C��C++��ʵ��֧�ֶ��������������ϵͳΨһ�Ĺ���*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//��ַ��
class CHostAddress
{
public:
    CHostAddress(const char *ip, unsigned short port);
    CHostAddress();//Ĭ�Ϲ���
    ~CHostAddress();
    void  SetIp(const char *ip);
    const char* GetIp();
    void  SetPort(unsigned short port);
    unsigned short GetPort();
    struct sockaddr * Address();
    struct sockaddr_in * InAddress();
    int Length();
    socklen_t* LengthPtr();
private:
    struct sockaddr_in m_addr;
    int m_length;
};


#endif
