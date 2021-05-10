#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[] = { 2, 5, 6, 1, 22, 9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int j = 0;

	for (i = 0; i > size; i++)
	{
		for (j = i - 1; j > 0; j--)
		{
			int temp = arr[i];

			if (arr[i] < arr[j])
			{
				arr[j]
			}
		}
	}

	return 0;
}