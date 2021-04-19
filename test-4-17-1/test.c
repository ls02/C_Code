#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	ListNode* pList = ListCreate();

	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPrint(pList);

	ListPushFront(pList, 0);
	ListPushFront(pList, -1);
	ListPushFront(pList, -2);
	ListPushFront(pList, -3);
	ListPrint(pList);

	ListPopBack(pList);
	ListPopBack(pList);
	ListPrint(pList);

	ListPopFront(pList);
	ListPopFront(pList);
	ListPopFront(pList);
	ListPrint(pList);

	ListNode* temp = ListFind(pList, 1);
	ListInsert(temp, 66);
	ListPrint(pList);
	ListErase(temp);
	ListPrint(pList);

	ListDestory(pList);
	pList = NULL;
}


int main()
{
	TestList1();

	return 0;
}