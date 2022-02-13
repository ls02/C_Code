#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(NULL != ps);

	ps->capacity = 0;
	ps->size = 0;
	ps->data = NULL;
}

void SeqListDestroy(SeqList* ps)
{
	assert(NULL != ps);

	free(ps->data);
	ps->size = 0;
	ps->capacity = 0;
	ps->data = NULL;
}

void SeqListCheckyCapacity(SeqList* ps)
{
	assert(NULL != ps);

	if (ps->size >= ps->capacity)
	{
		size_t newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

		DataType* newData = (DataType*)realloc(ps->data, sizeof(DataType) * newCapacity);
		if (NULL == newData)
		{
			printf("����ʧ�ܣ�\n");

			exit(-1);
		}

		ps->capacity = newCapacity;
		ps->data = newData;
	}
}

void SeqListPrint(SeqList* ps)
{
	size_t i = 0;

	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}

	putchar('\n');
}


void SeqListPushBack(SeqList* ps, DataType val)
{
	assert(NULL != ps);

	SeqListInsert(ps, ps->size, val);
}

void SeqListFront(SeqList* ps, DataType val)
{
	assert(NULL != ps);

	SeqListInsert(ps, 0, val);
}

void SeqListInsert(SeqList* ps, size_t pos, DataType val)
{
	assert(NULL != ps);

	SeqListCheckyCapacity(ps);

	if (pos > ps->size)
	{
		printf("��λ���޷����룡\a\n");

		return;
	}

	int end = ps->size - 1;

	//Ų������
	while (end >= (int)pos)
	{
		ps->data[end + 1] = ps->data[end];

		end--;
	}

	ps->data[pos] = val;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(NULL != ps && 0 != ps->size);

	if (pos >= ps->size)
	{
		printf("��λ���޷�ɾ����\a\n");

		return;
	}

	int i = 0;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}

	ps->size--;
}

void SeqListPopBack(SeqList* ps)
{
	assert(NULL != ps && 0 != ps->size);

	SeqListErase(ps, ps->size - 1);
}

void SeqListPopFront(SeqList* ps)
{
	assert(NULL != ps && 0 != ps->size);

	SeqListErase(ps, 0);
}

int SeqListFind(SeqList* ps, DataType key)
{
	assert(NULL != ps);

	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == key)
		{
			return i;
		}
	}

	return -1;
}