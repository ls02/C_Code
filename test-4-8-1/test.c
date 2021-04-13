#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void TestSList1()
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 55);
	SListPushBack(&plist, 77);
	SListPushBack(&plist, 66);
	SListPushBack(&plist, 88);
	SListPushBack(&plist, 99);
	SListPushBack(&plist, 11);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);

	SListDestory(plist);

	return;
}

void TestSList2()
{
	SListNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	SListNode* q = SListFind(plist, 0);

	SListPrint(plist);

	printf("%d", q->data);

}

void TestSList3()
{
	SListNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListPrint(plist);

	SListNode* newNode = SListFind(plist, 3);
	SListInsertAfter(newNode, 55);
	SListPrint(plist);

	SListEraseAfter(newNode);
	SListPrint(plist);

	SListDestory(plist);
}

int main()
{
	TestSList3();

	return 0;
}