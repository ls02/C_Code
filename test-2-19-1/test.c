#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#include <stdio.h>

#include <stdio.h>

void tets(int arr[3][5])//OK?
{}
void test(int arr[][])//OK?
{}
void test(int arr[][5])//OK?
{}

//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行有多少元素
//这样才方便运算

void test(int* arr)//OK?
{}
void test(int* arr[5])//OK?
{}
void test(int(*arr)[5])//OK?
{}
void test(int** arr)//OK?
{}

int main()
{
    int arr[3][5] = { 0 };

    test(arr);

    return 0;
}

//#include <stdio.h>
//
//void test(int arr[])//OK?
//{}
//void tees(int arr[10])//OK?
//{}
//void test(int* arr)//OK?
//{}
//void test2(int* arr[20])//OK?
//{}
//void test2(int** arr)//OK?
//{}
//
//int main()
//{
//    int arr[10] = { 0 };
//    int* arr2[20] = { 0 };
//
//    test(arr);
//    test2(arr2);
//
//    return 0;
//}

//void print(int(*p)[3], int col, int row)
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < col; i++)
//	{
//		for (j = 0; j < row; j++)
//		{
//			//printf("%d ", p[i][j]);
//			//printf("%d ", *(*(p + i) + j));
//			//printf("%d ", (*(p + i))[j]);
//			//printf("%d ", *(p[i] + j));
//			//以上全都等价，如果全部理解说明你已经掌握的差不多了
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][3] = { { 1, 2, 3 }, { 3, 4, 5 }, { 5, 6, 7 } };
//	
//	print(arr, 3, 3);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//整形数组
//	int(*p)[10] = &arr;//存放整形的数组指针，把arr的地址给了数组指针
//	//一般数组指针不是这样用的
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//
//	printf("arr=%p\n", arr);
//	printf("&arr=%p\n", &arr);
//	printf("-----------------------\n");
//	printf("arr+1=%p\n", arr + 1);
//	printf("&arr+1=%p\n", &arr + 1);
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int(*p)[10] = &arr;
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[0][i]);
//	}
//
//
//	return 0;
//}

//int main()
//{
//	char const* p = "hello world";
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "hello world";
//	char const* p1 = "hello world";
//	char const* p2 = "hello world";
//
//	if (arr1 == arr2)
//	{
//		printf("arr1 and arr2 are same\n");
//	}
//	else
//	{
//		printf("arr1 and arr2 are not same\n");
//	}
//
//	if (p1 == p2)
//	{
//		printf("p1 and p2 are same\n");
//	}
//	else
//	{
//		printf("p1 and p2 are not same\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 9;
//	float* pFloat = (float*)&a;
//
//	printf("a的值为:%d\n", a);
//	printf("*pFloat的值为:%f\n", *pFloat);
//
//	*pFloat = 9.0;
//
//	printf("a的值为:%d\n", a);
//	printf("*pFloat的值为:%f\n", *pFloat);
//
//	return 0;
//}

//int main()
//{
//	float a = 8.5;
//
//	//1000.1
//	//1.0001
//	//S=0,E=3,M=0001
//	//(-1)^0*1.0001*2^3
//	//3+127
//	//0 10000010 00010000000000000000000
//	//0100 0001 0000 1000 0000 0000 0000 0000
//	//41 08 00 00
//
//	//1001.0
//	//1.001
//	//S=0,E=3,M=1.001.
//	//0 10000010 00100000000000000000000
//
//	//0 00000001 00100000000000000000000
//	//1.001*10e3
//	//1001.0
//	//9
//
//	return 0;
//}