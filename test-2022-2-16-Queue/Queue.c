#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(NULL != pq);

	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(NULL != pq);

	QueueNode* cur = pq->head;
	while (NULL != cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = NULL;
	pq->tail = NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(NULL != pq);

	QueueNode* cur = pq->head;
	size_t size = 0;
	while (NULL != cur)
	{
		cur = cur->next;
		size++;
	}

	return size;
}

void QueuePush(Queue* pq, QDataType val)
{
	assert(NULL != pq);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->next = NULL;
	newNode->val = val;

	//检查是否尾空队列
	if (pq->tail == NULL)
	{
		pq->tail = newNode;
		pq->head = newNode;
	}
	else
	{
		pq->tail->next = newNode;
		pq->tail = newNode;
	}
}

void QueuePop(Queue* pq)
{
	assert(NULL != pq);
	assert(!QueueEmpty(pq));

	//判断是删除一个数据的队列还是多个数据的队列
	if (pq->head == pq->tail)
	{
		free(pq->head);
		pq->head = NULL;
		pq->tail = NULL;
	}
	else
	{
		QueueNode* temp = pq->head;
		pq->head = pq->head->next;
		free(temp);
		temp = NULL;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(NULL != pq);

	return pq->head == NULL;
}

QDataType QueueFront(Queue* pq)
{
	assert(NULL != pq);

	return pq->head->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(NULL != pq);

	return pq->tail->val;
}