#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Stu
{
	char name[20];
	short age;
};

//int cmp(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
//}


int cmp(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void _swap(char* base1, char* base2, unsigned int width)
{
	unsigned int i = 0;

	for (i = 0; i < width; i++)
	{
		char temp = *base1;
		*base1 = *base2;
		*base2 = temp;
		base1++;
		base2++;
	}
}

void bubbling_qsrto(void* base, unsigned int sz, unsigned int width, int (*cmp)(const void* e1, const void* e2))
{
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}


int main()
{
	//int arr[] = { 1, 8, 3, 6, 2, 4, 9, 7, 5, 10 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	struct Stu arr[3] = { "zhangsan", 15, "lisi", 24, "wangwu", 22 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	bubbling_qsrto(arr, sz, sizeof(arr[0]), cmp);

	for (i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i].age);
	}

	return 0;
}