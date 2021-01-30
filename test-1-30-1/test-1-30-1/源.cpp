#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int gcc = 100;
	int acc = 20;
	int& i = gcc, &k = acc;

	printf("i=%d\n", i);
	printf("k=%d\n", k);
	printf("&gcc=%p\n", &gcc);
	printf("&i=%p\n", &i);
	printf("gcc=%d\n", gcc);
	printf("&k=%p\n", &k);
	printf("&acc=%p\n", &acc);

	return 0;
}

//double Pow(int k, int n)
//{
//	if (0 == n)
//	{
//		return 1;
//	}
//	else if (0 < n)
//	{
//		return k * Pow(k, n - 1);
//	}
//	else
//		return 1.0 / (Pow(k, -n));
//}

//int main()
//{
	//int i = 0;
	//int j = 0;
	//int count = 0;
	//int max = 0;

	//scanf("%d%d", &k, &n);

	//double sum = Pow(k, n);

	//printf("%lf", sum);

	//for (i = 2; i < 10; i++)
	//{		
	//	int count = 1;
	//	for (j = 2; j < i; j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			count = 0;
	//			break;
	//		}
	//	}
	//	if (count)//11 01 01 01 00 00 
	//	{
	//		printf("%d", i);
	//		max++;
	//	}
	//}
	//printf("\n%d", max);

	//for (i = 2; i < 10; i++)
	//{
	//	int count = 1;
	//	for (j = 2; j < sqrt(i); j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			count = 0;
	//			break;
	//		}
	//	}
	//	if (count)//11 01 01 01 00 00 
	//	{
	//		printf("%d", i);
	//		max++;
	//	}
	//}
	//printf("\n%d", max);

//	return 0;
//}