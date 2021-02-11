#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

//游戏菜单
void menu_play()
{
	printf("*********************\n");
	printf("*** 1.play 0.exit ***\n");
	printf("*********************\n");
}

//游戏主体:
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	//棋盘初始化
	Board_Initze(board, ROW, COL);
	//棋盘打印
	Display_Board(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		player(board, ROW, COL);
		//打印棋盘
		Display_Board(board, ROW, COL);
		ret = judge(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		automan(board, ROW, COL);
		Display_Board(board, ROW, COL);
		ret = judge(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}
	}

	if (ret == '#')
	{
		Display_Board(board, ROW, COL);
		printf("玩家赢!\n");
	}
	else if (ret == '*')
	{
		Display_Board(board, ROW, COL);
		printf("电脑赢\n");
	}
	else
	{
		Display_Board(board, ROW, COL);
		printf("平局\n");
	}

}

//棋盘初始化
void Board_Initze(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Display_Board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	system("cls");//每次打印清屏

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);

			if (j < col - 1)
			printf("|");
		}

		printf("\n");

		if (i < col - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");

				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
	printf("\n");
}

void player(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家：\n");
		printf("请下棋:>");
		scanf("%d%d", &x, &y);

		if ((0 < x && x <= col) && (0 < y && y <= row))//判断是否正确输入
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				return;
			}
			else
			{
				printf("这位置有棋子了\n");
			}
			
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	
}

//电脑人
void automan(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if ((0 <= x && x <= row) && (0 <= y && y <= col))
		{
			if (board[x][y] == ' ')
			{
				board[x][y] = '*';
				return;
			}
		}
	}
}

//判断棋盘是否满了
static int bitbare(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	
	return 1;
}

//判断输赢
char judge(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//判断是否平局
	if (bitbare(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}
