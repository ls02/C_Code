#include <stdio.h>
#define ROW 4
#define COL 4
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1

void Triangle()
{
	int arr[ROW][COL] = { 0 };
	int i = 0;

	for (i = 0; i < ROW; i++)
	{
		int j = 0;
		
		for (j = 0; j < COL; j++)
		{

			if (0 == j || i == j)
			{
				arr[i][j] = 1;
			}
			else
			{
				if (i >= 0 && j >= 0)
				{
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				}
			}
		}
	}

	for (i = 0; i < ROW; i++)
	{
		int j = 0;

		for (j = COL; j > i; j--)
		{
			printf(" ");
		}

		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}
}


int main()
{
	Triangle();

	return 0;
}