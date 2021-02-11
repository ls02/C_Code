#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

extern void menu_play();
extern void game();

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu_play();
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//游戏主体
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}

	} while (input);

	return 0;
}