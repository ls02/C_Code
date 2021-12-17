#define _CRT_SECURE_NO_WARNINGS 1
#include "Srot.h"

void TestSort1()
{
	int arr[] = { 6, 1, 2 , 7 ,9 , 3, 4, 5 ,10, 8};
	//int arr[] = { 35, 6 ,2 ,1 ,7, 0, 22, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//InsertSort(arr, size);
	//Print(arr, size);

	//ShellSort(arr, size);
	//Print(arr, size);

	//SelectSort(arr, size);
	//Print(arr, size);

	//HeapSort(arr, size);
	//Print(arr, size);

	//BubbleSort(arr, size);
	//Print(arr, size);
	//QuickSort(arr, 0, size - 1);
	//Print(arr, size);

	//MergeSort(arr, size);
	//Print(arr, size);

	//MergeSortNonR(arr, size);
	//Print(arr, size);

	CountSort(arr, size);
	Print(arr, size);

}

void TestSort2()
{
	srand((size_t)time(0));
	int i = 0;
	int max = 100000;

	int* a1 = (int*)malloc(sizeof(int) * max);
	if (!a1)
	{
		exit(-1);
	}

	int* a2 = (int*)malloc(sizeof(int) * max);
	if (!a2)
	{
		exit(-1);
	}

	int* a3 = (int*)malloc(sizeof(int) * max);
	if (!a3)
	{
		exit(-1);
	}

	int* a4 = (int*)malloc(sizeof(int) * max);
	if (!a4)
	{
		exit(-1);
	}

	int* a5 = (int*)malloc(sizeof(int) * max);
	if (!a5)
	{
		exit(-1);
	}

	for (int i = 0; i < max; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a2[i];
		a4[i] = a3[i];
		a5[i] = a4[i];
		//a1[i] = i;
	}

	int head1 = clock();
	HeapSort(a1, max - 1);
	int end1 = clock();
	printf("HeapSort:%d\n", end1 - head1);

	int head2 = clock();
	QuickSort1(a2, 0, max - 1);
	int end2 = clock();
	printf("QuickSort1:%d\n", end2 - head2);

	int head3 = clock();
	MergeSort(a3, max);
	int end3 = clock();
	printf("MergeSort:%d\n", end3 - head3);

	int head4 = clock();
	MergeSortNonR(a4, max);
	int end4 = clock();
	printf("MergeSortNonR:%d\n",end4 - head4);

	int head5 = clock();
	CountSort(a5, max - 1);
	int end5 = clock();
	printf("CountSort:%d\n", end5 - head5);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
}

int* sortArray(int* a, int numsSize, int* returnSize) {
	int min = a[0];
	int max = a[0];
	int i = 0;

	for (i = 0; i < numsSize; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* countArray = (int*)malloc(sizeof(int) * range);
	if (!countArray)
	{
		exit(-1);
	}
	memset(countArray, 0, sizeof(int) * range);
	int Index = 0;

	for (i = 0; i < numsSize; i++)
	{
		countArray[a[i] - min]++;
	}

	for (i = 0; i < range; i++)
	{
		while (countArray[i]--)
		{
			a[Index++] = i + min;
		}
	}

	free(countArray);

	*returnSize = Index;

	return a;
}

void TestSort3()
{
	int arr[] = { 6, 1, 2 , 7 ,9 , 3, 4, 5 ,10, 8 };
	//int arr[] = { 35, 6 ,2 ,1 ,7, 0, 22, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int asize = 0;
	int* arr1 = sortArray(arr, size, &asize);

	for (int i = 0; i < asize; i++)
	{
		printf("%d ", arr1[i]);
	}

}


int main()
{
	TestSort3();

	return 0;
}