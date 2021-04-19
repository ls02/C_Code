#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//双向链表节创建
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

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = BuyListNode(0);
	pHead->_next = pHead;
	pHead->_prev = pHead;

	return pHead;
}

// 双向链表销毁
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

// 双向链表打印
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
// 双向链表尾插
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

// 双向链表尾删
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
// 双向链表头插
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
// 双向链表头删
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
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	free(pos);

	prev->_next = next;
	next->_prev = prev;
}