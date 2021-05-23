#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//��ʼ��ջ
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

//����
void StackDestroy(Stack* pst)
{
	assert(pst);

	free(pst->_a);
	pst->_a = NULL;

	pst->_capacity = pst->_top = 0;
}

//�ж��Ƿ�Ϊ��,���Ϊ�շ��ط�����,�����Ϊ�շ���0
bool StackEmpty(Stack* pst)
{
	assert(pst);

	return pst->_top == 0;
}

//��ȡջ��
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	return pst->_a[pst->_top - 1];
}

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* pst)
{
	assert(pst);

	return pst->_top;
}

//��������
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

//ɾ������
void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));

	pst->_top--;
}