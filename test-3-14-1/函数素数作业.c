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
	printf("������һ����>:");
	scanf("%d", &a);

	if (xdd(a) == 0)
	{
		printf("%d��������\n", a);
	}
	else
	{
		printf("%d������\n", a);
	}
	} while (1);
	
	return 0;
}