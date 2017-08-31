#include "stdafx.h"
#include "MyRSA.h"

MyRSA::MyRSA()
{
	mpz_init(p);
	mpz_init(q);
	mpz_init(n);
	mpz_init(pri);
	mpz_init(pub);
	gmp_randinit_default(state);
}

MyRSA::~MyRSA()
{
	mpz_clears(p, q, n, pri, pub);
}

void MyRSA::CreateKey()
{
	mpz_t psub, qsub;
	mpz_init(psub);
	mpz_init(qsub);
	mpz_t euler;
	mpz_init(euler);
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
	//�õ�˽Կ

	//�ͷ��ڴ�
	mpz_clears(psub, qsub, euler);
}

void MyRSA::ClearKey()
{
}

void MyRSA::printKey()
{
	gmp_printf("p   = : %Zd \n", p);
	gmp_printf("q   = : %Zd \n", q);
	gmp_printf("n   = : %Zd \n", n);
	printf("��Կ= :");
	gmp_printf(" %Zd \n", pub);
	printf("˽Կ= :");
	gmp_printf(" %Zd \n", pri);
}

//���� solovay-strassen �㷨
bool MyRSA::isNotPrime(mpz_t num)
{
	mpz_t a, x, y;
	mpz_inits(a, x, y);
	gmp_randinit_default(state);
	time_t seed;
	time(&seed);
	gmp_randseed_ui(state, unsigned long(seed));
	gmp_randinit_lc_2exp_size(state, 128);
	for (int i = 0; i < SOLOVAY_STRASSEN_NUM; i++)
	{
		mpz_urandomm(a, state, num);
		
	}
	return false;
}

bool MyRSA::relaPrime(mpz_t a, mpz_t b)
{
	/*
	mpz_t r0, r1, q;
	mpz_init(q);
	if (mpz_cmp(a, b) > 0) {
		mpz_init_set(r0, a);
		mpz_init_set(r1, b);
	}
	else {
		mpz_init_set(r0, b);
		mpz_init_set(r1, a);
	}
	while (mpz_cmp_ui(r1, 0)!=0) {
		mpz_set(q, r1);
		mpz_fdiv_r(r1, r0, q);
		mpz_set(r0, q);
	}
	if (mpz_cmp_ui(r0, 1)) {
		mpz_clears(r0, r1, q);
		return true;
	}
	else {
		mpz_clears(r0, r1, q);
		return false;
	}*/
	mpz_t result;
	mpz_init(result);
	mpz_gcd(result , a, b);
	if (mpz_cmp_ui(result,1) == 0) {
		mpz_clear(result);
		return true;
	}
	else {
		mpz_clear(result);
		return false;
	}
	return true;//ǰ��Ӧ�ã���ֹ����
}
