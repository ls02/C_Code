#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqlist1()
{
	SeqList s;

	SeqListInit(&s);//³õÊ¼»¯
	//SeqListInsert(&s, 0, 0);
	SeqListPushBack(&s, 0);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	//SeqListPushFront(&s, 5);
	//SeqListPushFront(&s, 4);
	//SeqListPushFront(&s, 3);
	//SeqListPushFront(&s, 2);
	//SeqListPushFront(&s, 1);
	//SeqListErase(&s, -1);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopBack(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	SeqListAlter(&s, 3, 666);
	SeqListPrint(&s);
	//SLDateType temp = SeqListFind(&s, 2);
	//printf("%d\n", temp);
	SeqListDestory(&s);//Ïú»Ù
}

int main()
{
	TestSeqlist1();

	return 0;
}