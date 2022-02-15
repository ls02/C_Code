#include "SList.h"

SListNode* SListBuyNode(SLDataType val)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		printf("����ڵ�ʧ�ܣ�\n");

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

	//���ֻ��һ���ڵ�
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

	//�ձ����
	if (NULL == *ppl)
	{
		*ppl = newNode;

	}
	else//ͷ���pos��
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

	//�ҵ����һ���ڵ�
	while (NULL != cur->next)
	{
		prev = cur;
		cur = cur->next;
	}

	free(cur);
	cur = NULL;

	//�����ɾһ���ڵ㻹�Ƕ���ڵ�
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