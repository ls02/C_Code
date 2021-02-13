#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int count = 0;//统计还剩多少格子没被扫


void game()//游戏实现
{
	char mine[ROWS][COLS] = { 0 };//用于埋雷
	char show[ROWS][COLS] = { 0 };//用于游戏的画面显示

	//初始化
	initzeboard(show, ROWS, COLS, '*');
	initzeboard(mine, ROWS, COLS, '0');

	//显示棋盘
	Display_board(show, ROW, COL);
	//Display_board(mine, ROW, COL);

	//埋雷
	random_mine(mine, ROW, COL);
	Display_board(mine, ROW, COL);
	
	//扫雷
	mine_sweeping(mine, show, ROW, COL);
}

//初始化
void initzeboard(char mine[ROWS][COLS], int rows, int cols, char val)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = val;
		}
	}
}

//显示棋盘
void Display_board(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	printf("            扫雷游戏\n");
	printf("---------------------------------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}

	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", mine[i][j]);
		}

		printf("\n");

	}
}

//埋雷
void random_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = EASILY;

	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//统计周围雷的个数
static int statistics_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

//扩张
static void derive(char mine[ROWS][COLS], int x, int y)
{
	if (0 == statistics_mine(mine, x - 1, y - 1) && count < ROW * COL - EASILY)
	{
		mine[x - 1][y - 1] = ' ';
		derive(mine, x - 1, y - 1);
	}
	if (0 == statistics_mine(mine, x - 1, y) && count < ROW * COL - EASILY)
	{
		mine[x - 1][y] = ' ';
		count++;
		derive(mine, x - 1, y);
	}
	if (0 == statistics_mine(mine, x - 1, y + 1) && count < ROW * COL - EASILY)
	{
		mine[x - 1][y + 1] = ' ';
		count++;
		derive(mine, x - 1, y + 1);
		}
	if (0 == statistics_mine(mine, x, y - 1) && count < ROW * COL - EASILY)
	{
		mine[x][y - 1] = ' ';
		count++;
		derive(mine, x, y - 1);
	}
	if (0 == statistics_mine(mine, x, y + 1) && count < ROW * COL - EASILY)
	{
		mine[x][y + 1] = ' ';
		count++;
		derive(mine, x, y + 1);
	}
	if (0 == statistics_mine(mine, x + 1, y - 1) && count < ROW * COL - EASILY)
	{
		mine[x + 1][y - 1] = ' ';
		count++;
		derive(mine, x + 1, y - 1);
	}
	if (0 == statistics_mine(mine, x + 1, y) && count < ROW * COL - EASILY)
	{
		mine[x + 1][y] = ' ';
		count++;
		derive(mine, x + 1, y);
	}
	if (0 == statistics_mine(mine, x + 1, y + 1) && count < ROW * COL - EASILY)
	{
		mine[x + 1][y + 1] = ' ';
		count++;
		derive(mine, x + 1, y + 1);
	}
}

//扫雷
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	while (count < row * col - EASILY)
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);

		if ((1 <= x && x <= row) && (1 <= y && y <= col))
		{
			if (mine[x][y] == '0')
			{
				if (0 == statistics_mine(mine, x, y))
				{
					derive(mine, x, y);
					Display_board(show, ROW, COL);
				}
				else
				{
					int leng = statistics_mine(mine, x, y);
					show[x][y] = leng + '0';
				}
				Display_board(show, COL, ROW);
				count++;
			}
			else
			{
				printf("很遗憾你被炸死了\n");
				Display_board(mine, ROW, COL);
				break;
			}
		}
		else
		{                                                                                                                                            
			printf("请输入有效数字!\n");
		}
	}

	if (count == row * col - EASILY)
	{
		printf("恭喜你扫雷成功!\n");
		Display_board(mine, ROW, COL);
	}
}