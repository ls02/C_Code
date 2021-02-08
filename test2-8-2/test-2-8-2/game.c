#define _CRT_SECURE_NO_WARNINGS 1
#include "GAME.h"

void game()
{
	int input = 0;
	int guess = rand() % 100 + 1;

	while (1)
	{	
		printf("请猜数字:>");
		scanf("%d", &input);

		if (input > guess)
		{
			printf("猜大了\n");
		}
		else if (input < guess)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了,数字:%d\n", guess);
			return;
		}
	}
}