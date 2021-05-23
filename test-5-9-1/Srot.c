#define _CRT_SECURE_NO_WARNINGS 1
#include "Srot.h"

static void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// ��������
void InsertSort(int* a, int n)
{
	int i = 0;

	//ÿ�α�����Ҫ��������ĺ�һ��������n-1��ֹԽ�����
	for (i = 0; i < n - 1; i++)
	{
		//endǰ�������Ϊ�������
		int end = i;
		//��temp�嵽endǰ��,��end�����һ������Ϊ�Ǵ��������
		int temp = a[end + 1];

		//���end���ڵ���0����Ϊ���������ԱȽ�
		while (end >= 0)
		{
			//�������ţ�end����temp�͵�����ȥ
			if (temp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}

		//�ߵ����������������������temp�󣬻�endС��temp�Ͱ�temp�嵽end�����λ��
		a[end + 1] = temp;
	}
}

// ϣ������
void ShellSort(int* a, int n)
{
	int gap = n;

	//gap����1˵����Ԥ����׶Σ���gap����1�൱�ڲ�������
	//��gap��ֵԽ��˵������Ҫ�����Ĵ���Խ�ٲ��������˳�򲻻�ӽ�����
	//��gap��ֵԽС��˵������Ҫ�����Ĵ���Խ�ಢ�������˳��Խ��Խ�ӽ�����
	while (gap > 1)
	{
		//ÿ��gap������С����֮һ����һ�Ƿ�ֹgap����0
		gap = gap / 3 + 1;
		int i = 0;

		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];

			//��end>=0 ˵������ֵ���Խ���
			while (end >= 0)
			{
				//��tempС��end��end�Ͱ�ֵ���ǵ���end+gap��λ����
				if (temp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			//�ߵ�ֻ�����ֿ��ܣ�temp����end��������������temp
			a[end + gap] = temp;
		}
	}
}

// ѡ������
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int i = 0;

	//���leftС��right˵����������Ҫ����
	while (left < right)
	{
		int maxIndex = left;
		int minIndex = left;

		for (i = left; i <= right; i++)
		{	
			//�ҳ����������������������±��maxIndex
			if (a[i] >= a[maxIndex])
			{
				maxIndex = i;
			}

			//�ҳ���С����������С�������±��minIndex
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}

		//�������������ţ�leftӦ�÷���С������minIndex����С������left����
		Swap(&a[left], &a[minIndex]);
		//�ж�left��maxIndex�Ƿ��ص�����Ϊ�ص�����С�ĺ�left������ʱ��maxindex���Ļ�����С�ģ�����С��֮ǰ������������ģ�������Ҫ����
		if (left == maxIndex)
		{
			//��ʱminIndex�ǽ������ģ�û����������С�Ķ��������߳�����ˣ���Ϊleft��maxIndex�ص��ˣ��������ǵ�����minIndex��maxIndex
			maxIndex = minIndex;
		}
		//������right�Ǵ����ģ����Ժ�maxIndex����
		Swap(&a[right], &a[maxIndex]);

		left++;
		right--;
	}
}

// ������
void AdjustDwon(int* a, int n, int root)//��������µ�����
{
	int Child = root * 2 + 1;

	//�������С��n˵�����ܼ�������
	while (Child < n)
	{
		//ѡ�����ĺ���
		if (Child + 1 < n && a[Child] < a[Child + 1])
		{
			Child++;
		}

		//������Ӵ��ڸ��ڵ�ͽ���
		if (a[root] < a[Child])
		{
			Swap(&a[root], &a[Child]);

			root = Child;
			Child = root * 2 + 1;
		}
		else//��������ھͽ���
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	int i = 0;

	//����
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;

	//�������ϵ���
	while (end > 0)
	{
		//������һ��Ԫ�غ͵�endԪ�أ��������ľ��ܵ������
		Swap(&a[0], &a[end]);
		//��Ϊ�����˶���������ݣ���ʱ�ĶѾͲ��Ǵ�����ˣ���ʱ���������µ��������ѱ�ɴ���ѣ���Ϊ���Ƕ����Ǹ��ڵ㣬���������������������Ǵ����
		//��Ϊ����Ĳ��������һ�������ľͲ��õ�����ֵ����endǰ��ģ����������ͷ�end,��end����0��ʱ�������������������
		AdjustDwon(a, end, 0);

		end--;
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}



//int GetMidIndex(int* a, int left, int right)
//{
//	int mid = (left + right) >> 1;
//	
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//	else //(a[left] > a[mid])
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return left;
//		}
//		else
//		{
//			return right;
//		}
//	}
//}

//����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	// left  mid  right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//int GetMidIndex(int* a, int begin, int end)
//{
//	int mid = begin + ((end - begin) >> 1);
//	if (a[begin] < a[mid])
//	{
//		if (a[mid] < a[end])
//		{
//			return mid;
//		}
//		else if (a[begin] > a[end])
//		{
//			return begin;
//		}
//		else
//		{
//			return end;
//		}
//	}
//	else // begin >= mid
//	{
//		if (a[mid] > a[end])
//		{
//			return mid;
//		}
//		else if (a[begin] < a[end])
//		{
//			return begin;
//		}
//		else
//		{
//			return end;
//		}
//	}
//
//}


int PartSort1(int* a, int left, int right)
{
	int MidIdex = GetMidIndex(a, left, right);
	Swap(&a[MidIdex], &a[left]);

	//ȡ��һ��Ԫ����Ϊ�ο�ֵ
	int keyi = left;
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		// �Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);


	return left;
}

//��������
//void QuickSort(int* a, int begin, int end)
//{
//	//��begin��end�൱˵��ֻ��һ��������ֻ��һ������������ģ��Ͳ���Ҫ����
//	if (begin >= end)
//	{
//		return;
//	}
//
//	int left = begin;
//	int right = end;
//	int keyi = left;
//
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			right--;
//		}
//
//		while (left < right && a[left] <= a[keyi])
//		{
//			left++;
//		}
//
//		Swap(&a[left], &a[right]);
//	}
//
//	int meeti = left;
//
//	Swap(&a[keyi], &a[meeti]);
//
//	//���ߵ���һ�����Ȱ�left���С��keyi��Ԫ�أ�����һ���µ����飬��������
//	QuickSort(a, begin, meeti - 1);
//	//���ߵ���һ�����Ȱ�left�ұߴ���keyi��Ԫ��,����һ���µ����飬��������
//	QuickSort(a, meeti + 1, end);
//}

//void QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)
//		return;
//
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)
//	{
//		// ��С
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// �Ҵ�
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	int meeti = left;
//
//	Swap(&a[keyi], &a[meeti]);
//
//
//	// [begin, meeti-1] meeti [meeti+1, end]
//	QuickSort(a, begin, meeti - 1);
//	QuickSort(a, meeti+1, end);
//}

void Print(int* a, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int MidIdex = GetMidIndex(a, left, right);
	Swap(&a[MidIdex], &a[left]);

	int keyi = a[left];

	while (left < right)
	{
		//��С
		while (left < right && a[right] >= keyi)
		{
			right--;
		}
		Swap(&a[left], &a[right]);

		//�Ҵ�
		while (left < right && a[left] <= keyi)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &keyi);

	return left;
}


//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = keyi;
	int cur = keyi + 1;

	while (cur <= right)
	{
		//��С
		if (a[cur] < a[keyi] && a[prev++] != a[cur])
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}

	//���м�ֵ����
	Swap(&a[prev], &a[keyi]);

	return prev;
}

//��������
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;


	// [begin, meeti-1] meeti [meeti+1, end]

	//С�����Ż�
	if (end - begin > 10)
	{
		int keyi = PartSort3(a, begin, end);

		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
	}

}

//��������
void QuickSort1(int* a, int begin, int end)
{
	//����һ��ջ
	Stack st;
	//��ʼ��ջ
	StackInit(&st);
	//��ջ
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		//��ջ����Ϊ�Ƚ����������ջ����right
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//�������򣬲������м��±�
		int keyi = PartSort1(a, left, right);

		//���м�ֵ��ߵ������±��ջ
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		//���м�ֵ�ұߵ������±��ջ
		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}	
	}
}

void _MergeSort(int* a, int left, int right, int* temp)
{
	if (left >= right)
	{
		return;
	}
	
	int Mid = (left + right) >> 1;
	 
	//���ƶ������ĺ��򣬷ֽ⵽ֻ��һ���������俪ʼ�ϲ�
	_MergeSort(a, left, Mid, temp);
	_MergeSort(a, Mid + 1, right, temp);

	int begin1 = left;
	int begin2 = Mid + 1;
	int end1 = Mid;
	int end2 = right;
	int i = left;
	int j = left;

	//��һ����͵ڶ�����ϲ�
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else 
		{
			temp[i++] = a[begin2++];
		}
	}

	//����Ƿ���δ�ϲ�����
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//������ԭ����
	while (j <= right)
	{
		a[j] = temp[j];
		j++;
	}

	//memcpy(a + left, temp + left, sizeof(int) * (right - left + 1));
}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
	assert(a);
	int* temp = (int*)malloc(sizeof(int) * n);
	if (!temp)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	_MergeSort(a, 0, n - 1, temp);

	free(temp);
}

void _Merge(int* a, int* temp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	int j = begin1;

	//�鲢��������һ���鲢��ͽ���
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}

	//����Ƿ�����û�鲢
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//������ԭ����
	while (j < begin2)
	{
		a[j] = temp[j];
		j++;
	}
}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int* temp = (int*)malloc(sizeof(int) * n);
	if (!temp)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	//�鲢�ĸ���
	int gap = 1;

	while (gap < n)
	{
		int i = 0;

		//�ֳ���������
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int begin2 = i + gap;
			int end1 = i + gap - 1;
			int end2 = i + 2 * gap - 1; 

			//����ڶ��������n��Ȼ���ڣ��Ͳ�������
			if (begin2 >= n)
			{
				break;
			}

			//����ڶ������ĩβ����������
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//��������鲢
			_Merge(a, temp, begin1, end1, begin2, end2);
		}

		gap *= 2;
	}

	free(temp);
}

// ��������
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	int i = 0;

	//�ҳ�������С
	for (i = 0; i < n; i++)
	{
		if (a[i] < a[min])
		{
			min = a[i];
		}

		if (a[i] > a[max])
		{
			max = a[i];
		}
	}

	//�����ݷ�Χ
	int range = max - min + 1;
	int* countArray = (int*)malloc(sizeof(int) * range);
	if (!countArray)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	//�����ʼ��Ϊ0
	memset(countArray, 0, sizeof(int) * range);

	//ͳ�Ƹ������ֵĸ���
	for (i = 0; i < n; i++)
	{
		countArray[a[i] - min]++;
	}

	int index = 0;

	//��ͳ�ƺõĸ������������Ҫ���������
	for (i = 0; i < range; i++)
	{
		while (countArray[i]--)
		{
			a[index++] = i + min;
		}
	}

	free(countArray);
}

//void CountSort(int* a, int n)
//{
//	int max = a[0], min = a[0];
//	for (int i = 0; i < n; ++i)
//	{
//		if (a[i] > max)
//			max = a[i];
//
//		if (a[i] < min)
//			min = a[i];
//	}
//	//�ҵ����ݵķ�Χ
//	int range = max - min + 1;
//	int* countArray = (int*)malloc(range * sizeof(int));
//	if (!countArray)
//	{
//		printf("malloc fail\n");
//
//		exit(-1);
//	}
//
//	memset(countArray, 0, sizeof(int) * range);
//	//��������λ�ã����Խ�ʡ�ռ�
//	for (int i = 0; i < n; ++i)
//	{
//		countArray[a[i] - min]++;
//	}
//	//���ܴ����ظ������ݣ��м����漸��
//	int index = 0;
//	for (int i = 0; i < range; ++i)
//	{
//		while (countArray[i]--)
//		{
//			a[index++] = i + min;
//		}
//	}
//
//	free(countArray);
//}