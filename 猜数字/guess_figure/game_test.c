#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	int vaule = rand()%100;//固定随机数范围
	int a = 0;
	printf("请猜1-100的数\n");
	while (1)
	{
		printf("请猜数字>:");
		scanf("%d", &a);
		if (a == vaule)
		{
			printf("猜对了！是>:%d\n",vaule);
			return;
		}
		else if (a > vaule)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("猜小了\n");
		}
	}
}