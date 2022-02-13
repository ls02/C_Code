#include "SeqList.h"

void Test1()
{
	SeqList s1;

	SeqListInit(&s1);

	SeqListPushBack(&s1, 0);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListFront(&s1, 10);
	SeqListFront(&s1, 20);
	SeqListFront(&s1, 30);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 4, 50);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 4, 60);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 4, 70);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 4, 80);
	SeqListPrint(&s1);

	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 1);
	SeqListPrint(&s1);

	printf("删除：\n");
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopBack(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);
	//SeqListPopFront(&s1);

	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	//SeqListErase(&s1, 1);
	//SeqListPrint(&s1);
	int key = 60;
	int index = 0;
	if (~(index = SeqListFind(&s1, key)))
	{
		printf("%d找到了！下标是：%d\n", key, index);
	}
	else
	{
		printf("没找到！\n");
	}

	SeqListDestroy(&s1);

	printf("完成\n");
}

void Test2()
{
	SeqList s1;

	SeqListInit(&s1);

	SeqListPushBack(&s1, 0);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 3, 30);
	SeqListPrint(&s1);
}

int main()
{
	//Test2();
	Test1();

	//if (3 >= 3)
	//{
	//	printf("1");
	//}

	return 0;
}