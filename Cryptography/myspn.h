/*myspn �ӿڽ���
void setKey(char * key);
void setKey(unsigned long key);
	������Կ�������֣�һ�����ַ������͵ģ�char[4]������Ϊ16����
	��һ������ֵ unsigned long
	�޷���
unsigned short encrypt16(unsigned short plaintext_s);
unsigned char* encrypt16(unsigned char * plaintext_c);
	16λ���ļ��ܣ������֣�һ���Ƕ�16λ��ֵ���м��ܣ�����16λ��ֵ
	��һ���Ƕ��ַ������͵�ʮ���������ݼ��ܣ�char[4]��
		��������Ϊ�ַ���0��--��9������a/A��--��f/F����
		�����ַ��������ַ���������λһ�����ֵ
~MySPN();
	�ͷſռ䣬δ�õ�������α��ʼ����һ�£�������������Կ����ʵûɶ�ã�
unsigned char crytext[5];
	���ģ�unsiigned char* encrypt16�������ݣ�crytext[4]='/0'����������õ�
unsigned char plaintext[4];
	���ģ��ṹͬcrytext

2017.8.21 Ϊ�����ԺͲ�ַ������ر�������������ӿ�
void setKey_01(char *key); 
	����Ϊ �ַ�������ġ�010101��
char * encrypt16_01(char *plaintext_01); 
	����Ϊ �ַ���������ġ�010101�������Ϊ�ַ�����ֵ�ġ�\0\1\0\1\0\1��
*/
#pragma once
#include "stdafx.h"
#include <windows.h>

//#define NumRound 4

class MySPN {
public:
	MySPN();//���캯��
	void setKey(char * key);
	void setKey(unsigned long key);
	unsigned short encrypt16(unsigned short plaintext_s);
	unsigned char* encrypt16(unsigned char * plaintext_c);
	~MySPN();	//���������������ͷ��ڴ�
	unsigned char crytext[5];
	unsigned char plaintext[4];
	void setKey_01(char *key); //����ר�ã�01���������ַ���
	char * encrypt16_01(char *plaintext_01); //����ר�ã�01���������ַ���

private:
	char crytext_01[17]; //����ר�ã�01�����ַ���
	unsigned char * encrypt16_hex(unsigned char * plaintext_c);
	static void roundKeyCreat(LPVOID argu);//����Կ���ɣ��˴�������һ���߳�����
	inline char c2hc(char temp) {
		return (temp >= '0'&&temp <= '9') ? temp - '0' :
			(temp >= 'A'&&temp <= 'F') ? temp - 'A' + 10 : temp - 'a' + 10;
	}
	struct argumKey {
		unsigned long inputKey;
		struct storeKey
		{
			unsigned short key;
			unsigned char keyChar[4];
			bool state;
		} roundKey[5];//�洢����Կ
	} threadArgu;
	inline void xor16(unsigned char *key,unsigned char *text) {
		text[0] = text[0] ^ key[0];
		text[1] = text[1] ^ key[1];
		text[2] = text[2] ^ key[2];
		text[3] = text[3] ^ key[3];
	}//����������������
	unsigned char sbox_c[16];
	inline void sbox16(unsigned char *text) {
		text[0] = sbox_c[text[0]];
		text[1] = sbox_c[text[1]];
		text[2] = sbox_c[text[2]];
		text[3] = sbox_c[text[3]];
	}
	inline void pbox16(unsigned char *text);
	HANDLE hThread;
};