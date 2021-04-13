#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
//����ڵ����
void SListInsertAfter(SListNode* pos, SLTDateType x);
//����ڵ�ɾ��
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SListNode* plist);