#include <iostream>

void InsertionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//i+1�����Ԫ���Ǵ����������Ԫ�ز��������Ԫ������
		int temp = arr[i + 1];
		//ǰi�����������
		int end = i;
		while (end >= 0)
		{
			//���С������Ų������Ԫ���ڳ�λ��
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else//�ҵ������ǰ�涼����������������˵����λ�õĺ����Ǹ����ǲ����
			{
				break;
			}
		}

		//�ŵ�С��tempԪ�صĺ���
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