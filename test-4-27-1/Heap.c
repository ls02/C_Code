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
		//������Ӵ��ڸ��׾ͽ���
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

//���µ���
void AdjustDwon(HPDataType* a, int n, int parent)
{
	assert(a);

	int child = parent * 2 + 1;

	while (child < n)
	{
		//ѡ�����ĺ���
		if (child + 1< n && a[child] < a[child + 1])
		{
			child++;
		}

		//����ȸ��״�ͽ���
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


// �ѵĹ���
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

	//�����ݿ�������
	memcpy(hp->a, a, sizeof(HPDataType) * n);
	hp->size = n;
	hp->capacity = n;

	//����
	for (i = (hp->size - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(hp->a, hp->size, i);
	}
	
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//�ռ䲻��������
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

	//���һ���������ϵ���
	ADjusUP(hp->a, hp->size);
}

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	Swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDwon(hp->a, hp->size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->size > 0);

	return hp->a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);

	return hp->size;
}

// �ѵ��п�
bool HeapEmpty(Heap* hp)
{
	assert(hp);

	return hp->size == 0;
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	assert(a);
	int i = 0;

	if (!k || !n)
	{
		return;
	}

	//�����
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

//��������������
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
	
	//�߶�
	int h = depth(hp->size);
	//�ո���
	int y = 2 * (h - 1);
	//����
	size_t row = 1;
	//�±�
	int pos = 0;

	while (1)
	{
		i = 0;
		
		while (i < y)
		{
			//��ӡ�ո�
			printf(" ");
			i++;
		}
		y--;

		//���ݵĸ���
		int count = (int)pow(2, row - 1);

		//�����ݴ�����Ч���ݾͽ���ѭ��
		while (count-- && pos < hp->size)
		{
			//��ӡ�ѵ�����
			printf("%d ", hp->a[pos++]);
		}

		printf("\n\n");

		//��������Ч���ݣ�˵����ӡû�����ݿ��Դ�ӡ���Ƴ�ѭ��
		if (pos >= hp->size)
		{
			break;
		}
		row++;
	}
}


