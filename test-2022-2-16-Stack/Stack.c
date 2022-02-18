#include "Stack.h"

void StackInit(Stack* pSt)
{
	assert(NULL != pSt);

	pSt->data = NULL;
	pSt->capacity = 0;
	pSt->top = 0;
}

void StackDestroy(Stack* pSt)
{
	assert(NULL != pSt);

	free(pSt->data);
	pSt->data = NULL;
	pSt->top = 0;
	pSt->capacity = 0;
}

void StackPush(Stack* pSt, StDataType val)
{
	assert(NULL != pSt);

	//²é¿´ÊÇ·ñÐèÒªÀ©ÈÝ
	if (pSt->top == pSt->capacity)
	{
		size_t newCapacity = pSt->capacity == 0 ? 4 : pSt->capacity * 2;
		if (pSt->capacity)
		{
			StDataType* temp = (StDataType*)realloc(pSt->data, newCapacity * sizeof(StDataType));
			if (NULL == temp)
			{
				printf("À©ÈÝÊ§°Ü£¡\n");

				exit(-1);
			}

			pSt->data = temp;
			pSt->capacity = newCapacity;
		}
		else
		{
			pSt->data = (StDataType*)malloc(sizeof(StDataType) * newCapacity);
			if (NULL == pSt->data)
			{
				printf("ÉêÇëÄÚ´æÊ§°Ü£¡");

				exit(-1);
			}

			pSt->capacity = newCapacity;
		}
	}//end if(À©ÈÝ)
	
	pSt->data[pSt->top] = val;
	pSt->top++;
}

void StackPop(Stack* pSt)
{
	assert(NULL != pSt);

	pSt->top--;
}

StDataType StackTop(Stack* pSt)
{
	assert(NULL != pSt);
	assert(!StackEmpty(pSt));

	return pSt->data[pSt->top - 1];
}

bool StackEmpty(Stack* pSt)
{
	assert(NULL != pSt);

	return pSt->top == 0;
}

size_t StackSize(Stack* pSt)
{
	assert(NULL != pSt);
	
	return pSt->top;
}