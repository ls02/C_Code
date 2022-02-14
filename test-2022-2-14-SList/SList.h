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
	SListNode* next;
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
extern void SListInsert(SListNode** ppl, size_t pos, SLDataType val);

//删接口
//头删
extern void SListNodePopFront(SListNode** ppl);
//尾删
extern void SListNodePopBack(SListNode** ppl);
//删除pos位置
extern void SListNodeErase(SListNode** ppl, size_t pos);

//查接口
extern size_t SListNodeFind(SListNode* pl, SLDataType val);

#endif 

