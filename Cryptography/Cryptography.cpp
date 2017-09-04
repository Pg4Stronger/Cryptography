// Cryptography.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������spn����
#include "stdafx.h"
#include "myspn.h"
#include "MyRSA.h"
int test_SPN_file();
int test_decrypt_SPN();
int main() {
//	test_decrypt_SPN();
//	test_SPN_file();
	MySPN test;
	test.setKey(0x70114090);
	test.setKeyDecrypt(0x70114090);
	test.encryptFile("D://first", "D://new");
	test.decryptFile("D://new", "D://old");
/*	unsigned short a=0;
	std::cout << test.decrypt16(test.encrypt16(123), a) << std::endl;
	*/system("pause");
	return 0;
}

int test_SPN_file() {
	MySPN test;
	test.setKey(0x70114090);
	test.setKeyDecrypt(0x70114090);
	test.encryptFile("D://first", "D://new");
	test.decryptFile("D://new", "D://old");
	system("pause");
	return 0;
}

int test_decrypt_SPN() {
	MySPN test;
	test.setKey(255);
	test.setKeyDecrypt(255);
	while (true) {
		unsigned short text, aaa=0,bbb=0;
		std::cin >> text;
		aaa=test.encrypt16(text);
		std::cout << "���� ����" << std::endl;
		std::cout << aaa << std::endl;
		std::cout << "���� ����" << std::endl;
		std::cout << test.decrypt16(aaa,bbb)<< std::endl;
	}
	return 0;
}

int test_RSA_key() {
	MyRSA test;
	clock_t start;
	clock_t end;
	start = clock();
	test.CreateKey();
	end = clock();
	test.printKey();
	std::cout << "\n\n" << end - start << std::endl;
	system("pause");
	return 0;
}

int test_spn_01() {
	char input[20];
	char keyinput[50];
	for (int i = 0; i < 32; i++)
	{
		std::cin >> keyinput[i];
	}
	MySPN test;
	test.setKey_01(keyinput);
	std::cout << "key ok" << std::endl;
	for (int i = 0; i < 16; i++)
	{
		std::cin >> input[i];
	}
	std::cout << test.encrypt16_01(input) << std::endl;
	return 0;
}

int spn()
{
	int keyType;
	unsigned char plaintext[10];
	char keyString[10];
	MySPN test;
	unsigned short keyNum;
	do {
		std::cout << "��������Կ��ʽ��\n16���Ʊ�ʾ������1\nʮ�������ֱ�ʾ������0\n" << std::endl;
		std::cin >> keyType;
		std::cout << "�밴����ȷ���ĸ�ʽ������Կ��������32λ��(16�����벻Ҫ����0x)\n"
			<<"16�����밴�յ�ַ˳�����루��С�˸�ʽ�����ַ˳����ͬ�� "<< std::endl;
		if (keyType == 1) {
			std::cin >> keyString;
			test.setKey(keyString);
			break;
		}else if(keyType==0){
			std::cin >> keyNum;
			test.setKey(keyNum);
			break;
		}else {
			std::cout << "�밴Ҫ������0/1" << std::endl;
			continue;
		}
	} while (true);//������ѡ���ѭ��ִ��
	std::cout << "������16�������ģ������Ƴ���Ϊ16λ��\n" << std::endl;
	std::cin >> plaintext;//û�ж����ͽ��м�⣬Ӧ���еģ�����Ϊ�˼�������ʱ��
	test.encrypt16(plaintext);
	std::cout << "���ģ� " << std::hex << (int)test.crytext[0] 
		<<(int) test.crytext[1] << (int)test.crytext[2] 
		<< (int)test.crytext[3] << std::endl;
	system("pause");//�������
	return 0;
}

