#include "List.h"

void TestList1()
{
	List l1;
	
	l1.pHead = ListInit();
	ListPushBack(l1.pHead, 1);
	ListPushBack(l1.pHead, 2);
	ListPushBack(l1.pHead, 3);
	ListPushBack(l1.pHead, 4);
	ListPushBack(l1.pHead, 5);
	ListPrint(l1.pHead);

	ListPushFront(l1.pHead, 0);
	ListPushFront(l1.pHead, -1);
	ListPushFront(l1.pHead, -2);
	ListPushFront(l1.pHead, -3);
	ListPushFront(l1.pHead, -4);
	ListPushFront(l1.pHead, -5);
	ListPrint(l1.pHead);

	ListPopBack(l1.pHead);
	ListPopBack(l1.pHead);
	ListPopBack(l1.pHead);
	ListPrint(l1.pHead);

	ListPopFront(l1.pHead);
	ListPopFront(l1.pHead);
	ListPopFront(l1.pHead);
	ListPrint(l1.pHead);

	ListNode* pos = ListFind(l1.pHead, 0);
	ListErase(pos);
	ListPrint(l1.pHead);

	pos = ListFind(l1.pHead, 1);
	ListErase(pos);
	ListPrint(l1.pHead);

	printf("链表节点个数：%d\n", ListSize(l1.pHead));

	ListDestroy(&l1.pHead);
	printf("完成\n");
}

int main()
{
	TestList1();

	return 0;
}