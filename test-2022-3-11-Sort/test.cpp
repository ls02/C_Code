#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

//排序d
namespace ls
{
	//直接插入排序
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

	//希尔排序
	void ShellSort(int* arr, int n)
	{
		int gap = n;
		//gap是2以上时是预排序，当gap为2就是插入排序
		while (gap > 1)
		{
			//分成3份，由于3可能会商0从而不会导致无法进行最后一次的插入排序，所以会进行+1
			gap = gap / 3 + 1;

			for (int i = 0; i < n - gap; i++)
			{
				int end = i;
				int temp = arr[end + gap];
				//把小的往左挪
				while (end >= 0)
				{
					if (arr[end] > temp)
					{
						arr[end + gap] = arr[end];
						end -= gap;
					}
					else//区间已经有序无需再找
					{
						break;
					}
				}

				//由于找到合适位置时因为要不满足循环条件所以会发生减，这时该位置不是我们想要插入的点位，需要+gap位才是原理找到的点位
				arr[end + gap] = temp;
			}
		}
	}

	//冒泡排序
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

	//快速排序的小区间优化
	int GetMindex(int* arr, int left, int right)
	{
		//取得中间值
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

	//左右指针排序
	int PartSort1(int* arr, int left, int right)
	{
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int key = left;
		while (left < right)
		{
			//left做key,先走right，右找小于key的下标
			while (left < right && arr[key] <= arr[right])
			{
				right--;
			}

			//找大于key的下标
			while (left < right && arr[key] >= arr[left])
			{
				left++;
			}

			swap(arr[left], arr[right]);
		}

		//交换key值
		swap(arr[left], arr[key]);
		key = left;

		return key;
	}

	//挖坑法
	int PartSort2(int* arr, int left, int right)
	{
		//小区间优化
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int key = arr[left];
		while (left < right)
		{
			//找小
			while (left < right && arr[right] >= key)
			{
				--right;
			}

			//找到的位置形成坑
			arr[left] = arr[right];

			//找大
			while (left < right && arr[left] <= key)
			{
				++left;
			}

			//填前面的坑，自己位置再形成坑
			arr[right] = arr[left];
		}

		//当结束时此位置是一个坑，把保存的key填到该坑
		arr[left] = key;

		return left;
	}

	//前后指针法
	int PartSort3(int* arr, int left, int right)
	{
		int midIndex = GetMindex(arr, left, right);
		swap(arr[midIndex], arr[left]);
		int keyI = left;
		int cur = left + 1;
		int prev = left;
		//遍历整个区间
		while (cur <= right)
		{
			//如果cur小于就和prev交换，为了防止自己和自己交换所以加了!=这个判断
			if (arr[cur] < arr[keyI] && ++prev != cur)
			{
				swap(arr[prev], arr[cur]);
			}
			//cur不管有没有交换都要进行迭代不然会死循环
			++cur;
		}

		//最后出来key值再和prev交换
		swap(arr[keyI], arr[prev]);

		//prev是当前位置的相对有序中间值，它的左边全是比它小的，它的右边全是比它大的
		return prev;
	}
	
	//快速排序——递归实现
	void QuickSortRe(int* arr, int begin, int end)
	{
		//直到区间为1说明该区间无法继续排了且是有序的了
		if (begin >= end)
		{
			return;
		}
		
		//小区间优化，如果待排序数量很少直接使用插入排序
		if (end - begin > 20)
		{
			//把key值排到中间形成key左边的值小于key，右边的值全部大于key这样key就是有序的了
			int keyI = PartSort2(arr, begin, end);

			//把key左边的区间再排序
			QuickSortRe(arr, begin, keyI - 1);
			//把key的右边再排序
			QuickSortRe(arr, keyI + 1, end);
		}
		else
		{
			//这时候不用全部用直接插入排序，就整个区间使用插入排序从而使得效率大幅度提升
			InsertionSort(arr + begin, end - begin + 1);
		}
	}


	void QuickSort1(int* a, int begin, int end)
	{
		if (begin >= end)
			return;

		// 1、如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
		// 2、如果这个子区间是数据较小，再去分治递归不太划算
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

	//快速排序——递归实现
	void QuickSort(int* arr, int begin, int end)
	{
		stack<int> st;
		st.push(begin);
		st.push(end);

		//直到所有区间都排序好为止
		while (!st.empty())
		{
			//获取区间坐标
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();

			//对该区间排序并返回左右区间的位置
			int keyI = PartSort2(arr, left, right);

			//先入左区间
			if (left < keyI - 1)
			{
				st.push(left);
				st.push(keyI - 1);
			}

			//再如右区间
			if (keyI + 1 < right)
			{
				st.push(keyI + 1);
				st.push(right);
			}
		}
	}

	//向下调整算法
	void AdjustDown(int* arr, int n, int parent)
	{
		int child = parent * 2 + 1;

		//如果孩子还是大于父节点，那么还需要继续调整直到满足
		while (child < n)
		{
			//建大堆所以要选出最大的孩子
			if (child + 1 < n && arr[child + 1] > arr[child])
			{
				child++;
			}

			//如果孩子大于父节点说明该堆不是大根堆，需要调整，如果孩子小于说明是大根堆不需要调整直接跳
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

	//堆排序
	void HeapSort(int* arr, int n)
	{
		//从最后一个父节点开始建堆
		for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		{
			//建堆
			AdjustDown(arr, n, i);
		}

		int end = n - 1;
		while (end >= 0)
		{
			//把堆顶的数据推到最后一个，这样该数组最后一个数据就是最大的了
			swap(arr[end], arr[0]);
			//这时对其它数据重新建堆，最后一个数据不放进堆里，每次被从堆顶换下来的数据就不能再放进堆里
			AdjustDown(arr, end, 0);
			end--;
		}
	}

	//选择排序
	void SelectionSort(int* arr, int n)
	{
		int left = 0;
		int right = n - 1;
		while (left < right)
		{
			int minIndex = left;
			int maxIndex = left;
			//选出整个数组最大的和最小的值
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

			//最小的值换到左边
			swap(arr[left], arr[minIndex]);
			//检查左边是否是最大值，如果是要更新下当前最大值的下标，不更新的话当前最大值并不是最大值而是最小值
			if (left == maxIndex)
			{
				maxIndex = minIndex;
			}

			//把最大的值换到最右边
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

		//分出两个区间
		int midIndex = (left + right) >> 1;
		//对左区间排序
		_MergeSortRe(arr, left, midIndex, temp);
		//对右区间排序
		_MergeSortRe(arr, midIndex + 1, right, temp);

		//当左区间和有区间有序之后再对整个数组排序，那么整个数组就是有序的了
		int begin1 = left, end1 = midIndex;
		int begin2 = midIndex + 1, end2 = right;
		int i = left;
		//当一方区间结束就不用比较了，直接链接上去
		while (begin1 <= end1 && begin2 <= end2)
		{
			//找较小的值放到临时数组里
			if (arr[begin1] > arr[begin2])
			{
				temp[i++] = arr[begin2++];
			}
			else
			{
				temp[i++] = arr[begin1++];
			}
		}
		
		//检查左右区间是否全部放入临时数组内
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}

		//把有序的区间拷贝到原数组内
		for (int j = left; j <= right; j++)
		{
			arr[j] = temp[j];
		}
	}

	//归并排序-递归实现
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

		//当一个区间走完就停止，一个区间走完另一个区间已经是有序的了，没必要继续比较
		while (begin1 <= end1 && begin2 <= end2)
		{
			//两边区间进行比较把较小的值放到临时数组里
			if (arr[begin1] > arr[begin2])
			{
				temp[i++] = arr[begin2++];
			}
			else
			{
				temp[i++] = arr[begin1++];
			}
		}

		//对左右区间进行检查看哪一个是没走完的
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}

		//把临时数组里的有序区间拷贝到原数组区间。
		for (; j <= end2; j++)
		{
			arr[j] = temp[j];
		}
	}

	//归并排序-迭代实现
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

				//如果左边区间不是完整的那么就没必要交换了
				if (begin2 >= n)
				{
					break;
				}
				
				//如果右边不是完整的需要交换，但是交换前得修正下位置。
				if (end2 >= n)
				{
					end2 = n - 1;
				}
				
				//对该区间进行排序
				_MergeSort(arr, begin1, end1, begin2, end2, temp);
			}

			//跳过一个区间
			gap *= 2;
		}

		delete[] temp;
	}

	//计数排序
	void CountSort(int* arr, int n)
	{
		int maxIndex = arr[0];
		int minIndex = arr[0];
		//选出最大和最小值
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

		//开辟最大值的空间
		int range = maxIndex - minIndex + 1;
		int* temp = new int[range];
		//初始化
		memset(temp, 0, sizeof(int) * range);

		//绝对映射
		for (int i = 0; i < n; i++)
		{
			temp[arr[i] - minIndex]++;
		}

		//取出映射的值
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

	printf("QuickSort：%d\n", end1 - begin1);
	printf("QuickSortRe：%d\n", end2 - begin2);
	printf("HeapSort：%d\n", end3 - begin3);
	printf("sort：%d\n", end4 - begin4);
	printf("QuickSort1：%d\n", end5 - begin5);
}

int main()
{
	srand((size_t)time(nullptr));
	TestSort2();
	TestSort1();

	return 0;
}