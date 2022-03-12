#include <iostream>

void InsertionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//i+1后面的元素是待排序区间的元素插入有序的元素区间
		int temp = arr[i + 1];
		//前i个当成有序的
		int end = i;
		while (end >= 0)
		{
			//如果小于往后挪给插入元素腾出位置
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else//找到插入点前面都是有序的如果不等于说明该位置的后面那个就是插入点
			{
				break;
			}
		}

		//放到小于temp元素的后面
		arr[end + 1] = temp;
	}
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

int main()
{
	int arr[] = { 2, 3, 1, 0, 2, 5, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Print(arr, size);
	
	InsertionSort(arr, size);

	Print(arr, size);

	return 0;
}