#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 13, c;
	c = ~a;
	printf("%d", c);

	return 0;
}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int len = 0;
//	int hen = sz - 1;
//	int k = 0;
//
//	scanf("%d", &k);
//
//	while (len <= hen)
//	{
//			int mid = (len + hen) / 2;
//		
//			if (arr [mid]> k)
//			{
//				hen--;
//			}
//			else if (arr[mid] < k)
//			{
//				len++;
//			}
//			else if (arr[mid] == k)
//			{
//				printf("�ҵ��ˣ��±��ǣ�%d", mid);
//				break;
//			}
//	}
//
//	if (len > hen)
//	{
//		printf("û�ҵ���\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d  ", j, i, i * j);
//		}
//		putchar('\n');
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int tem;
//
//	
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//
//	for (i = 0; i <8; i++)
//	{
//		if (arr[i] > arr[i + 1])
//		{
//			tem = arr[i];
//		}
//		else
//		{
//			tem = arr[i + 1];
//		}
//
//	}
//	printf("%d", tem);
//
//	return 0;
//}

///*
//˼·��
//1. ���������ʽ���Է�����
//   a. �ñ��ʽ��Ҫ��100�������Ϊ����ż����Ϊ��
//2. ����һ��ѭ����1~100���������ʽ�е�ÿһ�1.0/i, ע��˴�����ʹ��1��������ȫ��Ϊ0
//	Ȼ��ʹ��flag��ǿ�����ż�������Ϊ����ż����Ϊ��
//	Ȼ�����е�����Ӽ���
//*/
//
//
//
//
//#include <stdio.h>
//
//
//int  main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int a = 0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (9 == i % 10)
//			a++;
//		if (9 == i / 10)
//			a++;
//	}
//	printf("%d", a);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int k = 0;
//	int j = 0;
//
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			k++;
//			printf("%d ", i);
//		}
//	}
//
//	printf("\n%d", k);
//	
//	return 0;
//}

//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		//�ж�year�Ƿ�Ϊ����
//		if (year % 4 == 0)  // ���year�ܹ���4������year����Ϊ����
//		{
//			if (year % 100 != 0) // ���year������100��������һ��������
//			{
//				printf("%d ", year);
//			}
//		}
//		if (year % 400 == 0)  // ÿ400������һ��
//		{
//			printf("%d ", year);
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (( 0 == i % 4 && i % 100 != 0) || 0 == i % 400)
//		{
//			printf("%d\t", i);
//		}
//	}
//
//	return 0;
//}

/*
���Լ���������������й���Լ��������ߡ�
���ķ�ʽ�Ƚ϶࣬������١�շת�������������𷨡�Stein�㷨�㷨
�˴���Ҫ���ܣ�շת�����


˼·��
���ӣ�18��24�����Լ��
��һ�Σ�a = 18  b = 24  c = a%b = 18%24 = 18
	  ѭ���У�a = 24   b=18
�ڶ��Σ�a = 24   b = 18  c = a%b = 24%18 = 6
	  ѭ���У�a = 18   b = 6


�����Σ�a = 18   b = 6   c=a%b = 18%6 = 0
  ѭ������

��ʱb�е����ݼ�Ϊ�������е����Լ����
*/


//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	scanf("%d%d", &a, &b);
//
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d\n", b);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1; i < 100; i++)
//	{
//		if (0 == i % 3)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 8;
//	int c = 6;
//
//
//	if (a < b)
//	{
//		int tem = a;
//		a = b;
//		b = tem;
//	}
//
//	if (a < c)
//	{
//		int tem = a;
//		a = c;
//		c = tem;
//	}
//
//	if (b < c)
//	{
//		int tem = b;
//		b = c;
//		c = tem;
//	}
//
//	printf("%d %d %d",a,b,c);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ",i);
//	}
//
//	return 0;
//}