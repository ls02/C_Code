#define _CRT_SECURE_NO_WARNINGS 1
#define BOOK "War and Peace"
#include <stdio.h>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("&p+%d=%p\n", i, &arr + i);
		printf("&p+%d=%d\n", i, p + i);
		printf("---------------------------\n");

	}

	return 0;
}