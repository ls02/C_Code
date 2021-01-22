#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

void external(int x)
{
	int i = 0;
	int j = 0;

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%-2d*%-2d=%-3d ", i, j, i * j);
		}
		putchar('\n');
	}
}


int main()
{
	int i = 0;

	scanf("%d", &i);

	external(i);


	return 0;
}

//void swap(int* a, int* b)
//{
//	int tem = *a;
//	*a = *b;
//	*b = tem;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	scanf("%d %d", &a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//
//	return 0;
//}

//int main()
//{
//	int year = 0;
//
//	scanf("%d", &year);
//
//	if (((year % 400 == 0) && (year % 100 != 0)) || year % 4 == 0)
//	{
//		printf("%d是闰年\n", year);
//	}
//	else
//	{
//		printf("%d不是闰年\n",year);
//	}
//
//	return 0;
//}

//int result(int i)
//{
//	int j = 0;
//
//	for (j = 2; j <= sqrt(i); j++)
//	{
//		if (0 == i % j)
//		{
//			return 0;
//		}
//	}
//
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//
//	for (i = 100; i < 200; i++)
//	{
//		if (result(i) == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//    int arr[7] = { 0 };
//    int i = 0;
//    int max = 0;
//    int min = 0;
//    float sum = 0;
//
//    for (i = 0; i < 7; i++)
//    {
//        scanf("%d",&arr[i]);
//    }
//
//    for (i = 0; i < 6; i++)
//    {
//        if (arr[i] > arr[i + 1])
//        {
//            min = arr[i];
//        }
//        else if (arr[i] < arr[i + 1])
//        {
//            max = arr[i];
//        }
//        sum = arr[0];
//        sum += arr[i + 1];
//    }
//
//    sum = (sum - min - max) / 5.0;
//    printf("%.2f", sum);
//
//    return 0;
//}