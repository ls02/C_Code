#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

//����d
namespace ls
{
	//ֱ�Ӳ�������
	void InsertionSort(int* arr, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int end = i;
			int temp = arr[end + 1];
			while (end >= 0)
			{
				if (arr[end] > temp)
				{
					arr[end + 1] = arr[end];
					end--;
				}
				else
				{
					break;
				}
			}

			arr[end + 1] = temp;
		}
	}

	//ϣ������
	void ShellSort(int* arr, int n)
	{
		int gap = n;
		//gap��2����ʱ��Ԥ���򣬵�gapΪ2���ǲ�������
		while (gap > 1)
		{
			//�ֳ�3�ݣ�����3���ܻ���0�Ӷ����ᵼ���޷��������һ�εĲ����������Ի����+1
			gap = gap / 3 + 1;

			for (int i = 0; i < n - gap; i++)
			{
				int end = i;
				int temp = arr[end + gap];
				//��С������Ų
				while (end >= 0)
				{
					if (arr[end] > temp)
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else//�����Ѿ�������������
					{
						break;
					}
				}

				//�����ҵ�����λ��ʱ��ΪҪ������ѭ���������Իᷢ��������ʱ��λ�ò���������Ҫ����ĵ�λ����Ҫ+gapλ����ԭ���ҵ��ĵ�λ
				arr[end + gap] = temp;
			}
		}
	}

	//ð������
	void BubbleSort(int* arr, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int flags = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] > arr[j])
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					flags = 0;
				}
			}

			if (flags)
			{
				break;
			}
		}
	}

	//���������С�����Ż�
	int GetMindex(int* arr, int left, int right)
	{
		//ȡ���м�ֵ
		int midIndex = (left + right) >> 1;

		if (arr[left] > arr[right])
		{
			if (arr[left] < arr[midIndex])
			{
				return left;
			}
			else if (arr[right] > arr[midIndex])
			{
				return right;
			}
			else
			{
				return midIndex;
			}
		}
		else
		{
			if (arr[right] < arr[midIndex])
			{
				return right;
			}
			else if (arr[midIndex] > arr[left])
			{
				return midIndex;
			}
			else
			{
				return left;
			}
		}
	}

	//����ָ������
	int PartSort1(int* arr, int left, int right)
	{
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int key = left;
		while (left < right)
		{
			//left��key,����right������С��key���±�
			while (left < right && arr[key] <= arr[right])
			{
				right--;
			}

			//�Ҵ���key���±�
			while (left < right && arr[key] >= arr[left])
			{
				left++;
			}

			swap(arr[left], arr[right]);
		}

		//����keyֵ
		swap(arr[left], arr[key]);
		key = left;

		return key;
	}

	//�ڿӷ�
	int PartSort2(int* arr, int left, int right)
	{
		//С�����Ż�
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int key = arr[left];
		while (left < right)
		{
			//��С
			while (left < right && arr[right] >= key)
			{
				--right;
			}

			//�ҵ���λ���γɿ�
			arr[left] = arr[right];

			//�Ҵ�
			while (left < right && arr[left] <= key)
			{
				++left;
			}

			//��ǰ��Ŀӣ��Լ�λ�����γɿ�
			arr[right] = arr[left];
		}

		//������ʱ��λ����һ���ӣ��ѱ����key��ÿ�
		arr[left] = key;

		return left;
	}

	//ǰ��ָ�뷨
	int PartSort3(int* arr, int left, int right)
	{
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int keyI = left;
		int cur = left + 1;
		int prev = left;
		//������������
		while (cur <= right)
		{
			//���curС�ھͺ�prev������Ϊ�˷�ֹ�Լ����Լ��������Լ���!=����ж�
			if (arr[cur] < arr[keyI] && ++prev != cur)
			{
				swap(arr[prev], arr[cur]);
			}
			//cur������û�н�����Ҫ���е�����Ȼ����ѭ��
			++cur;
		}

		//������keyֵ�ٺ�prev����
		swap(arr[keyI], arr[prev]);

		//prev�ǵ�ǰλ�õ���������м�ֵ���������ȫ�Ǳ���С�ģ������ұ�ȫ�Ǳ������
		return prev;
	}
	
	//�������򡪡��ݹ�ʵ��
	void QuickSortRe(int* arr, int begin, int end)
	{
		//ֱ������Ϊ1˵���������޷��������������������
		if (begin >= end)
		{
			return;
		}
		
		//С�����Ż��������������������ֱ��ʹ�ò�������
		if (end - begin > 20)
		{
			//��keyֵ�ŵ��м��γ�key��ߵ�ֵС��key���ұߵ�ֵȫ������key����key�����������
			int keyI = PartSort2(arr, begin, end);

			//��key��ߵ�����������
			QuickSortRe(arr, begin, keyI - 1);
			//��key���ұ�������
			QuickSortRe(arr, keyI + 1, end);
		}
		else
		{
			//��ʱ����ȫ����ֱ�Ӳ������򣬾���������ʹ�ò�������Ӷ�ʹ��Ч�ʴ��������
			InsertionSort(arr + begin, end - begin + 1);
		}
	}


	void QuickSort1(int* a, int begin, int end)
	{
		if (begin >= end)
			return;

		// 1�������������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
		// 2�������������������ݽ�С����ȥ���εݹ鲻̫����
		if (end - begin > 20)
		{
			int keyi = PartSort2(a, begin, end);

			// [begin, keyi-1] keyi [keyi+1, end]
			QuickSort1(a, begin, keyi - 1);
			QuickSort1(a, keyi + 1, end);
		}
		else
		{
			//HeapSort(a + begin, end - begin + 1);
			InsertionSort(a + begin, end - begin + 1);
		}
	}

	//�������򡪡��ݹ�ʵ��
	void QuickSort(int* arr, int begin, int end)
	{
		stack<int> st;
		st.push(begin);
		st.push(end);

		//ֱ���������䶼�����Ϊֹ
		while (!st.empty())
		{
			//��ȡ��������
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();

			//�Ը��������򲢷������������λ��
			int keyI = PartSort2(arr, left, right);

			//����������
			if (left < keyI - 1)
			{
				st.push(left);
				st.push(keyI - 1);
			}

			//����������
			if (keyI + 1 < right)
			{
				st.push(keyI + 1);
				st.push(right);
			}
		}
	}

	//���µ����㷨
	void AdjustDown(int* arr, int n, int parent)
	{
		int child = parent * 2 + 1;

		//������ӻ��Ǵ��ڸ��ڵ㣬��ô����Ҫ��������ֱ������
		while (child < n)
		{
			//���������Ҫѡ�����ĺ���
			if (child + 1 < n && arr[child + 1] > arr[child])
			{
				child++;
			}

			//������Ӵ��ڸ��ڵ�˵���öѲ��Ǵ���ѣ���Ҫ�������������С��˵���Ǵ���Ѳ���Ҫ����ֱ����
			if (arr[child] > arr[parent])
			{
				swap(arr[child], arr[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	//������
	void HeapSort(int* arr, int n)
	{
		//�����һ�����ڵ㿪ʼ����
		for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		{
			//����
			AdjustDown(arr, n, i);
		}

		int end = n - 1;
		while (end >= 0)
		{
			//�ѶѶ��������Ƶ����һ�����������������һ�����ݾ���������
			swap(arr[end], arr[0]);
			//��ʱ�������������½��ѣ����һ�����ݲ��Ž����ÿ�α��ӶѶ������������ݾͲ����ٷŽ�����
			AdjustDown(arr, end, 0);
			end--;
		}
	}

	//ѡ������
	void SelectionSort(int* arr, int n)
	{
		int left = 0;
		int right = n - 1;
		while (left < right)
		{
			int minIndex = left;
			int maxIndex = left;
			//ѡ�������������ĺ���С��ֵ
			for (int i = left; i <= right; i++)
			{
				if (arr[minIndex] > arr[i])
				{
					minIndex = i;
				}

				if (arr[maxIndex] < arr[i])
				{
					maxIndex = i;
				}
			}

			//��С��ֵ�������
			swap(arr[left], arr[minIndex]);
			//�������Ƿ������ֵ�������Ҫ�����µ�ǰ���ֵ���±꣬�����µĻ���ǰ���ֵ���������ֵ������Сֵ
			if (left == maxIndex)
			{
				maxIndex = minIndex;
			}

			//������ֵ�������ұ�
			swap(arr[maxIndex], arr[right]);
			right--;
			left++;
		}
	}

	void _MergeSortRe(int* arr, int left, int right, int* temp)
	{
		if (left >= right)
		{
			return;
		}

		//�ֳ���������
		int midIndex = (left + right) >> 1;
		//������������
		_MergeSortRe(arr, left, midIndex, temp);
		//������������
		_MergeSortRe(arr, midIndex + 1, right, temp);

		//�������������������֮���ٶ���������������ô������������������
		int begin1 = left, end1 = midIndex;
		int begin2 = midIndex + 1, end2 = right;
		int i = left;
		//��һ����������Ͳ��ñȽ��ˣ�ֱ��������ȥ
		while (begin1 <= end1 && begin2 <= end2)
		{
			//�ҽ�С��ֵ�ŵ���ʱ������
			if (arr[begin1] > arr[begin2])
			{
				temp[i++] = arr[begin2++];
			}
			else
			{
				temp[i++] = arr[begin1++];
			}
		}
		
		//������������Ƿ�ȫ��������ʱ������
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}

		//����������俽����ԭ������
		for (int j = left; j <= right; j++)
		{
			arr[j] = temp[j];
		}
	}

	//�鲢����-�ݹ�ʵ��
	void MergeSortRe(int* arr, int n)
	{
		int* temp = new int[n];
		_MergeSortRe(arr, 0, n - 1, temp);
		delete[] temp;
	}

	void _MergeSort(int* arr, int begin1, int end1, int begin2, int end2, int* temp)
	{
		int i = begin1;
		int j = begin1;

		//��һ�����������ֹͣ��һ������������һ�������Ѿ���������ˣ�û��Ҫ�����Ƚ�
		while (begin1 <= end1 && begin2 <= end2)
		{
			//����������бȽϰѽ�С��ֵ�ŵ���ʱ������
			if (arr[begin1] > arr[begin2])
			{
				temp[i++] = arr[begin2++];
			}
			else
			{
				temp[i++] = arr[begin1++];
			}
		}

		//������������м�鿴��һ����û�����
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}

		//����ʱ��������������俽����ԭ�������䡣
		for (; j <= end2; j++)
		{
			arr[j] = temp[j];
		}
	}

	//�鲢����-����ʵ��
	void MergeSort(int* arr, int n)
	{
		int gap = 1;
		int* temp = new int[n];
		while (gap < n)
		{
			for (int i = 0; i < n; i += 2 * gap)
			{
				int begin1 = i, end1 = i + gap - 1;
				int begin2 = i + gap, end2 = i + 2 * gap - 1;

				//���������䲻����������ô��û��Ҫ������
				if (begin2 >= n)
				{
					break;
				}
				
				//����ұ߲�����������Ҫ���������ǽ���ǰ��������λ�á�
				if (end2 >= n)
				{
					end2 = n - 1;
				}
				
				//�Ը������������
				_MergeSort(arr, begin1, end1, begin2, end2, temp);
			}

			//����һ������
			gap *= 2;
		}

		delete[] temp;
	}

	//��������
	void CountSort(int* arr, int n)
	{
		int maxIndex = arr[0];
		int minIndex = arr[0];
		//ѡ��������Сֵ
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > maxIndex)
			{
				maxIndex = arr[i];
			}
			
			if (arr[i] < minIndex)
			{
				minIndex = arr[i];
			}
		}

		//�������ֵ�Ŀռ�
		int range = maxIndex - minIndex + 1;
		int* temp = new int[range];
		//��ʼ��
		memset(temp, 0, sizeof(int) * range);

		//����ӳ��
		for (int i = 0; i < n; i++)
		{
			temp[arr[i] - minIndex]++;
		}

		//ȡ��ӳ���ֵ
		int j = 0;
		for (int i = 0; i < range; i++)
		{
			while (temp[i]--)
			{
				arr[j++] = i + minIndex;
			}
		}

		delete[] temp;
	}
}

void Print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << arr[i] << " ";
	}
	putchar('\n');
}

void TestSort1()
{
	int arr[] = { 2, 2, 2, 2, 2, 2, 2, 2 };
	//int arr[] = { 3, 5, 1, 4, 7, 2, 9, 6 };
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	//ls::InsertionSort(arr, sz);
	//ls::ShellSort(arr, sz);
	//ls::BubbleSort(arr, sz);
	//ls::BubbleSort(arr1, 8);
	//ls::QuickSort(arr, 0, sz - 1);
	//ls::QuickSort(arr, 0, sz - 1);
	//ls::QuickSort(arr1, 0, sz - 1);
	//ls::HeapSort(arr, sz);
	//ls::SelectionSort(arr, sz);
	//ls::MergeSort(arr, sz);
	ls::CountSort(arr, sz);
	Print(arr, sz);
	//Print(arr1, 8);
}

#define N 100000

void TestSort2(void)
{
	int* arr1 = new int[N];
	int* arr2 = new int[N];
	int* arr3 = new int[N];
	int* arr4 = new int[N];
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back(arr4[i] = arr3[i] = arr2[i] = arr1[i] = rand());
	}

	int begin1 = clock();
	ls::QuickSort(arr1, 0, N - 1);
	int end1 = clock();


	int begin2 = clock();
	ls::QuickSortRe(arr2, 0, N - 1);
	int end2 = clock();

	int begin3 = clock();
	ls::QuickSortRe(arr3, 0, N - 1);
	int end3 = clock();

	int begin4 = clock();
	sort(v.begin(), v.end());
	int end4 = clock();

	int begin5 = clock();
	ls::QuickSort1(arr4, 0, N - 1);
	int end5 = clock();

	printf("QuickSort��%d\n", end1 - begin1);
	printf("QuickSortRe��%d\n", end2 - begin2);
	printf("HeapSort��%d\n", end3 - begin3);
	printf("sort��%d\n", end4 - begin4);
	printf("QuickSort1��%d\n", end5 - begin5);
}

int main()
{
	srand((size_t)time(nullptr));
	TestSort2();
	TestSort1();

	return 0;
}