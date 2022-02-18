#pragma once
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StDataType;

typedef struct Stack
{
	StDataType* data;
	size_t top;
	size_t capacity;
}Stack;

//��ʼ��ջ
extern void StackInit(Stack* pSt);

//����ջ
extern void StackDestroy(Stack* pSt);

//��ջ
extern void StackPush(Stack* pSt, StDataType val);

//��ջ
extern void StackPop(Stack* pSt);

//��ȡջ������
extern StDataType StackTop(Stack* pSt);

//��ȡջ�е����ݸ���
extern size_t StackSize(Stack* pSt);

//���ջ�Ƿ�Ϊ��
extern bool StackEmpty(Stack* pSt);

#endif
