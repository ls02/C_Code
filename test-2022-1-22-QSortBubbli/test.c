#include "QSortBubbli.h"
#include <time.h>
#include <stdlib.h>

//提供给快排的比较函数，如果想调整排序的升序和降序，只需在自己提供的比较函数内修改
int CompInt(const int* p1, const int* p2)
{
	return *p1 - *p2;
}


void Print(int* arr, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main()
{
	srand((size_t)time(0));
	int i = 0;
	int arr[10] = { 1, 2, 4, 11, 20, 6, 9, 12, 88, 100 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < sz; i++)
	{
		arr[i] = rand();
	}

	Print(arr, sz);

	QSortBubbli((void*)arr, sz, sizeof(arr[0]), CompInt);

	Print(arr, sz);


	return 0;
}