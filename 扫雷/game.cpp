#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

//游戏主体
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//初始化棋盘
	Initialize_board(mine, ROW, COL,'0');
	Initialize_board(show, ROW, COL, '*');
	//打印棋盘
	exhibit_board(show, ROW, COL);
	//exhibit_board(mine, ROW, COL);
	//布置雷
	assign_mine(mine, ROW, COL);
	exhibit_board(mine, ROW, COL);
	//判断是否是雷
	determine(mine, show, ROW, COL);

}

//初始化棋盘
void Initialize_board(char board[ROWS][COLS], int row, int col, char val)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = val;//所有元素初始化
		}
	}
}

//打印棋盘
void exhibit_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//打印列数
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印函数
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//打印*
		}
		printf("\n");
	}
}

//布置雷
void assign_mine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;//计算器
	count = DIFFICULTY;//布置雷的数量

	while (count)//达到数量不布置
	{
		int x = 0;//坐标x，行坐标
		int y = 0;//坐标y，列坐标

		x = rand() % row + 1;//随机值布置雷，范围1-9
		y = rand() % col + 1;//随机值布置雷，范围1-9

		if (board[x][y] == '0')//判断是否没被布置过雷
		{
			board[x][y] = '1';//如果没被布置过就布置一颗雷
			count--;//成功布置雷就减一
		}
	}
}

//计数器
int counter_mine(char mine[ROWS][COLS], int x, int y)
{
	return	mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';//统计周围所有的雷并加起来返回

}

//判断是否是雷
void determine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;//统计雷是否被排完

	while (count < row * col - DIFFICULTY)//如果雷排完就跳出循环
	{
		printf("请输入坐标:>");
		scanf("%d %d", &x, &y);
		
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了！\n");
				exhibit_board(mine, row, col);
				break;
			}
			else
			{
				int count_mine = counter_mine(mine, x, y);//统计雷的放回值给count_mine
				show[x][y] = count_mine + '0';//show显示周围的雷数量
				exhibit_board(show, row, col);
				count++;//没踩到雷就减一直到地图上面全是雷就跳出循环
			}
		}
		else
		{
			printf("坐标输入错误！\n");
		}
	}
	if (count == row * col - DIFFICULTY)//判断是否只剩下雷
	{
		printf("恭喜你排雷成功!\n");
	}
}