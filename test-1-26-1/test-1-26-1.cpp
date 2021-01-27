#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

//int Cola(int a)
//{
//	int n = 0;
//	n = a % 2;
//	if (a >= 1)
//	{
//
//		return a + Cola(a / 2) + n;
//	}
//
//	return a - 1;
//}
//
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//
//
//	scanf("%d", &money);
//
//	//方法1
//	total = money;
//	empty = money;
//	while (empty > 1)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}
//	printf("%d\n", total);
//
//}
//
//int main()
//{
//	int a = 20;
//
//	int sum = Cola(a);
//
//	printf("%d", sum);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//
//	scanf("%d", &n);
//
//	for (i = 1; i < n; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			printf(" ");
//		}
//
//		for (j = 0; j < i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	for (i = 1; i < n; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			printf(" ");
//		}
//		
//		for (j = 0; j < n - i - 1; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 0; i <= 99999; i++)
//	{
//		int tmep = i;
//		int count = 1;
//		int sum = 0;
//
//		while (tmep)
//		{
//			count++;
//			tmep = tmep / 100;
//		}
//
//		tmep = i;
//
//		while (tmep)
//		{
//			sum += pow(tmep % 10, count);
//			tmep /= 10;
//		}
//
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int n = 0;
//	int sum = 0;
//
//	scanf("%d %d", &a, &n);
//	sum = a;
//	while (n)
//	{
//		sum += 10 * a + 2;
//		n--;
//	}
//	printf("%d", sum);
//
//	return 0;
//}

//void contrary(char* str)
//{
//	char* left = str;
//	char* right = str + strlen(str) - 1;
//
//	while (left < right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	char str[101] = "0";
//
//	while (gets_s(str))
//	{
//		contrary(str);
//
//		puts(str);
//	}
//
//	return 0;
//}

//void my_printf(int* p, int number)
//{
//	int i = 0;
//
//	for (i = 0; i < number; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	my_printf(arr, 10);
//
//	return 0;
//}

//int the_une1(int a)//效率低，循环次数比2高
//{
//	int count = 0;
//	int i = 0;
//
//	for (i = 0; i < 32; i++)
//	{
//		if (((a >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//
//	return count;
//}
//
//int the_une2(int a)//效率高，循环次数比1少
//{
//	int count = 0;
//	
//	while (a)
//	{
//		count++;
//		a = a & (a - 1);
//	}
//
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//
//	scanf("%d", &a);
//	printf("%d",the_une2(a));
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//
//	scanf("%d", &a);
//
//	int i = 0;//00000000 00000000 00000000 00000001
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", ((a >> i) & i));
//	}
//
//	putchar('\n');
//
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (a >> i) & 1);
//	}
//
//	return 0;
//}

//int main()
//{
//    int a = 0;
//    int b = 0;
//    int count = 0;
//
//    scanf("%d %d", &a, &b);//求二进制里面有几个不同
//    int c = a ^ b;//异或出每个不同的二进制位
//    int i = 0;
//
//    for (i = 0; i < 32; i++)//循环三十二次
//    {
//        if ((( c >> i) & 1) == 1)//每循环i次遍历三十二个比特位，逻辑与只有两边真才为真，以此来判断a和b的二进制是否是不同；
//        {
//            count++;//如果相同就加一
//        }
//    }
//
//    printf("%d\n", count);
//
//    return 0;
//}

//int main()
//{
//	int a = 22;
//	int b = 33;
//
//	int c = a ^ b;
//	printf("%d\n", c);
//	 int k = c ^ b;
//	printf("%d\n", k);
//	int j = k ^ c;
//	printf("%d\n", j);
//
//	return 0;
//}