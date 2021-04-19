#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//˫������ڴ���
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

	if (!newNode)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	newNode->_next = NULL;
	newNode->_prev = NULL;
	newNode->_data = x;

	return newNode;
}

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* pHead = BuyListNode(0);
	pHead->_next = pHead;
	pHead->_prev = pHead;

	return pHead;
}

// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);

		cur = next;
	}

	free(pHead);
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		printf("%d->", cur->_data);

		cur = cur->_next;
	}

	printf("NULL\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newNode = BuyListNode(x);
	ListNode* pTail = pHead->_prev;

	pTail->_next = newNode;
	newNode->_prev = pTail;
	newNode->_next = pHead;
	pHead->_prev = newNode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);

	ListNode* pTail = pHead->_prev;
	ListNode* pTailPrev = pTail->_prev;

	free(pTail);
	pTail = NULL;

	pTailPrev->_next = pHead;
	pHead->_prev = pTailPrev;
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	assert(pHead->_next != pHead);

	ListNode* newNode = BuyListNode(x);
	ListNode* first = pHead->_next;

	newNode->_next = first;
	first->_prev = newNode;
	newNode->_prev = pHead;
	pHead->_next = newNode;

}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	
	ListNode* first = pHead->_next;
	ListNode* second = first->_next;

	free(first);
	first = NULL;

	second->_prev = pHead;
	pHead->_next = second;
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* cur = pHead->_next;

	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* newNode = BuyListNode(x);

	prev->_next = newNode;
	newNode->_prev - prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	free(pos);

	prev->_next = next;
	next->_prev = prev;
}