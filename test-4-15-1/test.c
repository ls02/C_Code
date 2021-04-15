#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[5] = { 1, 5, 7, 8 ,3 };
	int i = 0;
	int j = 0;

	//两个元素两两交换，按升序排，小的在左边，大的在右边
	for (i = 0; i < 5 - 1; i++)
	{
		for (j = 0; j < 5 - i - 1; j++)
		{
			//比较第j个元素大还是j+1个元素大，如果第j个元素大就交换
			if (arr[j] > arr[j + 1])
			{
				//创建一个临时变量保存j + 1个元素
				int temp = arr[j + 1];
				//把大于的跟j + 1交换
				arr[j + 1] = arr[j];
				//把temp保存的数据给第j个元素
				arr[j] = temp;
			}
		}
	}
	//以上才是冒牌排序的代码
	
	//-----------------------------------------------------

	//以下是打印
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}