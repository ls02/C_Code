#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_head = pq->_tail = NULL;
}

//销毁
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

//判断是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//如果是空返回真
	return pq->_head == NULL;
}

//插入
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

//删除
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

//返回队头
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_head->_data;
}

//返回队尾
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->_tail->_data;
}

//队列大小
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