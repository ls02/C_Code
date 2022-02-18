#include "Stack.h"

void TestStack1(void)
{
	Stack st1;

	StackInit(&st1);

	StackPush(&st1, 0);
	StackPush(&st1, 1);
	StackPush(&st1, 2);
	StackPush(&st1, 3);
	StackPush(&st1, 4);
	StackPush(&st1, 5);

	while (!StackEmpty(&st1))
	{
		printf("%d ", StackTop(&st1));
		StackPop(&st1);
	}

	StackDestroy(&st1);
}

int main()
{
	TestStack1();

	return 0;
}