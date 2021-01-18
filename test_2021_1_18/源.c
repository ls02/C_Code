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
//				printf("找到了，下标是：%d", mid);
//				break;
//			}
//	}
//
//	if (len > hen)
//	{
//		printf("没找到！\n");
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
//思路：
//1. 从上述表达式可以分析出
//   a. 该表达式主要由100项，基数项为正，偶数项为负
//2. 设置一个循环从1~100，给出表达式中的每一项：1.0/i, 注意此处不能使用1，否则结果全部为0
//	然后使用flag标记控制奇偶项，奇数项为正，偶数项为负
//	然后将所有的项相加即可
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
//		//判断year是否为闰年
//		if (year % 4 == 0)  // 如果year能够被4整除，year可能为闰年
//		{
//			if (year % 100 != 0) // 如果year不能内100整除，则一定是闰年
//			{
//				printf("%d ", year);
//			}
//		}
//		if (year % 400 == 0)  // 每400年再润一次
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
最大公约数：即两个数据中公共约数的最大者。
求解的方式比较多，暴力穷举、辗转相除法、更相减损法、Stein算法算法
此处主要介绍：辗转相除法


思路：
例子：18和24的最大公约数
第一次：a = 18  b = 24  c = a%b = 18%24 = 18
	  循环中：a = 24   b=18
第二次：a = 24   b = 18  c = a%b = 24%18 = 6
	  循环中：a = 18   b = 6


第三次：a = 18   b = 6   c=a%b = 18%6 = 0
  循环结束

此时b中的内容即为两个数中的最大公约数。
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