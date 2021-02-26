#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化
void SeqListInit(SL* ps)
{
	assert(ps);
	ps->data = (SlType*)malloc(sizeof(SlType) * 4);

	if (ps->data == NULL)
	{
		printf("初始化失败!\n");
		return;
	}

	ps->size = 0;
	ps->capacity = 4;
}

//尾删
void SeqListBackDelet(SL* ps)
{
	assert(ps);

	ps->size--;
}

//尾插
void SeqListBackInsert(SL* ps, SlType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	ps->size++;
	ps->data[ps->size - 1] = x;
}

//头插
void SeqListHendInsert(SL* ps, SlType x)
{
	assert(ps);
	int i = 0;

	SeqListCheckCapacity(ps);

	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	
	ps->data[0] = x;
	ps->size++;
}

//头删
void SeqListHendDlest(SL* ps)
{
	assert(ps && ps->data);

	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}

	ps->size--;
}

//选择插入替换
SlType SeqListOptInsertReplce(SL* ps, SlType x, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];
		ps->data[seat - 1] = x;

		return temp;
	}
	else
	{
		printf("此处无法插入\n");

		return 0;
	}
}

//打印数据
void SeqListPrint(SL* ps)
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}

	printf("\n");
}

//检查增容
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		SlType* x = (SlType*)realloc(ps->data, sizeof(SlType) * ps->capacity);

		if (NULL == x)
		{
			printf("申请内存失败!\n");

			return;
		}
		ps->data = x;
	}
}

//销毁
void SeqListDestory(SL* ps)
{
	assert(ps);

	free(ps->data);
	free(ps);
}

//查找
SlType SeqListFind(SL* ps, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		return ps->data[seat - 1];
	}
	else
	{
		printf("无数据!\n");

		return 0;
	}
}

//选择删除
SlType SeqListOptDelete(SL* ps, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];
		int i = 0;

		for (i = seat; i < ps->size; i++)
		{
			ps->data[i - 1] = ps->data[i];
		}
		ps->size--;

		return temp;
	}
	else
	{
		printf("无可删除数据!\n");
		
		return 0;
	}

}


//选择插入
SlType SeqListOptInsertt(SL* ps, SlType x, int seat)
{
	assert(ps);
	int i = 0;
	SeqListCheckCapacity(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];

		for (i = ps->size; i >= seat; i--)
		{
			ps->data[i] = ps->data[i - 1];
		}

		ps->data[seat - 1] = x;
		ps->size++;

		return temp;
	}
	else
	{
		printf("无法插入!\n");

		return 0;
	}
}