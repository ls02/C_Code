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

void SListNodeDestroy(SListNode** ppl)
{
	assert(NULL != ppl);

	SListNode* cur = (*ppl);

	//���ֻ��һ���ڵ�
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

	//ͷ��
	if (NULL == *ppl)
	{
		*ppl = newNode;

	}
	else//β���pos��
	{

	}
}