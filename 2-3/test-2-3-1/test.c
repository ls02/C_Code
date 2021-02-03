#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

void my_print1(int* arr, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void my_print2(char* arr, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
	putchar('\n');
}

int cmp(const void* e1, const void* e2)
{
	return *((char*)e2) - *((char*)e1);
}

typedef struct Student
{
	char name[20];
	int age;
}S;

int cmp2(const void* e1, const void* e2)
{
	return ((S*)e2)->name - ((S*)e1)->name;
}

void my_print3(S* arr, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%s ", (arr + i)->name);
	}
	putchar('\n');
}

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	char arr2[7] = "abcdef";
	S s1[] = { { "张三", 33 } , {"李四", 55}, {"王五", 22} };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	int sz3 = sizeof(s1) / sizeof(s1[0]);

	qsort(arr1, sz1, sizeof(arr1[0]), cmp);
	my_print1(arr1, sz1);
	qsort(arr2, sz2, sizeof(arr2[0]), cmp);
	my_print2(arr2, sz2);
	qsort(s1, sz3, sizeof(s1[0]), cmp2);
	my_print3(s1, sz3);

	return 0;
}

//void my_print(int* arr, int sz)
//{
//	int i = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	putchar('\n');
//}
//
//int compare(const void* elem1, const void* elem2)
//{
//	return *((char*)elem1) - *((char*)elem2);
//}
//
//void my_swop(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//
//	for (i = 0; i < width; i++)
//	{
//		int temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubbling_qsort(void* base, size_t num, size_t width, int(* compare)(const void* elem1, const void* elem2))
//{
//	size_t i = 0;
//	size_t j = 0;
//
//	for (i = 0; i < num - 1; i++)
//	{
//		for (j = 0; j < num - i - 1; j++)
//		{
//			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) < 0)
//			{
//				my_swop((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 9, 8, 2, 5, 6, 7, 3, 2, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubbling_qsort(arr, sz, sizeof(arr[0]),compare);
//
//	my_print(arr, sz);
//	return 0;
//}