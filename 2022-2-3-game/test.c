#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

extern void game();

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		printf("**************************\n");
		printf("***  1. play  0. exit  ***\n");
		printf("***      2. clear      ***\n");
		printf("**************************\n");
		printf("请选择:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//游戏实现
			break;
		case 2://清屏选项
			system("cls");
			break;
		case 0:
			printf("退出程序!\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);

	return 0;
}
//第一步：游戏菜单：可选择开始游戏和退出游戏
//第二步：游戏画面初始化：全部初始化为字符型
//第三步：埋雷：随机埋下地雷
//第四步：扫雷：先判断输入的中心点是否为雷，如果是游戏结束，如果不是继续下一个判断周围有多少雷
//第五步：递归扩展：如果周围都没有雷就递归继续扫荡直到遇到雷
//第六步：完成：整个游戏框架完成