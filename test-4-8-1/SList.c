#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));//����һ���ڵ�
	
	if (!newNode)//�ж��Ƿ�����ɹ�
	{
		printf("newNode fail\n");

		return NULL;
	}

	newNode->next = NULL;
	newNode->data = x;

	return newNode;//��������Ľڵ�
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* newNode = BuySListNode(x);//����һ���ڵ�

	if (!*pplist)//�ж��Ƿ�Ϊ��
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* tail = *pplist;

		while (tail->next)//��Ϊ���ҵ�β����β��
		{
			tail = tail->next;
		}

		tail->next = newNode;
	}
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	SListNode* newNode = BuySListNode(x);//����һ���ڵ����ͷ��

	newNode->next = *pplist;
	*pplist = newNode;
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* tail = plist;

	while (tail)//����һ�������ӡ
	{
		printf("%d->", tail->data);
		tail = tail->next;
	}

	printf("NULL\n");
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);

	if (!*pplist)//�ж��Ƿ��ǿ�
	{
		return;
	}
	else if (!(*pplist)->next)//�ж��Ƿ�Ϊ�����ڵ�
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//���������βɾ
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

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);

	SListNode* front = *pplist;

	if (*pplist)//�ж��Ƿ�Ϊ�ղ��Ǿ�ͷɾ
	{
		*pplist = (*pplist)->next;

		free(front);
		front = NULL;
	}
	else//�ǵĻ������κδ���
	{
		return;
	}
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);

	SListNode* src = plist;

	while (src)//����һ������
	{
		if (src->data == x)//����data��x��ȷ�������ڵ�ĵ�ַ
		{
			return src;
		}

		src = src->next;//����
	}

	return NULL;//û�д˽ڵ㷵�ؿ�
}
// �����������
void SListDestory(SListNode* plist)
{
	assert(plist);

	SListNode* cur = plist;
	SListNode* next = NULL;

	if (!plist)
	{
		return;
	}

	while (cur)//����������
	{
		next = cur->next;//��cur���¸��ڵ��next

		free(cur);//����cur
		cur = next;//next��cur���е���
	}
}


//����ڵ����
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);//����һ���½ڵ�

	newNode->next = pos->next;//��pos�������
	pos->next = newNode;
}

//����ڵ�ɾ��
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;//����next����pos����һ���ڵ�
	pos->next = next->next;//pos����next��next
	
	free(next);//�ͷ�next
	next = NULL;
}