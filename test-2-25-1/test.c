#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//≤‚ ‘Õ∑Œ≤…æ,Œ≤…æ£¨Œ≤≤Â,—°≤Â°£
void TestSeqList1()
{
	SL s;
	SeqListInit(&s);
	SeqListHendInsert(&s, 22);
	SeqListHendInsert(&s, 23);
	SeqListHendInsert(&s, 24);
	SeqListHendInsert(&s, 25);
	SeqListHendInsert(&s, 26);
	SeqListHendInsert(&s, 27);
	SeqListHendInsert(&s, 28);
	SeqListHendInsert(&s, 29);
	SeqListHendInsert(&s, 30);

	
	//SeqListHendDlest(&s);
	//SeqListHendDlest(&s);
	//SeqListHendDlest(&s);
	//SeqListHendDlest(&s);

	//SeqListBackDelet(&s);
	SeqListBackInsert(&s, 31);
	SeqListBackInsert(&s, 32);
	SeqListBackInsert(&s, 33);
	SeqListBackInsert(&s, 34);
	
	//int ret = SeqListOptInsert(&s, 999, 13);
	SeqListPrint(&s);
	//printf("%d", ret);
}

//
void TestSeqList2()
{
	SL s;

	SeqListInit(&s);

	SeqListHendInsert(&s, 20);
	SeqListHendInsert(&s, 21);
	SeqListHendInsert(&s, 22);
	SeqListHendInsert(&s, 23);

	//int ret = SeqListFind(&s, 0);
	//printf("%d\n", ret);

	SeqListPrint(&s);

	//SeqListDestory(&s);
	//SeqListOptDelete(&s, 2);
	int ret = SeqListOptInsertt(&s, 33, 3);
	printf("%d\n", ret);
	SeqListPrint(&s);

}

int main()
{
	//TestSeqList1();
	TestSeqList2();

	return 0;
}