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

//�����½ڵ�
extern SListNode* SListBuyNode(SLDataType val);

//����
extern void SListDestroy(SListNode** ppl);

//��ӡ
extern void SListPrint(SListNode* pl);

//���ӿ�
//ͷ��
extern void SListPushFront(SListNode** ppl, SLDataType val);
//β��
extern void SListPushBack(SListNode** ppl, SLDataType val);
//��posλ�ò���
extern void SListInsert(SListNode** ppl, SListNode* pos, SLDataType val);

//ɾ�ӿ�
//ͷɾ
extern void SListPopFront(SListNode** ppl);
//βɾ
extern void SListPopBack(SListNode** ppl);
//ɾ��posλ��
extern void SListErase(SListNode** ppl, SListNode* pos);

//��ӿ�
extern SListNode* SListFind(SListNode* pl, SLDataType val);

#endif 

