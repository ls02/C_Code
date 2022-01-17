#include "PushBoxGame.h"
#define nullptr ((void*) 0)

int main()
{
	int input = 0;

	do
	{
		system("cls");
		printf("************************\n");
		printf("**** 1. 开始游戏   *****\n");
		printf("**** 0. 退出游戏   *****\n");
		printf("************************\n");
		printf("请输入(1/0)>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		default:
			printf("请输入有效数字！\a\n");
			Sleep(500);
			break;
		}
	} while (input);


	return 0;
}