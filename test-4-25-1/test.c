#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

//�������
void AdjustDown(int* arr, int n, int parent)
{
	//*2��һ�������ӣ�*2�Ӷ������Һ���
	int Child = parent * 2 + 1;

	while (Child < n)
	{
		//ѡ������С�ĺ���
		if (arr[Child] < arr[Child + 1] && Child + 1 < n)
		{
			Child++;
		}

		//��˫�׽ڵ�Ƚϣ����˫�׽ڵ�С�ں��Ӿͽ���
		if (arr[Child] > arr[parent])
		{
			//�����ڵ�
			Swap(&arr[Child], &arr[parent]);

			//��ɽ��������ӳ�Ϊ����
			parent = Child;
			//�������µ�˫�׵ĺ��ӽ��бȽ�
			Child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//������
void heapSort(int* arr, int n)
{
	int i = 0;

	//���ѣ�n-1�ҵ���������һ��Ԫ�أ��ټ�һ��2�ҵ����Ԫ�ص�˫�ס��������ϰ�����Ѹ�ɴ��
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, n, i);
	}

	//ĩβ��Ԫ��
	int end = n - 1;

	while (end)
	{
		//�ѵ�һ��Ԫ���û���ĩβ�ģ��������͵��ˣ�ĩβ�ټ���������򣬾���һϵ�в������������ᵽ���棬�Դ������������
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);

		//ÿ��һ�Σ�ĩβ������һ��
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