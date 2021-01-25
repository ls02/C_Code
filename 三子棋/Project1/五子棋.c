#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include "test.h"
#include <stdlib.h>
#include <time.h>

void menu()
{
		printf("*********************************************\n");
		printf("***    1.开始游戏         0.退出游戏      ***\n");
		printf("*********************************************\n");
}

void game()
{
	//游戏画面
	char ret;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//棋盘的制作
	while (1)
	{
		//玩家下棋
		Wan_Jia(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家输赢
		ret = Pan_Duan1(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Dian_Nao(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑输赢
		ret = Pan_Duan1(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("电脑赢了！\n");
	}
	else if (ret == '*') 
	{
		printf("玩家赢了！\n");
	}
	else
	{
		printf("平局！\n");
	}
}

int main()
{
	//1.选择界面   2.游戏界面  3.界面的交互  4.游戏的操作逻辑 5.判断棋是否有重复的下棋操作在同一地点  6.判断游戏状态

	int u_a=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();

		printf("请选择>:");
		scanf("%d", &u_a);

		switch (u_a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请输入有效数字！\n");
			break;
		}
	} while (u_a);
	

}