#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <math.h>

int Fibonacci(int n)
{
	if (n > 2)
	{
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}

	return 1;
}

int main()
{
	int n;

	while (1)
	{
		scanf("%d", &n);

		int sum = Fibonacci(n);
		printf("%d\n", sum);
	}

	return 0;
}

//int factorial(int n, int k)
//{
//	if (k >= 1)
//	{
//		return n * factorial(n,k - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//
//	scanf("%d %d",&n,&k);
//
//	int sum = factorial(n, k);
//	printf("%d", sum);
//
//	return 0;
//}

//int DigitSum(unsigned int a)
//{
//	int tem = 0;
//	tem = a % 10;
//	if (a > 9)
//	{
//
//		return tem + DigitSum(a / 10);
//	}
//
//	return a;
//}
//
//int main()
//{
//	unsigned int a = 0;
//
//	scanf("%d", &a);
//
//	int n = DigitSum(a);
//	printf("%d", n);
//
//	return 0;
//}

//void reverse_string(char* arr)
//{
//	int len = strlen(arr);
//	char tmp = *arr;
//	*arr = *(arr+len-1);
// 
//	*(arr+len-1) = '\0';
//	if(strlen(arr+1)>=2)
//		reverse_string(arr+1);
// 
//	*(arr+len-1) = tmp;
//}
//
//void reverse_string1(char* arr)
//{
//	char* left = arr;
//	char* right = arr + strlen(arr) - 1;
//
//	while (left < right)
//	{
//		char tem = *left;
//		*left = *right;
//		*right = tem;
//
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	char string[] = "abcdef";
//
//	reverse_string(string);
//	
//	puts(string);
//	
//	return 0;
//}

//int pesrsonal_strlen2(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + pesrsonal_strlen2(1 + arr);
//	}
//
//}
	
//int pesrsonal_strlen1(char* arr)//非递归
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	
//	return count;
//}

//int main()
//{
//	char arr[20] = "abcdefg";
//	
//	printf("%d", pesrsonal_strlen2(arr));
//
//	return 0;
//}

//int factorial2(int a)
//{
//	int i = 0;
//	int sum = 1;
//	
//	for (i = 2; i <= a; i++)
//	{
//		sum *= i;
//	}
//
//	return sum;
//}

//int factorial1(int a)
//{
//	if (a <= 1)
//	{
//		return 1;
//	}
//
//	return (a * factorial(a - 1));
//}

//int main()
//{
//	int a = 0;
//	
//	scanf("%d", &a);
//	int sum = factorial2(a);
//	printf("%d",sum);
//
//	return 0;
//}

//void the_unit(int a)
//{
//
//	if (a > 9)
//	{
//		printf("%d", a / 10);
//		printf("%d", a % 10);
//	}
//
//	return;
//}
//
//int main()
//{
//	int a = 0;
//
//	scanf("%d", &a);
//	the_unit(a);
//
//	return 0;
//}

//void external(int x)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%-2d*%-2d=%-3d ", i, j, i * j);
//		}
//		putchar('\n');
//	}
//}
//
//
//int main()
//{
//	int i = 0;
//
//	scanf("%d", &i);
//
//	external(i);
//
//
//	return 0;
//}

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