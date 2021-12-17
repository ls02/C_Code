#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ��
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_head = pq->_tail = NULL;
}

//����
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_head;

	while (cur)
	{
		QueueNode* next  = cur->_next;
		
		free(cur);
		cur = next;
	}

	pq->_head = pq->_tail = NULL;
}

//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//����ǿշ�����
	return pq->_head == NULL;
}

//����
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

	if (!newNode)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	newNode->_next = NULL;
	newNode->_data = x;

	if (!pq->_head)
	{
		pq->_head = pq->_tail = newNode;
	}
	else
	{
		pq->_tail->_next = newNode;
		pq->_tail = newNode;
	}
}

//ɾ��
void QueuePop(Queue* pq)
{
	assert(pq);

	if (!pq->_head->_next)
	{
		free(pq->_head);
		pq->_head = pq->_tail = NULL;
	}
	else
	{
		QueueNode* next = pq->_head->_next;
		free(pq->_head);
		pq->_head = next;
	}
}

//���ض�ͷ
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_head->_data;
}

//���ض�β
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_tail->_data;
}

//���д�С
int QueueSize(Queue* pq)
{
	assert(pq);

	int size = 0;
	QueueNode* cur = pq->_head;

	while (cur)
	{
		cur = cur->_next;
		size++;
	}

	return size;
}