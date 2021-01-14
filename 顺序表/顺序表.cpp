#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Arr.h"

int main()
{
	arr* aa1 = kon_biao();
	arr* aa2 = kon_biao();
	Pyte tem;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tem);

		chai_ru(aa1, tem);
	}

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &tem);

		chai_ru(aa2, tem);
	}

	//shu_chu(aa1);
	//cx_chai_ru(aa1, 2,6);
	//shu_chu(aa1);

	//sc_fang_hui(aa1, 5);
	//shu_chu(aa1);
	//int c;
	//c=arr_get(aa1,8);
	//shu_chu(aa1);
	//printf("\n%d ",c);

	arr_merge(aa1, aa2);
	shu_chu(aa1);
	shu_chu(aa2);

	return 0;
}