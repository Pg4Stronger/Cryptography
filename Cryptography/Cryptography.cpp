// Cryptography.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������spn����
#include "stdafx.h"
#include "myspn.h"

int main() {
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

