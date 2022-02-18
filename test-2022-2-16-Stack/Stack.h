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

//初始化栈
extern void StackInit(Stack* pSt);

//销毁栈
extern void StackDestroy(Stack* pSt);

//入栈
extern void StackPush(Stack* pSt, StDataType val);

//出栈
extern void StackPop(Stack* pSt);

//获取栈顶数据
extern StDataType StackTop(Stack* pSt);

//获取栈中的数据个数
extern size_t StackSize(Stack* pSt);

//检查栈是否为空
extern bool StackEmpty(Stack* pSt);

#endif
