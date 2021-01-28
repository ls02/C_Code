#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void excharnge(int* arr, int n)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] % 2 == 0 && arr[j + 1] % 2 != 0)
			{
				int timep = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = timep;
			}
		}

	}
}

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int timep = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < timep; i++)
	{
		scanf("%d", &arr[i]);
	}

	excharnge(arr,timep);

	for (i = 0; i < timep; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

//char* my_strcpy(char* arr1, const char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//
//	char* p = arr1;
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//
//	return p;
//}
//
//int main()
//{
//	char arr1[20];
//	char arr2[10] = "abcdef";
//
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}

	//char my_strlen(const char* arr)
	//{
	//	int count = 0;

	//	while (*arr++)
	//	{
	//		count++;
	//	}

	//	return count;
	//}

	//int main()
	//{
	//	int count = 0;
	//	char arr[20] = "abcdef";

	//	count = my_strlen(arr);

	//	printf("%d", count);

	//	return 0;
	//}

//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//
//}