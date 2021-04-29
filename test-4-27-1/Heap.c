#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

static void ADjusUP(HPDataType* a, int size)
{
	int child = size - 1;
	int parent = (child - 2) / 2;
	
	while (child > 0)
	{
		//如果孩子大于父亲就交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//向下调整
void AdjustDwon(HPDataType* a, int n, int parent)
{
	assert(a);

	int child = parent * 2 + 1;

	while (child < n)
	{
		//选出最大的孩子
		if (child + 1< n && a[child] < a[child + 1])
		{
			child++;
		}

		//如果比父亲大就交换
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	int i = 0;

	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!hp->a)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	//把数据拷到堆里
	memcpy(hp->a, a, sizeof(HPDataType) * n);
	hp->size = n;
	hp->capacity = n;

	//建堆
	for (i = (hp->size - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(hp->a, hp->size, i);
	}
	
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//空间不够就扩容
	if (hp->size == hp->capacity)
	{
		HPDataType* temp = (HPDataType*)realloc(hp->a, hp->capacity * 2 * sizeof(HPDataType));

		if (!temp)
		{
			printf("realloc fail\n");

			exit(-1);
		}

		hp->a = temp;
		hp->capacity *= 2;
	}

	hp->a[hp->size] = x;
	hp->size++;

	//最后一个数据向上调整
	ADjusUP(hp->a, hp->size);
}

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDwon(hp->a, hp->size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

// 堆的判空
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	int i = 0;

	if (!k || !n)
	{
		return;
	}

	//建大堆
	for (i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, k, i);
	}
	

	for (i = k; i < n; i++)
	{
		if (a[0] > a[i])
		{
			Swap(&a[0], &a[i]);
			AdjustDwon(a, k, 0);
		}
	}
}

void TestTopk()
{
	int arr[] = { 22, 33, 123, 53, 6, 121, 35, 3, 66, 12, 15, 99 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	PrintTopK(arr, size, 12);

	for (i = 0; i < 12; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//计算二叉树的深度
static int depth(int n)
{
	if (n > 0)
	{
		int h = 1;
		int y = 2;

		while (y < n)
		{
			y *= 2;
			h++;
		}

		return h;
	}
	else
	{
		return 0;
	}
}

void HeapPrint(Heap* hp)
{
	assert(hp);

	int i = 0;
	int j = 0;

	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}

	printf("\n\n");
	
	//高度
	int h = depth(hp->size);
	//空格数
	int y = 2 * (h - 1);
	//行数
	size_t row = 1;
	//下标
	int pos = 0;

	while (1)
	{
		i = 0;
		
		while (i < y)
		{
			//打印空格
			printf(" ");
			i++;
		}
		y--;

		//数据的个数
		int count = (int)pow(2, row - 1);

		//当数据大于有效数据就结束循环
		while (count-- && pos < hp->size)
		{
			//打印堆的数据
			printf("%d ", hp->a[pos++]);
		}

		printf("\n\n");

		//当大于有效数据，说明打印没有数据可以打印了推出循环
		if (pos >= hp->size)
		{
			break;
		}
		row++;
	}
}


