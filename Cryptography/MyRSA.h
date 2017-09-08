/*
�������ԣ��������ɵ���Ҫʱ��������˴����������ɣ�
 ����Ҫ�������������������Խ���һ���߳���������һ��������
 ����ʱ����350 ���ҽ����� 200����
*/
#pragma once
#include "stdafx.h"
#include "gmp.h"
#include <time.h>
#include <Windows.h>

#pragma comment (lib , "libgmp-6.1.1.lib")

#define PRIME_NUM 10 //���Լ�����

class  MyRSA
{
public:
	 MyRSA();
	~ MyRSA();
	void CreateKey();
	void CreatePPkey();
	void ClearKey();
	void printKey();
	void encrypt_ModS2(mpz_t &plaintext, mpz_t &crytext);//ģ�ظ�ƽ��
	void encrypt_Montgomery(mpz_t &plaintext, mpz_t &crytext);//�ɸ�����
	void encrypt_China(mpz_t &plaintext, mpz_t &crytext);//�й�ʣ�ඨ��
	void decrypt_ModS2(mpz_t &plaintext, mpz_t &crytext);//ģ�ظ�ƽ��
	void decrypt_Montgomery(mpz_t &plaintext, mpz_t &crytext);//�ɸ�����
	void decrypt_China(mpz_t &plaintext, mpz_t &crytext);//�й�ʣ�ඨ��
	mpz_t  n, pub, pri;
	mpz_t p, q;
private:
	void SquareMultiply(mpz_t &result, mpz_t & text, mpz_t &pub, mpz_t &mod);//ģƽ��
	void Montgomery(mpz_t &result, mpz_t & text, mpz_t &pub, mpz_t &mod);//�ɸ�����
	void China(mpz_t &result, mpz_t text, mpz_t pub,mpz_t p,mpz_t q, mpz_t mod);//�й�ʣ�ඨ��
	bool ok;
	gmp_randstate_t state;
	struct arguement {
		bool * ok;
		gmp_randstate_t * state;
		mpz_t *p;
	}argue;
	static bool isNotPrime(mpz_t &num);
	bool relaPrime(mpz_t &a, mpz_t &b, mpz_t &c, bool state);
	bool priCreat(mpz_t &a, mpz_t &b);
	static void bigPrime(LPVOID argue);
};