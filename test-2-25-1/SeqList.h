#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SlType;
//˳���
//1����ʼ�� 2��ͷɾ 3��βɾ 4��ͷ�� 5��β�� 

typedef struct SequenceList
{
	SlType* data;
	int size;
	int capacity;
}SL;

//��ʼ��
void SeqListInit(SL* ps);

//βɾ
void SeqListBackDelet(SL* ps);

//β��
void SeqListBackInsert(SL* ps, SlType x);

//ͷ��
void SeqListHendInsert(SL* ps, SlType x);

//ͷɾ
void SeqListHendDlest(SL* ps);

//ѡ������滻
SlType SeqListOptInserttReplce(SL* ps, SlType x, int seat);

//��ӡ����
void SeqListPrint(SL* ps);

//�������
void SeqListCheckCapacity(SL* ps);

//����
void SeqListDestory(SL* ps);

//����
SlType SeqListFind(SL* ps, int seat);

//ѡ��ɾ��
SlType SeqListOptDelete(SL* ps, int seat);

//ѡ�����
SlType SeqListOptInsertt(SL* ps, SlType x, int seat);