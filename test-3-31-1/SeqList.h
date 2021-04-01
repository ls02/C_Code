#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDateType;

typedef struct SeqList
{
	SLDateType* s;//����
	size_t size;//ʵ������
	size_t capacity;//�ܹ�����
}SeqList;

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);//��ʼ��
void SeqListDestory(SeqList* ps);//����

void SeqListPrint(SeqList* ps);//��ӡ
void SeqListPushBack(SeqList* ps, SLDateType x);//ĩβ���
void SeqListPushFront(SeqList* ps, SLDateType x);//ͷ�����
void SeqListPopFront(SeqList* ps);//ͷ��ɾ��
void SeqListPopBack(SeqList* ps);//ĩβɾ��

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
//˳����޸�
void SeqListAlter(SeqList* ps, size_t x, SLDateType data);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
