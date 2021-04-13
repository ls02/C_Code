#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));//申请一个节点
	
	if (!newNode)//判断是否申请成功
	{
		printf("newNode fail\n");

		return NULL;
	}

	newNode->next = NULL;
	newNode->data = x;

	return newNode;//返回申请的节点
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* newNode = BuySListNode(x);//创建一个节点

	if (!*pplist)//判断是否为空
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* tail = *pplist;

		while (tail->next)//不为空找到尾进行尾插
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* newNode = BuySListNode(x);//申请一个节点进行头插

	newNode->next = *pplist;
	*pplist = newNode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* tail = plist;

	while (tail)//遍历一遍链表打印
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}

	printf("NULL\n");
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);

	if (!*pplist)//判断是否是空
	{
		return;
	}
	else if (!(*pplist)->next)//判断是否为单个节点
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//正常情况的尾删
	{
		SListNode* tail = *pplist;
		SListNode* prev = NULL;

		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);

	SListNode* front = *pplist;

	if (*pplist)//判断是否为空不是就头删
	{
		*pplist = (*pplist)->next;

		free(front);
		front = NULL;
	}
	else//是的话不做任何处理
	{
		return;
	}
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* src = plist;

	while (src)//遍历一遍链表
	{
		if (src->data == x)//遇到data和x相等返回这个节点的地址
		{
			return src;
		}

		src = src->next;//迭代
	}

	return NULL;//没有此节点返回空
}
// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist);

	SListNode* cur = plist;
	SListNode* next = NULL;

	if (!plist)
	{
		return;
	}

	while (cur)//遍历单链表
	{
		next = cur->next;//把cur的下个节点给next

		free(cur);//销毁cur
		cur = next;//next给cur进行迭代
	}
}


//任意节点插入
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);//创建一个新节点

	newNode->next = pos->next;//在pos后面插入
	pos->next = newNode;
}

//任意节点删除
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;//创建next保存pos的下一个节点
	pos->next = next->next;//pos连接next的next
	
	free(next);//释放next
	next = NULL;
}