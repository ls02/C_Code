#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//头删尾删，头插尾插
void SListTest1()
{
	SListNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	SListpopFront(&plist);
	SListpopFront(&plist);
	SListpopFront(&plist);
	SListpopFront(&plist);
	SListpopFront(&plist);

	SListpopBack(&plist);
	SListpopBack(&plist);
	SListpopBack(&plist);
	SListNode* s1 = SListFind(plist, 2);

	printf("%d\n", s1->data);

	SListPrint(plist);
}

//查找，pos位置插入，和pos位置删除
void SListTest2()
{
	SListNode* plist = NULL;
	SListNode* ptemp = NULL;
	int i = 0;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	ptemp = plist;
	for (i = 0; i < 1 && ptemp; i++)
	{
		ptemp = ptemp->Next;
	}

	SListEraseAfter(ptemp);

	SListPrint(plist);

}

int main()
{
	SListTest2();

	return 0;
}