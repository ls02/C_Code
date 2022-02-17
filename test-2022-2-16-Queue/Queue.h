#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType val;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//��ʼ��
extern void QueueInit(Queue* pq);

//����
extern void QueueDestroy(Queue* pq);

//��ȡ�������ݸ���
extern size_t QueueSize(Queue* pq);

//���
extern void QueuePush(Queue* pq, QDataType val);

//����
extern void QueuePop(Queue* pq);

//��ȡ��ͷ����
extern QDataType QueueFront(Queue* pq);

//��ȡ��β����
extern QDataType QueueBack(Queue* pq);

//����Ƿ�Ϊ��
extern bool QueueEmpty(Queue* pq);

#endif
