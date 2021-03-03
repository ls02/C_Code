#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	
	//判断是否申请成功
	if (!newNode)
	{
		printf("申请内存失败!\n");

		return NULL;
	}

	newNode->data = x;
	newNode->Next = NULL;

	return newNode;
}

//头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	if (*pplist)
	{
		SListNode* newNode = *pplist;
		*pplist = BuySListNode(x);
		(*pplist)->Next = newNode;
	}
	else
	{
		*pplist = BuySListNode(x);
	}
}

//单链表打印
void SListPrint(SListNode* plist)
{
	assert(plist);

	if (!plist->Next)
	{
		return;
	}

	SListNode* tail = plist;

	while (tail)
	{
		printf("%d->", tail->data);
		tail = tail->Next;
	}
	printf("NULL\n");
}

///单链表的尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	if (*pplist)
	{
		SListNode* newNode = BuySListNode(x);
		SListNode* tail = *pplist;

		while (tail->Next)
		{
			tail = tail->Next;
		}
		tail->Next = newNode;
	}
	else
	{
		*pplist = BuySListNode(x);
	}
}

//单链表的头删
void SListpopFront(SListNode** pplist)
{
	assert(pplist);

	if (*pplist)
	{
		SListNode* head = *pplist;
		*pplist = (*pplist)->Next;

		free(head);
	}
	else
	{
		return;
	}
}

//单链表的尾删
void SListpopBack(SListNode** pplist)
{
	assert(pplist);

	if (!(*pplist)->Next)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else if ((*pplist)->Next)
	{
		SListNode* tail = *pplist;
		SListNode* prev = NULL;

		while (tail->Next)
		{
			prev = tail;
			tail = tail->Next;
		}

		free(tail);
		prev->Next = NULL;
	}
	else
	{
		return;
	}
}

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	
	SListNode* newNode = BuySListNode(x);
	newNode->Next = pos->Next;
	pos->Next = newNode;
}

//单链表的查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* temp = plist;

	while (temp)
	{
		if (temp->data == x)
		{
			return temp;
		}
		
		temp = temp->Next;
	}

	return NULL;
}

//删除pos之后的值
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* next = pos->Next;
	SListNode* nextnext = next->Next;

	pos->Next = nextnext;

	free(next);
}