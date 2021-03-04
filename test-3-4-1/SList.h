#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* Next;
}SListNode;

//动态申请一个节点
SListNode* BuySListNode(SLTDateType x);

//单链表打印
void SListPrint(SListNode* plist);

///单链表的尾插
void SListPushBack(SListNode** pplist, SLTDateType x);

//单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);

//单链表的头删
void SListpopFront(SListNode** pplist);

//单链表的尾删
void SListpopBack(SListNode** pplis);

//单链表的查找
SListNode* SListFind(SListNode* plist, SLTDateType x);

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x);

//删除pos之后的值
void SListEraseAfter(SListNode* pos);
