#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


int main()
{
	//int arr[10] = { 1,6,3,9,18,5,22,98,12,14 };
	////mao_pao(arr,10);
	////xuan_ze(arr, 10);
	////cha_ru(arr, 10);
	////kuai_su(arr, 0,9);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ",arr[i]);
	//}
	//xs aa[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	scanf("%d %s", &aa[i].id, &aa[i].name);
	//}

	//mao_pao1(aa, 10);

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d %s\n", aa[i].id, aa[i].name);
	//}

	arr* a1 = chushihua();
	Pyte tem;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tem);

		chai_ru(a1, tem);
	}

	mao_pao22(a1->defi, a1->len);
	shu_chu(a1);
	
	return 0;
}