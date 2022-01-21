#include <stdio.h>

int main()
{
	int arr[3][4] = { 0 };
	int i = 0;
	int j = 0;
	int arr2[3] = { 1, 2, 3 };
	int(*p2)[3] = &arr2;

	for (i = 0; i < 3; i++)
	{
		printf("%d ", *((*p2) + i));
	}

	printf("\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = i + j;
		}
	}

	int(*p1)[4] = arr;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p1 + i) + j));
		}

		printf("\n");
	}

	//int a = 10;
	//int* p1 = &a;
	//int* arr[4] = { 0 };

	//arr[0] = p1;

	//printf("%d", *(*arr));

	return 0;
}