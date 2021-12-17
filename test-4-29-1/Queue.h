#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//���Ľڵ�
struct BinaryTreeNode;
typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//����
void QueueDestroy(Queue* pq);

//����
void QueuePush(Queue* pq, QDataType x);

//ɾ��
void QueuePop(Queue* pq);

//���ض�ͷ
QDataType QueueFront(Queue* pq);

//���ض�β
QDataType QueueBack(Queue* pq);

//�ж��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���д�С
int QueueSize(Queue* pq);