#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define ADD

int main()
{
#if !defined ADD
	printf("666\n");
#endif

	return 0;
}