#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap_array(int*const arr1, int*const arr2, int extent)
{
	int i = 0;
	int tem = 0;

	for (i = 0; i < extent; i++)
	{
		tem = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tem;
	}
}

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		printf("arr1[%d]=%d ", i, arr1[i]);
	}

	putchar('\n');

	for (i = 0; i < 10; i++)
	{
		printf("arr2[%d]=%d ", i, arr2[i]);
	}

	putchar('\n');

	Swap_array(arr1, arr2, 10);
	
	for (i = 0; i < 10; i++)
	{
		printf("arr1[%d]=%d ", i, arr1[i]);
	}

	putchar('\n');

	for (i = 0; i < 10; i++)
	{
		printf("arr2[%d]=%d ", i, arr2[i]);
	}

	return 0;
}

//void reverse(int* arr, int extent)//ÄæÖÃ
//{
//	int first = 0;
//	int end = --extent;
//
//	while (first < end)
//	{
//		int tem = arr[first];
//		arr[first] = arr[end];
//		arr[end] = tem;
//
//		first++;
//		end--;
//	}
//}
//
//void init(int* arr, int extent)//³õÊ¼»¯
//{
//	int i = 0;
//
//	for (i = 0; i < extent; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int* arr, int extent)//´òÓ¡
//{
//	int i = 0;
//
//	for (i = 0; i < extent; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	putchar('\n');
//
//}
//
//int main()
//{
//	int arr[9];
//	int i = 0;
//
//	init(arr,9);
//	for (i = 0; i < 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	print(arr, 9);
//	reverse(arr, 9);
//	print(arr, 9);
//
//	
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//
//	for (i = 0; i < 10-1; i++)
//	{
//		for (j = 0; j < 10 - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tem = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tem;
//			}
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 2;
//	int b = 3;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };
//	int* p = arr;
//
//	int k;
//	k = (b,++b);
//	printf("%d\n", sizeof(&arr));
//	printf("%p\n", &arr);
//	printf("%p\n", arr);
//	printf("%d %d\n", k,b);
//
//	return 0;
//}