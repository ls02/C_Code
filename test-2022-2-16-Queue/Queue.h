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

//初始化
extern void QueueInit(Queue* pq);

//销毁
extern void QueueDestroy(Queue* pq);

//获取队列数据个数
extern size_t QueueSize(Queue* pq);

//入队
extern void QueuePush(Queue* pq, QDataType val);

//出队
extern void QueuePop(Queue* pq);

//获取队头数据
extern QDataType QueueFront(Queue* pq);

//获取队尾数据
extern QDataType QueueBack(Queue* pq);

//检查是否为空
extern bool QueueEmpty(Queue* pq);

#endif
