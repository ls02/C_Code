#define _CRT_SECURE_NO_WARNINGS 1
#include "GAME.h"

void game()
{
	int input = 0;
	int guess = rand() % 100 + 1;

	while (1)
	{	
		printf("�������:>");
		scanf("%d", &input);

		if (input > guess)
		{
			printf("�´���\n");
		}
		else if (input < guess)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���,����:%d\n", guess);
			return;
		}
	}
}