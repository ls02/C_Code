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

//��ʼ��
extern void SeqListInit(SeqList* ps);

//����
extern void SeqListDestroy(SeqList* ps);

//�������
extern void SeqListCheckyCapacity(SeqList* ps);

//��ӡ����
extern void SeqListPrint(SeqList* ps);

//���ӿ�
//β��
extern void SeqListPushBack(SeqList* ps, DataType val);
//ͷ��
extern void SeqListFront(SeqList* ps, DataType val);
//Posλ�ò���
extern void SeqListInsert(SeqList* ps, size_t pos, DataType val);

//ɾ�ӿ�
//βɾ
extern void SeqListPopBack(SeqList* ps);
//ͷɾ
extern void SeqListPopFront(SeqList* ps);
//ɾposλ��
extern void SeqListErase(SeqList* ps, size_t pos);

//���ҽӿ�
extern int SeqListFind(SeqList* ps, DataType key);

#endif
