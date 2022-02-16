#pragma once
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LtDataType;

typedef struct ListNode
{
	LtDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	struct ListNode* pHead;
}List;

//新建一个节点
extern ListNode* ListNewNode(LtDataType val);

//初始化链表
extern ListNode* ListInit();

//销毁一个链表
extern void ListDestroy(ListNode** pHead);

//打印链表
extern void ListPrint(ListNode* pHead);

//获取链表的节点个数
extern size_t ListSize(ListNode* pHead);

//增接口
//头插
void ListPushFront(ListNode* pHead, LtDataType val);
//尾插
void ListPushBack(ListNode* pHead, LtDataType val);
//pos位置插入
extern void ListInsert(ListNode* pos, LtDataType val);

//删接口
//头删
extern void ListPopFront(ListNode* pHead);
//尾扇
extern void ListPopBack(ListNode* pHead);
//pos位置删除
extern void ListErase(ListNode* pos);

//查接口
extern ListNode* ListFind(ListNode* pHead, LtDataType key);

#endif