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
	void ClearKey();
	void printKey();

private:
	mpz_t p, q, n, pub, pri;
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