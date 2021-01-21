#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	srand((signed)time(NULL));//随机种子
	int a = 0;
	do
	{
		printf("************************\n");
		printf("***  1.paly  0.exit  ***\n");
		printf("************************\n");
		printf("请选择>:");
		scanf("%d",&a);

		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出程序！\n");
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (a);

	return 0;
}