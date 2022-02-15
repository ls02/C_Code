#pragma once
#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SLitNode
{
	SLDataType val;
	struct SListNode* next;
}SListNode;

//创建新节点
extern SListNode* SListBuyNode(SLDataType val);

//销毁
extern void SListDestroy(SListNode** ppl);

//打印
extern void SListPrint(SListNode* pl);

//增接口
//头插
extern void SListPushFront(SListNode** ppl, SLDataType val);
//尾插
extern void SListPushBack(SListNode** ppl, SLDataType val);
//在pos位置插入
extern void SListInsert(SListNode** ppl, SListNode* pos, SLDataType val);

//删接口
//头删
extern void SListPopFront(SListNode** ppl);
//尾删
extern void SListPopBack(SListNode** ppl);
//删除pos位置
extern void SListErase(SListNode** ppl, SListNode* pos);

//查接口
extern SListNode* SListFind(SListNode* pl, SLDataType val);

#endif 

