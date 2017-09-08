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
	void setKey(char * key);//16����
	void setKey(unsigned long key);
	void setKeyDecrypt(char * key);//32λchar ����
	void setKeyDecrypt(unsigned long key);
	void clearKey();
	unsigned short encrypt16(unsigned short plaintext_s);
	unsigned char* encrypt16(unsigned char * plaintext_c);
	bool encryptFile(char *filename, char *newfilename);
	bool decryptFile(char *filename, char *newfilename);
	~MySPN();	//���������������ͷ��ڴ�
	unsigned char crytext[5];
	unsigned char plaintext[4];
	void setKey_01(char *key); //����ר�ã�01���������ַ���
	char * encrypt16_01(char *plaintext_01); //����ר�ã�01���������ַ���
	unsigned short decrypt16(unsigned short crypttext_s, unsigned short &plaintext_s);
	unsigned short decrypt16(char *crypttext, char *plaintext);
	//���±���������
	struct argumKey {
		unsigned long inputKey;
		struct storeKey
		{
			unsigned short key;
			unsigned char keyChar[4];
			bool state;
		} roundKey[5];//�洢����Կ
	} threadArgu;
	struct argumKeyDecrypt {
		char key[32];
		struct storeKeyDecrypt {
			bool state;
			char keyChar[16];
		}roundKey[5];//����Կ �½ṹ
	}threadArguDecrypt;
	static void roundKeyCreat(LPVOID argu);//����Կ���ɣ��˴�������һ���߳�����
protected:
	char sboxDecrypt_c[16][4];
private:
	static void roundKeyCreatDecrypt(LPVOID argu);//����Կ���ɣ�������
	char crytext_01[17]; //����ר�ã�01�����ַ���
	unsigned char * encrypt16_hex(unsigned char * plaintext_c);
	inline char c2hc(char temp) {
		return (temp >= '0'&&temp <= '9') ? temp - '0' :
			(temp >= 'A'&&temp <= 'F') ? temp - 'A' + 10 : temp - 'a' + 10;
	}
	inline void xorDecrypt(char *a, char *key) {
		for (int i = 0; i < 16; i++)
		{
			a[i] = a[i] ^ key[i];
		}
	}
	inline void sboxDecrypt(char *input);
	inline void pboxDecrypt(char *input);

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
	HANDLE hThread, hThreadDecrypt;
};