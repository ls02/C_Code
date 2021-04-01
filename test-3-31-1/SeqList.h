#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* s;//数据
	size_t size;//实际容量
	size_t capacity;//总共容量
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);//初始化
void SeqListDestory(SeqList* ps);//销毁

void SeqListPrint(SeqList* ps);//打印
void SeqListPushBack(SeqList* ps, SLDateType x);//末尾添加
void SeqListPushFront(SeqList* ps, SLDateType x);//头部添加
void SeqListPopFront(SeqList* ps);//头部删除
void SeqListPopBack(SeqList* ps);//末尾删除

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
//顺序表修改
void SeqListAlter(SeqList* ps, size_t x, SLDateType data);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
