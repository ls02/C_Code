#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//大堆排序
void AdjustDown(int* arr, int n, int parent)
{
	//*2加一就是左孩子，*2加二就是右孩子
	int Child = parent * 2 + 1;

	while (Child < n)
	{
		//选出左右小的孩子
		if (arr[Child] < arr[Child + 1] && Child + 1 < n)
		{
			Child++;
		}

		//和双亲节点比较，如果双亲节点小于孩子就结束
		if (arr[Child] > arr[parent])
		{
			//交换节点
			Swap(&arr[Child], &arr[parent]);

			//完成交换，孩子成为父亲
			parent = Child;
			//继续找新的双亲的孩子进行比较
			Child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//堆排序
void heapSort(int* arr, int n)
{
	int i = 0;

	//建堆，n-1找到数组的最后一个元素，再减一÷2找到这个元素的双亲。从下往上把这个堆搞成大堆
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}

	//末尾的元素
	int end = n - 1;

	while (end)
	{
		//把第一个元素置换到末尾的，最大的数就到了，末尾再继续大堆排序，经过一系列操作，最大的数会到后面，以此完成升序排序
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);

		//每排一次，末尾就少排一个
		end--;
	}
}


int main()
{
	int arr[] = { 27, 15, 19, 18, 28, 34, 65, 49, 26, 37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	heapSort(arr, size);

	while (i < size)
	{
		printf("%d ", arr[i]);

		i++;
	}

	return 0;
}