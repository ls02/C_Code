#pragma once
#ifndef __SEQ_LIST_H__
#define __SEQ_LIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;

typedef struct SeqLsit
{
	DataType* data;
	size_t size;
	size_t capacity;
}SeqList;

//初始化
extern void SeqListInit(SeqList* ps);

//销毁
extern void SeqListDestroy(SeqList* ps);

//检查扩容
extern void SeqListCheckyCapacity(SeqList* ps);

//打印数据
extern void SeqListPrint(SeqList* ps);

//增接口
//尾插
extern void SeqListPushBack(SeqList* ps, DataType val);
//头插
extern void SeqListFront(SeqList* ps, DataType val);
//Pos位置插入
extern void SeqListInsert(SeqList* ps, size_t pos, DataType val);

//删接口
//尾删
extern void SeqListPopBack(SeqList* ps);
//头删
extern void SeqListPopFront(SeqList* ps);
//删pos位置
extern void SeqListErase(SeqList* ps, size_t pos);

//查找接口
extern int SeqListFind(SeqList* ps, DataType key);

#endif
