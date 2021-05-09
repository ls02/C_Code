#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//树的节点
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

//初始化
void QueueInit(Queue* pq);

//销毁
void QueueDestroy(Queue* pq);

//插入
void QueuePush(Queue* pq, QDataType x);

//删除
void QueuePop(Queue* pq);

//返回队头
QDataType QueueFront(Queue* pq);

//返回队尾
QDataType QueueBack(Queue* pq);

//判断是否为空
bool QueueEmpty(Queue* pq);

//队列大小
int QueueSize(Queue* pq);