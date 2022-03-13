#include <iostream>

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];

			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			arr[end + gap] = temp;
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 1, 0 ,10 , 22, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, size);

	for (auto e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	return 0;
}