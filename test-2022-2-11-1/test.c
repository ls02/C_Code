#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef char STDataType;

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

//初始化栈
void StackInit(Stack* pst)
{
	assert(pst);

	STDataType* temp = (STDataType*)malloc(sizeof(STDataType) * 4);

	if (!temp)
	{
		printf("malloc fail\n");

		exit(-1);
	}

	pst->_a = temp;
	pst->_capacity = 4;
	pst->_top = 0;
}

//销毁
void StackDestroy(Stack* pst)
{
	assert(pst);

	free(pst->_a);
	pst->_a = NULL;

	pst->_capacity = pst->_top = 0;
}

//判断是否为空,如果为空返回非零结果,如果不为空返回0
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->_top == 0;
}

//获取栈顶
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->_a[pst->_top - 1];
}

//获取栈中有效元素个数
int StackSize(Stack* pst)
{
	assert(pst);

	return pst->_top;
}

//插入数据
void StackPush(Stack* pst, STDataType x)
{
	assert(pst);

	if (pst->_top == pst->_capacity)
	{
		STDataType* temp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity * 2);

		if (!temp)
		{
			printf("realloc fail\n");

			exit(-1);
		}

		pst->_a = temp;
		pst->_capacity *= 2;
	}

	pst->_a[pst->_top] = x;
	pst->_top++;
}

//删除数据
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->_top--;
}



bool isValid(char* s)
{
	Stack st;

	StackInit(&st);

	while (*s)
	{
		//如果是左括号就入栈
		if (*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st, *s);

			s++;
		}
		//开始匹配
		else
		{
			//判断是否为空
			if (StackEmpty(&st))
			{
				return false;
			}

			char top = StackTop(&st);

			//匹配
			if ((top == '(' && *s != ')')
				|| (top == '[' && *s != ']')
				|| (top == '{' && *s != '}'))
			{
				return false;
			}
			//匹配
			else
			{
				StackPop(&st);
				s++;
			}
		}
	}

	bool ret = StackEmpty(&st);
	StackDestroy(&st);

	return ret;
}


int main()
{


	return 0;
}