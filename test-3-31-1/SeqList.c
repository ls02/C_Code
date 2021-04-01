#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps)//初始化
{
	assert(ps);

	SLDateType* temp = (SLDateType*)malloc(sizeof(SLDateType) * 4);//初始化默认值为4个数据大小的空间
	if (!temp)//判断是否初始化成功
	{
		printf("initialization failed!\n");
		exit(-1);
	}

	ps->s = temp;//把初始化成功的空间给顺序表
	ps->size = 0;//有效数据为0
	ps->capacity = 4;//默认值容量为4
}

//扩容
void dilatation(SeqList* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)//判断有效数据的空间是否满了，如果满了扩容
	{
		int newcapacity = ps->capacity *= 2;//创建一个变量存储二倍的capacity的值

		SLDateType* News = (SLDateType*)realloc(ps->s, sizeof(SLDateType) * newcapacity);//扩容capacity的二倍大小
		if (!News)//检查是否扩容失败
		{
			printf("realloc fail\n");

			exit(-1);
		}

		ps->s = News;//把扩容成功的新地址给顺序表
		ps->capacity = newcapacity;//容量同时扩大二倍
	}
}

void SeqListDestory(SeqList* ps)//销毁
{
	assert(ps);

	free(ps->s);//销毁顺序表
	ps->s = NULL;//并置空
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)//打印
{
	assert(ps);
	unsigned int i = 0;

	for (i = 0; i < ps->size; i++)//遍历整个顺序表
	{
		printf("%d ", ps->s[i]);//打印i个数据
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)//末尾添加
{
	assert(ps);

	SeqListInsert(ps, ps->size, x);//调用任意位置插入接口来完成尾增
}

void SeqListPushFront(SeqList* ps, SLDateType x)//头部添加
{
	assert(ps);

	SeqListInsert(ps, 0, x);//调用任意位置插入接口来完成头增
}

void SeqListPopFront(SeqList* ps)//头部删除
{
	assert(ps);

	SeqListErase(ps, 0);//调用任意位置删除接口来完成头删
}

void SeqListPopBack(SeqList* ps)//末尾删除
{
	assert(ps);

	SeqListErase(ps, ps->size - 1);//调用任意位置删除接口来完成尾删
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	size_t i = 0;

	for (i = 0; i < ps->size; i++)//遍历一遍判断是否有该值
	{
		if (ps->s[i] == x)//判断i是否是x
		{
			return ps->s[i];//是x则返回x的值
		}
	}

	return 0;//如果未找到返回空指针
}

//顺序表修改
void SeqListAlter(SeqList* ps, size_t x, SLDateType data)
{
	assert(ps);
	size_t i = 0;

	if (x >= 0 && x < ps->size)//判断是否在合法范围内修改
	{
		ps->s[x] = data;//修改第x个位置的数据
	}
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	unsigned int i = 0;

	dilatation(ps);//判断是否需要扩容

	if (pos > 0 && pos <= ps->size)//判断是否在正常位置插入
	{
		for (i = ps->size; i > pos; i--)
		{
			ps->s[i] = ps->s[i - 1];//从前往后挪，因为size这个位置已经是越界所以减一挪动
		}
		ps->s[pos] = x;//在空位置上插入值
		ps->size++;
	}
	else if (pos == 0 && ps->size == 0)//判断是否有有效数据，如果没有直接再第一个位置上插入
	{
		ps->s[pos] = x;//在空位置上插入值
		ps->size++;
	}
	else if(pos == 0 && ps->size != 0)//判断是否是是头插，如果有有效数据就需要挪动再插入
	{
		for (i = ps->size; i > pos; i--)
		{
			ps->s[i] = ps->s[i - 1];//从前往后挪动
		}
		ps->s[pos] = x;//在空位置上插入值
		ps->size++;
	}
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t i = 0;

	if (pos >= 0 && pos < ps->size)//判断是否在合法范围内
	{
		for (i = pos; i < ps->size; i++)//找到要删除的位置
		{
			ps->s[i] = ps->s[i + 1];//把后面的数据覆盖到删除的数据上，这样就完成了删除，依次删除
		}
		ps->size--;//如果不需要挪动直接--，不需要真的删掉
	}
}