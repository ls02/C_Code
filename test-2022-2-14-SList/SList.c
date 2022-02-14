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

void SListNodeDestroy(SListNode** ppl)
{
	assert(NULL != ppl);

	SListNode* cur = (*ppl);

	//如果只有一个节点
	if (NULL == cur->next)
	{
		free(cur);
		cur = NULL;
		*ppl = NULL;

		return;
	}

	while (NULL != cur->next)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	cur = NULL;
	*ppl = NULL;
}

void SListNodePushBack(SListNode** ppl, SLDataType val)
{
	assert(ppl);


}

void SListNodePushFront(SListNode** ppl, SLDataType val)
{
	assert(ppl);`

}

void SListNodeInsert(SListNode** ppl, SLDataType val)
{
	assert(ppl);

	SListNode* newNode = SListBuyNode(val);

	//头插
	if (NULL == *ppl)
	{
		*ppl = newNode;

	}
	else//尾插和pos插
	{

	}
}