#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 5;

	int* p = &a;

	printf("%d", *p++);

	return 0;
}