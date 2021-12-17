#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ��
	int _capacity;//����
}Stack;

//��ʼ��ջ
void StackInit(Stack* pst);

//����
void StackDestroy(Stack* pst);

//�ж��Ƿ�Ϊ��,���Ϊ�շŻط�����,�����Ϊ�շ���0
bool StackEmpty(Stack* pst);

//��ȡջ��
STDataType StackTop(Stack* pst);

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pst);

//��������
void StackPush(Stack* pst, STDataType x);

//ɾ������
void StackPop(Stack* pst);