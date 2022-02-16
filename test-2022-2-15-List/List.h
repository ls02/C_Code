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

//�½�һ���ڵ�
extern ListNode* ListNewNode(LtDataType val);

//��ʼ������
extern ListNode* ListInit();

//����һ������
extern void ListDestroy(ListNode** pHead);

//��ӡ����
extern void ListPrint(ListNode* pHead);

//��ȡ����Ľڵ����
extern size_t ListSize(ListNode* pHead);

//���ӿ�
//ͷ��
void ListPushFront(ListNode* pHead, LtDataType val);
//β��
void ListPushBack(ListNode* pHead, LtDataType val);
//posλ�ò���
extern void ListInsert(ListNode* pos, LtDataType val);

//ɾ�ӿ�
//ͷɾ
extern void ListPopFront(ListNode* pHead);
//β��
extern void ListPopBack(ListNode* pHead);
//posλ��ɾ��
extern void ListErase(ListNode* pos);

//��ӿ�
extern ListNode* ListFind(ListNode* pHead, LtDataType key);

#endif