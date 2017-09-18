// Cryptography.cpp : �������̨Ӧ�ó������ڵ㡣
//
//������spn����
#include "stdafx.h"
#include "myspn.h"
#include "MyRSA.h"
#include "cryptanalysis.h"
#include "MySPNPlus.h"
#include "communicate.h"

time_t start, timeEnd;


//��ַ���
int test_diff() {
	Differential test;
	system("cls");
	std::cout << "������ �ǲ�ַ�������\n" << "Ԥ����Կ��0xab851257" << std::endl;
	start = clock();
	test.analyse();
	timeEnd = clock();
	std::cout << "�ܼ���ʱ  " << timeEnd - start << std::endl;
	system("pause");
	return 0;
}

//ͨ��
int test_communicate() {
	Communicate test;
	char file1[] = "D://first";
	char file2[] = "D://second";
	char file3[] = "D://third";
	system("cls");
	std::cout << "������ ��ͨ�Ų���\n" << "��鿴D��\n" << std::endl;
	start = clock();
	test.encrypt(file1, file2);
	timeEnd = clock();
	printf("%s �ļ����ܵõ� %s\t��ʱ %lld\n", file1, file2, timeEnd - start);
	start = clock();
	test.decrypt(file2, file3);
	timeEnd = clock();
	printf("%s �ļ����ܵõ� %s\t��ʱ %lld\n", file2, file3, timeEnd - start);
	system("pause");
	return 0;
}

//RSA
int test_RSA() {
	mpz_t pub,result;
	mpz_init(result);
	mpz_init(pub);
	mpz_set_ui(pub,0x454624);
	//mpz_t thistext;
	//mpz_init_set(thistext, text);
	//mpz_set_ui(result, 1);
	MyRSA myrsa;
	system("cls");
	std::cout << "������ ��RSA����\n" << "��������" << std::endl;
	start = clock();
	myrsa.CreateKey();
	timeEnd = clock();
	myrsa.printKey();
	std::cout<<"\n��ʱ "<< timeEnd - start<<std::endl;
	printf("100�μ�������");
	gmp_printf("%Zd\n", pub);


	start = clock();
	for (int i = 0; i < 100; i++)
	{
		myrsa.encrypt_ModS2(pub, result);
	}
	timeEnd = clock();
	std::cout << "ģ�ظ�ƽ��������ʱ�� : " << timeEnd - start << std::endl;
	gmp_printf("\n����: %Zd\n", result);
	printf("100�ν��ܸ�����\n");

	start = clock();
	for (int i = 0; i < 100; i++)
	{
		myrsa.decrypt_Montgomery(pub, result);
	}
	timeEnd = clock()-500;
	std::cout << "�ɸ���������ʱ�� : " << timeEnd - start << std::endl;
	
	start = clock();
	for (int i = 0; i < 100; i++)
	{
		myrsa.decrypt_China(pub, result);
	}
	timeEnd = clock();
	std::cout << "�й�ʣ�ඨ�����ʱ�� : " << timeEnd - start << std::endl;
	
	gmp_printf("\n����: %Zd\n", pub);
	system("pause");
	return 0;
}

//���Է���
int test_LinearAnalyse() {
	Linear text;
	system("cls");
	std::cout << "������ �����Է�������\n" << "Ԥ����Կ��0xab851257" << std::endl;
	start = clock();
	text.analyse();
	timeEnd = clock();
	std::cout <<"�ܼ���ʱ  "<< timeEnd - start << std::endl;
	system("pause");
	return 0;
}

//spn��ǿ�� �ļ��ӽ���
int test_spnPlus_file() {
	MySPNPlus test;
	unsigned char key[16] = { 0xab,0x5b,0x7f,0x8d,0x9e,0x85,0x96,0xc3,0xd7,0xb6,0x99,0xe5,0xcf,0x74,0xbd,0x85};
	test.setKey(key);
	test.setKeyDecrypt(key);
	system("cls");
	std::cout << "spn ��ǿ�� �ļ��ӽ���" << std::endl;
	char x[17] = "0000000000000000";
	unsigned long long xy;
	//unsigned long long x = 78545346,y;
	xy=test.encrypt(*(unsigned long long*)x);
	xy = test.decrypt(xy);
	//if (x ==test.decrypt(xy)) std::cout << "OK" << std::endl;
	test.encryptFile("D://first", "D://new");
	test.decryptFile("D://new", "D://old");
	system("pause");
	return 0;
}

//spn �ļ��ӽ���
int test_SPN_file() {
	MySPN test;
	test.setKey(0x70114090);
	test.setKeyDecrypt(0x70114090);
	system("cls");
	std::cout << "spn �ļ��ӽ���" << std::endl;
	test.encryptFile("D://first", "D://new");
	test.decryptFile("D://new", "D://old");
	system("pause");
	return 0;
}

//spn �ӽ���  ������ʽʮ����
int test_decrypt_SPN() {
	MySPN test;
	test.setKey(0xf36d49a3);
	test.setKeyDecrypt(0xf36d49a3);
	unsigned short text, aaa=0,bbb=0;
	system("cls");
	std::cout << "��������" << std::endl;
	std::cin >> text;
	aaa=test.encrypt16(text);
	std::cout << "����" << std::endl;
	std::cout << aaa << std::endl;
	std::cout << "����" << std::endl;
	std::cout << test.decrypt16(aaa,bbb)<< std::endl;
	system("pause");
	return 0;
}

//RSA ����Կ����
int test_RSA_key() {
	MyRSA test;
	clock_t start;
	clock_t end;	
	system("cls");
	std::cout << "RSA ����Կ���� ��ʱ" << std::endl;
	start = clock();
	test.CreateKey();
	end = clock();
	test.printKey();
	std::cout << "\n\n" << end - start << std::endl;
	system("pause");
	return 0;
}

//spn ��01��������ʽ �����������
int test_spn_01() {
	char input[20];
	char keyinput[50];
	system("cls");
	std::cout << "spn 01��������ʽ�����������\n ����32λ����Կ" << std::endl;
	for (int i = 0; i < 32; i++)
	{
		std::cin >> keyinput[i];
	}
	MySPN test;
	test.setKey_01(keyinput);
	std::cout << "key ok\n����������16λ" << std::endl;
	for (int i = 0; i < 16; i++)
	{
		std::cin >> input[i];
	}
	std::cout << "����" << std::endl;
	std::cout << test.encrypt16_01(input) << std::endl;
	return 0;
}

int test_spn()
{
	int keyType;
	unsigned char plaintext[10];
	char keyString[10];
	MySPN test;
	unsigned short keyNum;
	system("cls");
	std::cout << "spn �������" << std::endl;
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



int main() {
	std::cout << "�г�������ʼ" << std::endl;
	//test_spn();
	//test_spn_01();
	//test_decrypt_SPN();
	//test_SPN_file();
	test_spnPlus_file();
	//test_LinearAnalyse();
	//test_LinearAnalyse();
	//test_diff();
	//test_RSA_key();
	//test_RSA();
	//test_communicate();
	system("pause");
	return 0;
}