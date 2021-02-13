#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* x, int* y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

int main()
{
	int a = 0;
	int b = 0;

	printf("请输入两个整形:>");
	scanf("%d %d", &a, &b);
	printf("交换前: a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("交换后: a = %d b = %d\n", a, b);

	return 0;
}