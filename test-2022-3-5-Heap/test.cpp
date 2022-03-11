#include <iostream>
#include "Heap.h"

void Swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;

	//调整这个堆
	while (child < n)
	{
		//选出较大的孩子
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			child++;
		}

		//如果孩子大于父节点就行进行交换
		if (arr[child] > arr[parent])
		{
			Swap(arr + child, arr + parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeadpSort(int* arr, int size)
{
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, size, i);
	}

	//先次大的
	int end = size - 1;
	while (end > 0)
	{
		Swap(arr, arr + end);
		AdjustDown(arr, end, 0);
		end--;
	}
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void Func(void)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			printf("%d*%d=%5d\t", i, j, i * j);
		}
		putchar('\n');
	}
}

int main()
{
	int arr1[] = { 3, 5, 7, 9, 1, 20, 50 };
	int size = sizeof(arr1) / sizeof(arr1[0]);
	//建堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr1, size, i);
	}

	Print(arr1, size);

	//ls::Heap h1(arr2, size);

	////Print(arr1, size);
	//h1.Print();
	////Func();

	//h1.Push(55);
	//h1.Print();
	//std::cout << h1.Top() << std::endl;
	//h1.Pop();
	//h1.Print();

	//std::cout << h1.Top() << std::endl;

	return 0;
}