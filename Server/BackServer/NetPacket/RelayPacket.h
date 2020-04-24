#ifndef RELAYPACKET_H
#define RELAYPACKET_H
#include "PacketBase.h"

//Ӧ���������
class RelayPacket:public PacketBase
{
public:
    RelayPacket(char *);
    RelayPacket(videoPacket*);
    RelayPacket(int fd);
    //������ͬ�������ݰ�
  void Login(int userid,bool result);
  void Regist(int userid,bool result);
  void Videolist(struct relay_videList *data,int i,int count);
  //count���ṹ��Ԫ�ظ���
  void UploadHistory(bool result);
    virtual char * Tochar();
    virtual videoPacket* Getpacket();

private:

  bool isEffective;
  int client_fd;

};

#endif // RELAYPACKET_H
