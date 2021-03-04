#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	
	//�ж��Ƿ�����ɹ�
	if (!newNode)
	{
		printf("�����ڴ�ʧ��!\n");

		return NULL;
	}

	newNode->data = x;
	newNode->Next = NULL;

	return newNode;
}

//ͷ��
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

//�������ӡ
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

///�������β��
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

//�������ͷɾ
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

//�������βɾ
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

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	
	SListNode* newNode = BuySListNode(x);
	newNode->Next = pos->Next;
	pos->Next = newNode;
}

//������Ĳ���
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

//ɾ��pos֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	SListNode* next = pos->Next;
	SListNode* nextnext = next->Next;

	pos->Next = nextnext;

	free(next);
}