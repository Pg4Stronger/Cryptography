#include "stdafx.h"
#include "MyRSA.h"

MyRSA::MyRSA()
{
	mpz_init2(p, 1024);
	mpz_init2(q, 1024);
	mpz_init2(n, 2048);
	mpz_init2(pri, 2048);
	mpz_init2(pub, 2048);
	gmp_randinit_default(state);
}

MyRSA::~MyRSA()
{
	mpz_clears(p, q, n, pri, pub);
}

void MyRSA::CreateKey()
{
	mpz_t psub, qsub;
	mpz_init2(psub, 1024);
	mpz_init2(qsub, 1024);
	mpz_t euler;
	mpz_init2(euler, 2048);
	time_t seed;
	time(&seed);
	gmp_randseed_ui(state,unsigned long(seed));
	gmp_randinit_lc_2exp_size(state, 128);
	//����� �õ� p  q
	do {
		mpz_rrandomb(p, state, 1024);
		mpz_setbit(p, 0);//����Ϊ����
	} while (isNotPrime(p));
	do {
		mpz_rrandomb(q, state, 1024);
		mpz_setbit(q, 0);	//����Ϊ����
	} while (isNotPrime(q));
	//�õ� n
	mpz_mul(n, p, q);
	//��p-1��q-1 ��ŷ����euler
	mpz_sub_ui(psub, p, 1);
	mpz_sub_ui(qsub, q, 1);
	mpz_mul(euler, psub, qsub);
	//�õ���Կ
	do {
		mpz_rrandomb(pub, state, 1024);
		mpz_setbit(pub,0);	//����Ϊ��
	} while (!relaPrime(pub, euler));
	//�ͷ��ڴ�
	mpz_clears(p, q, euler);
}

bool MyRSA::isNotPrime(mpz_t num)
{
	return false;
}

bool MyRSA::relaPrime(mpz_t a, mpz_t b)
{
	return false;
}
