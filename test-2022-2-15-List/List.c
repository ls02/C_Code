#include "List.h"

ListNode* ListNewNode(LtDataType val)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newNode)
	{
		printf("ÄÚ´æÉêÇëÊ§°Ü£¡\n");

		exit(-1);
	}

	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->val = val;

	return newNode;
}

ListNode* ListInit()
{
	ListNode* pHead = ListNewNode(0);
	pHead->next = pHead;
	pHead->prev = pHead;

	return pHead;
}

void ListDestroy(ListNode** pHead)
{
	assert(NULL != pHead);

	ListNode* cur = (*pHead)->next;
	while (cur != *pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(*pHead);
	*pHead = NULL;
}

void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}

	putchar('\n');
}

void ListInsert(ListNode* pos, LtDataType val)
{
	assert(NULL != pos);

	ListNode* newNode = ListNewNode(val);
	ListNode* prev = pos->prev;

	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = pos;
	pos->prev = newNode;
}

void ListPushBack(ListNode* pHead, LtDataType val)
{
	assert(pHead);

	ListInsert(pHead, val);
}

void ListPushFront(ListNode* pHead, LtDataType val)
{
	assert(pHead);

	ListInsert(pHead->next, val);
}

ListNode* ListFind(ListNode* pHead, LtDataType key)
{
	assert(NULL != pHead);

	ListNode* cur = pHead->next;

	while (cur != pHead)
	{
		if (cur->val == key)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void ListErase(ListNode* pos)
{
	assert(NULL != pos);

	ListNode* prev = pos->prev;
	ListNode* cur = pos;
	ListNode* next = pos->next;

	prev->next = cur->next;
	next->prev = prev;

	free(cur);
	cur = NULL;
}

void ListPopBack(ListNode* pHead)
{
	assert(NULL != pHead);

	ListErase(pHead->prev);
}

void ListPopFront(ListNode* pHead)
{
	assert(NULL != pHead);

	ListErase(pHead->next);
}

size_t ListSize(ListNode* pHead)
{
	assert(NULL != pHead);

	size_t size = 0;
	ListNode* cur = pHead->next;

	while (cur != pHead)
	{
		size++;
		cur = cur->next;
	}

	return size;
}