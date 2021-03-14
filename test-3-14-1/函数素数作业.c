#include <stdio.h>

int xld(int a)
{
	int i;
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int a;
	do
	{
	printf("请输入一个数>:");
	scanf("%d", &a);

	if (xdd(a) == 0)
	{
		printf("%d不是素数\n", a);
	}
	else
	{
		printf("%d是素数\n", a);
	}
	} while (1);
	
	return 0;
}