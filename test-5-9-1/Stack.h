#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	int _top;//栈顶
	int _capacity;//容量
}Stack;

//初始化栈
void StackInit(Stack* pst);

//销毁
void StackDestroy(Stack* pst);

//判断是否为空,如果为空放回非零结果,如果不为空返回0
bool StackEmpty(Stack* pst);

//获取栈顶
STDataType StackTop(Stack* pst);

//获取栈中有效元素个数
int StackSize(Stack* pst);

//插入数据
void StackPush(Stack* pst, STDataType x);

//删除数据
void StackPop(Stack* pst);