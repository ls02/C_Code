#define _CRT_SECURE_NO_WARNINGS 1
#include "Srot.h"

static void Swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

// 插入排序
void InsertSort(int* a, int n)
{
	int i = 0;

	//每次遍历都要访问数组的后一个，所以n-1防止越界访问
	for (i = 0; i < n - 1; i++)
	{
		//end前面的数认为是有序的
		int end = i;
		//把temp插到end前面,把end后面的一个数认为是待排序的数
		int temp = a[end + 1];

		//如果end大于等于0就认为还有数可以比较
		while (end >= 0)
		{
			//按升序排，end大于temp就到后面去
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

		//走到这有两种情况所有数都比temp大，或end小于temp就把temp插到end后面的位置
		a[end + 1] = temp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;

	//gap大于1说明是预排序阶段，当gap等于1相当于插入排序
	//当gap的值越大，说明它需要交换的次数越少并且数组的顺序不会接近有序
	//当gap的值越小，说明它需要交换的次数越多并且数组的顺序越来越接近有序
	while (gap > 1)
	{
		//每次gap都会缩小三分之一，加一是防止gap等于0
		gap = gap / 3 + 1;
		int i = 0;

		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = a[end + gap];

			//当end>=0 说明还有值可以交换
			while (end >= 0)
			{
				//当temp小于end，end就把值覆盖到，end+gap的位置上
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

			//走到只有两种可能，temp大于end或所有数都大于temp
			a[end + gap] = temp;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int i = 0;

	//如果left小于right说明还有数需要交换
	while (left < right)
	{
		int maxIndex = left;
		int minIndex = left;

		for (i = left; i <= right; i++)
		{	
			//找出最大的数，并把最大的数的下标给maxIndex
			if (a[i] >= a[maxIndex])
			{
				maxIndex = i;
			}

			//找出最小的数并把最小的数的下标给minIndex
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}

		//交换，按升序排，left应该放最小的所以minIndex是最小的数和left交换
		Swap(&a[left], &a[minIndex]);
		//判断left和maxIndex是否重叠，因为重叠，最小的和left交换此时的maxindex最大的会变成最小的，而最小的之前的坐标会变成最大的，我们需要调整
		if (left == maxIndex)
		{
			//此时minIndex是交换过的，没交换过是最小的而交换过边成最的了，因为left和maxIndex重叠了，所以我们调整把minIndex给maxIndex
			maxIndex = minIndex;
		}
		//交换，right是存最大的，所以和maxIndex交换
		Swap(&a[right], &a[maxIndex]);

		left++;
		right--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)//大根堆向下调整法
{
	int Child = root * 2 + 1;

	//如果孩子小于n说明还能继续调整
	while (Child < n)
	{
		//选出最大的孩子
		if (Child + 1 < n && a[Child] < a[Child + 1])
		{
			Child++;
		}

		//如果孩子大于父节点就交换
		if (a[root] < a[Child])
		{
			Swap(&a[root], &a[Child]);

			root = Child;
			Child = root * 2 + 1;
		}
		else//如果不大于就结束
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	int i = 0;

	//建堆
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;

	//从下向上调整
	while (end > 0)
	{
		//交换第一个元素和第end元素，这样最大的就跑到了最后
		Swap(&a[0], &a[end]);
		//因为调整了堆里面的数据，此时的堆就不是大根堆了，这时我们用向下调整法，把变成大根堆，因为我们动的是根节点，所以左子树和右子树还是大根堆
		//因为上面的操作，最后一个是最大的就不用调它，值调它end前面的，所以总数就放end,当end等于0的时候这个数组就是有序的了
		AdjustDwon(a, end, 0);

		end--;
	}
}

// 冒泡排序
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

//三数取中
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

	//取第一个元素作为参考值
	int keyi = left;
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}

		// 找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[keyi], &a[left]);


	return left;
}

//快速排序
//void QuickSort(int* a, int begin, int end)
//{
//	//当begin和end相当说明只有一个数，当只有一个数就是有序的，就不需要排序
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
//	//当走到这一步，先把left左边小于keyi的元素，当做一个新的数组，进行排序。
//	QuickSort(a, begin, meeti - 1);
//	//当走到这一步，先把left右边大于keyi的元素,当做一个新的数组，进行排序
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
//		// 找小
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// 找大
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

//挖坑法
int PartSort2(int* a, int left, int right)
{
	int MidIdex = GetMidIndex(a, left, right);
	Swap(&a[MidIdex], &a[left]);

	int keyi = a[left];

	while (left < right)
	{
		//找小
		while (left < right && a[right] >= keyi)
		{
			right--;
		}
		Swap(&a[left], &a[right]);

		//找大
		while (left < right && a[left] <= keyi)
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &keyi);

	return left;
}


//前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int prev = keyi;
	int cur = keyi + 1;

	while (cur <= right)
	{
		//找小
		if (a[cur] < a[keyi] && a[prev++] != a[cur])
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}

	//与中间值交换
	Swap(&a[prev], &a[keyi]);

	return prev;
}

//快速排序
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;


	// [begin, meeti-1] meeti [meeti+1, end]

	//小区间优化
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

//迭代快排
void QuickSort1(int* a, int begin, int end)
{
	//创建一个栈
	Stack st;
	//初始化栈
	StackInit(&st);
	//入栈
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		//出栈，因为先进后出，所以栈顶是right
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		//进行排序，并返回中间下标
		int keyi = PartSort1(a, left, right);

		//入中间值左边的数组下标进栈
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		//入中间值右边的数组下标进栈
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
	 
	//类似二叉树的后序，分解到只有一个数的区间开始合并
	_MergeSort(a, left, Mid, temp);
	_MergeSort(a, Mid + 1, right, temp);

	int begin1 = left;
	int begin2 = Mid + 1;
	int end1 = Mid;
	int end2 = right;
	int i = left;
	int j = left;

	//第一区间和第二区间合并
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

	//检查是否还有未合并的数
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//拷贝回原数组
	while (j <= right)
	{
		a[j] = temp[j];
		j++;
	}

	//memcpy(a + left, temp + left, sizeof(int) * (right - left + 1));
}

// 归并排序递归实现
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

	//归并，当其中一个归并完就结束
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

	//检查是否还有数没归并
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}

	//拷贝会原数组
	while (j < begin2)
	{
		a[j] = temp[j];
		j++;
	}
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	assert(a);

	int* temp = (int*)malloc(sizeof(int) * n);
	if (!temp)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	//归并的个数
	int gap = 1;

	while (gap < n)
	{
		int i = 0;

		//分出两个区间
		for (i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i;
			int begin2 = i + gap;
			int end1 = i + gap - 1;
			int end2 = i + 2 * gap - 1; 

			//如果第二个区间和n相等或大于，就不用排序
			if (begin2 >= n)
			{
				break;
			}

			//如果第二区间的末尾不满就修正
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			//两个区间归并
			_Merge(a, temp, begin1, end1, begin2, end2);
		}

		gap *= 2;
	}

	free(temp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	int i = 0;

	//找出最大和最小
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

	//找数据范围
	int range = max - min + 1;
	int* countArray = (int*)malloc(sizeof(int) * range);
	if (!countArray)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	//数组初始化为0
	memset(countArray, 0, sizeof(int) * range);

	//统计个个数字的个数
	for (i = 0; i < n; i++)
	{
		countArray[a[i] - min]++;
	}

	int index = 0;

	//把统计好的个数按升序存入要排序的数组
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
//	//找到数据的范围
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
//	//存放在相对位置，可以节省空间
//	for (int i = 0; i < n; ++i)
//	{
//		countArray[a[i] - min]++;
//	}
//	//可能存在重复的数据，有几个存几个
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