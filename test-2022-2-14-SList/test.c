#include "SList.h"

void Test1()
{
	SListNode* l1 = NULL;

	SListPushBack(&l1, 1);
	SListPushBack(&l1, 2);
	SListPushBack(&l1, 3);
	SListPushBack(&l1, 4);
	SListPushBack(&l1, 5);
	SListPrint(l1);

	SListPushFront(&l1, 0);
	SListPushFront(&l1, -1);
	SListPushFront(&l1, -2);
	SListPushFront(&l1, -3);
	SListPushFront(&l1, -4);
	SListPushFront(&l1, -5);
	SListPrint(l1);

	SListPopBack(&l1);
	SListPopBack(&l1);
	SListPrint(l1);

	SListPopFront(&l1);
	SListPopFront(&l1);
	SListPrint(l1);

	SListNode* temp = SListFind(l1, 0);
	SListErase(&l1, temp);
	SListPrint(l1);
	temp = SListFind(l1, -1);
	SListErase(&l1, temp);
	SListPrint(l1);


	SListDestroy(&l1);
	printf("Íê³É\n");
}

int main()
{
	Test1();

	return 0;
}