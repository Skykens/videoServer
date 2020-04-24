#ifndef _SHM_FIFO_H_
#define _SHM_FIFO_H_

#include <iostream>


class CShmFIFO 
{
public:
	CShmFIFO(int key, int blksize, int blocks);
	CShmFIFO();
    static CShmFIFO *GetinterfaceRecv(int key,int blksize,int blocks);
    static CShmFIFO *GetinterfaceSend(int key,int blksize,int blocks);
	virtual ~CShmFIFO();

	//����������
	bool init(int key, int blksize, int blocks);
	void destroy(void);
	static void Destroy(int key); //��̬ɾ�������ڴ淽��

	// �򿪺͹ر�
	bool open(int key, int blksize, int blocks);
	void close(void);

	//��ȡ�ʹ洢
	void write(const void *buf);
	void read(void *buf);


protected:

   static CShmFIFO* m_recvFIFO;
   static  CShmFIFO *m_sendFIFO;
	//���̿�����Ϣ��
	bool m_open;
	void *m_shmhead;		// �����ڴ�ͷ��ָ��
	char *m_payload;			// ��Ч���ص���ʼ��ַ
};


#endif /* _SHM_FIFO_H_ */
