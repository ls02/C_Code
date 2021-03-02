#include "test.h"

void game()
{
	 //雷的信息
	//1.布置好雷的情况
	char mine[ROWS][COLS] = {0};//11*11
	//2.排查雷的情况
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	DisplayBoard(mine,ROW,COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
}

void menu()
{
	printf("*************************\n");
	printf("***   1.玩游戏        ***\n");
	printf("***   0.退出游戏      ***\n");
	printf("*************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}