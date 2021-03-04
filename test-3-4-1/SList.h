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

//��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);

//�������ӡ
void SListPrint(SListNode* plist);

///�������β��
void SListPushBack(SListNode** pplist, SLTDateType x);

//�������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);

//�������ͷɾ
void SListpopFront(SListNode** pplist);

//�������βɾ
void SListpopBack(SListNode** pplis);

//������Ĳ���
SListNode* SListFind(SListNode* plist, SLTDateType x);

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x);

//ɾ��pos֮���ֵ
void SListEraseAfter(SListNode* pos);
