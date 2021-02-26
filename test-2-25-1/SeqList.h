#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SlType;
//顺序表
//1、初始化 2、头删 3、尾删 4、头插 5、尾插 

typedef struct SequenceList
{
	SlType* data;
	int size;
	int capacity;
}SL;

//初始化
void SeqListInit(SL* ps);

//尾删
void SeqListBackDelet(SL* ps);

//尾插
void SeqListBackInsert(SL* ps, SlType x);

//头插
void SeqListHendInsert(SL* ps, SlType x);

//头删
void SeqListHendDlest(SL* ps);

//选择插入替换
SlType SeqListOptInserttReplce(SL* ps, SlType x, int seat);

//打印数据
void SeqListPrint(SL* ps);

//检查增容
void SeqListCheckCapacity(SL* ps);

//销毁
void SeqListDestory(SL* ps);

//查找
SlType SeqListFind(SL* ps, int seat);

//选择删除
SlType SeqListOptDelete(SL* ps, int seat);

//选择插入
SlType SeqListOptInsertt(SL* ps, SlType x, int seat);