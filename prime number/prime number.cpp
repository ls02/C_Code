#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int i = 0;
	int n = 100;
	int j = 0;

	for (i = 2; i < n; i++)
	{
		if (i % 2 != 0)
		{
			printf("%d ", i);
		}
	}

	return 0;
}