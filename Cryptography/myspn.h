#pragma once
#include "stdafx.h"
#include <windows.h>

//#define NumRound 4

class MySPN {
public:
	MySPN();//���캯��
	void setKey(char * key);
	void setKey(unsigned long key);
	unsigned short encrypt16(unsigned short plaintext);
	unsigned short encrypt16(char * plaintext);
	~MySPN();
	//���������������ͷ��ڴ�
private:
	static void roundKeyCreat(LPVOID argu);//����Կ���ɣ��˴�������һ���߳�����
	struct argumKey {
		unsigned long inputKey;
		struct storeKey
		{
			unsigned short key;
			bool state;
		} roundKey[5];//�洢����Կ
	} threadArgu;
	HANDLE hThread;
};