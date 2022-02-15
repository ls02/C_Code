#include "SList.h"

SListNode* SListBuyNode(SLDataType val)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		printf("申请节点失败！\n");

		exit(-1);
	}

	newNode->next = NULL;
	newNode->val = val;

	return newNode;
}

void SListDestroy(SListNode** ppl)
{
	assert(NULL != ppl && NULL != *ppl);

	SListNode* cur = *ppl;

	//如果只有一个节点
	if (NULL == cur->next)
	{
		free(cur);
		*ppl = NULL;

		return;
	}

	while (NULL != cur->next)      
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*ppl = NULL;
}

void SListPrint(SListNode* pl)
{
	assert(NULL != pl);

	while (NULL != pl)
	{
		printf("%d ", pl->val);

		pl = pl->next;
	}

	putchar('\n');
}

void SListPushBack(SListNode** ppl, SLDataType val)
{
	assert(ppl);

	SListNode* cur = *ppl;
	SListNode* newNode = SListBuyNode(val);

	if (NULL == cur)
	{
		*ppl = newNode;
	}
	else
	{
		while (NULL != cur->next)
		{
			cur = cur->next;
		}

		cur->next = newNode;
	}
}

void SListPushFront(SListNode** ppl, SLDataType val)
{
	assert(ppl);

	SListNode* newNode = SListBuyNode(val);

	newNode->next = *ppl;
	*ppl = newNode;
}

void SListInsert(SListNode** ppl, SListNode* pos, SLDataType val)
{
	assert(ppl);

	SListNode* newNode = SListBuyNode(val);

	//空表插入
	if (NULL == *ppl)
	{
		*ppl = newNode;

	}
	else//头插和pos插
	{
		SListNode* cur = *ppl;
		SListNode* prev = NULL;

		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}

		if (NULL != prev)
		{
			prev->next = newNode;
		}

		newNode->next = cur;
	}
}

SListNode* SListFind(SListNode* pl, SLDataType val)
{
	assert(NULL != pl);

	SListNode* cur = pl;

	while (NULL != cur)
	{
		if (cur->val == val)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void SListPopBack(SListNode** ppl)
{
	assert(NULL != ppl && NULL != *ppl);

	SListNode* cur = *ppl;
	SListNode* prev = NULL;

	//找到最后一个节点
	while (NULL != cur->next)
	{
		prev = cur;
		cur = cur->next;
	}

	free(cur);
	cur = NULL;

	//检查是删一个节点还是多个节点
	if (NULL != prev)
	{
		prev->next = NULL;

	}
	else
	{
		*ppl = NULL;
	}
}

void SListPopFront(SListNode** ppl)
{
	assert(NULL != ppl && NULL != *ppl);

	SListNode* cur = *ppl;
	*ppl = (*ppl)->next;

	free(cur);
	cur = NULL;
}

void SListErase(SListNode** ppl, SListNode* pos)
{
	assert(NULL != ppl && NULL != *ppl && NULL != pos);

	SListNode* cur = *ppl;
	SListNode* prev = NULL;

	while (cur != pos)
	{
		prev = cur;
		cur = cur->next;
	}

	if (NULL != prev)
	{
		prev->next = cur->next;
		free(cur);
		cur = NULL;
	}
	else
	{
		free(cur);
		cur = NULL;
		*ppl = NULL;
	}
}