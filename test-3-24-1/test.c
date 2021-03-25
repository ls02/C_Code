#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int prime[50000] = { 1,1 };
void select(int prime[]);
int cnt = 0;

int main()
{
	select(prime);
	int K;
	//为0代表为质数 
	scanf("%d", &K);
	while (K--)
	{
		int a, b, c, c1, i;
		scanf("%d%d", &a, &b);
		c = a + b;
		int temp = sqrt(c);
		int res = 1;
		for (i = 0; i < cnt && prime[i] <= temp; i++)
		{
			int sum = 0;
			while (c % prime[i] == 0) 
			{

				sum++;
				c /= prime[i];
			}
			res = res * (sum + 1);
		}
		if (c > 1)res *= 2;
		printf("%d\n", res);


	}
}
void select(int prime[])
{
	for (int i = 2; i < 250; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < 50000; j += i)
				prime[j] = 1;
		}
	}
	for (int i = 2; i < 50000; i++) {
		if (prime[i] == 0) {
			prime[cnt++] = i;
		}
	}
}