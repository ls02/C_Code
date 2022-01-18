#include "PushBoxGame.h"

void HelpMan()
{
	system("cls");
	printf("==============================\n");
	printf("\t移动操作\n");
	printf("向上移动：\t↑\tw\n");
	printf("向下移动：\t↓\ts\n");
	printf("向左移动：\t←\ta\n");
	printf("向右移动：\t→\td\n");
	printf("------------------------------\n");
	printf("\t功能性操作\n");
	printf("游戏内回到主菜单：\tz\n");
	printf("==============================\n");
	printf("按任意键退出.......\n");
	_getch();
}

int JudgeVictory(int board[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (5 == board[i][j])
			{
				count++;
			}

			if (count == 4)
			{
				return 1;
			}
		}
	}

	return 0;
}

void MovePlay(int board[ROW][COL], int y, int x)
{
	//看是空地还是存放点
	if (0 == board[y][x])
	{
		board[y][x] = 6;
	}
	else if (3 == board[y][x])
	{
		board[y][x] = 4;
	}
}

void PushBox(int board[ROW][COL], int y, int x, char ch)
{
	//如果箱子在存放点
	if (5 == board[y][x])
	{
		switch (ch)
		{
		case 'w':
			if (0 == board[y - 1][x])
			{
				board[y--][x] = 4;
				board[y][x] = 2;
			}
			else if (3 == board[y - 1][x])
			{
				board[y--][x] = 4;
				board[y][x] = 5;
			}
			break;
		case 's':
			if (0 == board[y + 1][x])
			{
				board[y++][x] = 4;
				board[y][x] = 2;
			}
			else if (3 == board[y + 1][x])
			{
				board[y++][x] = 4;
				board[y][x] = 5;
			}
			break;
		case 'a':
			if (0 == board[y][x - 1])
			{
				board[y][x--] = 4;
				board[y][x] = 2;
			}
			else if (3 == board[y][x - 1])
			{
				board[y][x--] = 4;
				board[y][x] = 5;
			}
			break;
		case 'd':
			if (0 == board[y][x + 1])
			{
				board[y][x++] = 4;
				board[y][x] = 2;
			}
			else if (3 == board[y][x + 1])
			{
				board[y][x++] = 4;
				board[y][x] = 5;
			}
			break;
		}
	}
	//没在存放点
	else if (2 == board[y][x])
	{
		switch (ch)
		{
		case 'w':
			if (0 == board[y - 1][x])
			{
				board[y--][x] = 6;
				board[y][x] = 2;
			}
			else if (3 == board[y - 1][x])
			{
				board[y--][x] = 6;
				board[y][x] = 5;
			}
			break;
		case 's':
			if (0 == board[y + 1][x])
			{
				board[y++][x] = 6;
				board[y][x] = 2;
			}
			else if (3 == board[y + 1][x])
			{
				board[y++][x] = 6;
				board[y][x] = 5;
			}
			break;
		case 'a':
			if (0 == board[y][x - 1])
			{
				board[y][x--] = 6;
				board[y][x] = 2;
			}
			else if (3 == board[y][x - 1])
			{
				board[y][x--] = 6;
				board[y][x] = 5;
			}
			break;
		case 'd':
			if (0 == board[y][x + 1])
			{
				board[y][x++] = 6;
				board[y][x] = 2;
			}
			else if (3 == board[y][x + 1])
			{
				board[y][x++] = 6;
				board[y][x] = 5;
			}
			break;
		}
	}
}


void MovePlayer(int board[ROW][COL])
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (6 == board[i][j])
			{
				x = j;
				y = i;
			}
		}
	}

	do
	{
		DisplayBoard(board);

		switch (_getch())
		{
		case 'w':
		case 'W':
		case 上:
			//判断是在空地，还是在存放点
			if (6 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y - 2][x]) && !(5 == board[y - 2][x]) && !(1 == board[y - 2][x]) && (2 == board[y - 1][x] || 5 == board[y - 1][x]))
				{
					board[y--][x] = 0;
					PushBox(board, y, x, 'w');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y - 1][x] || 3 == board[y - 1][x])
				{
					board[y--][x] = 0;
					MovePlay(board, y, x);
				}
			}
			else if (4 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y - 2][x]) && !(5 == board[y - 2][x]) && !(1 == board[y - 2][x]) && (2 == board[y - 1][x] || 5 == board[y - 1][x]))
				{
					board[y--][x] = 3;
					PushBox(board, y, x, 'w');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y - 1][x] || 3 == board[y - 1][x])
				{
					board[y--][x] = 3;
					MovePlay(board, y, x);
				}
			}

			break;
		case 's':
		case 'S':
		case 下:
			//判断是在空地，还是在存放点
			if (6 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y + 2][x]) && !(5 == board[y + 2][x]) && !(1 == board[y + 2][x]) && (2 == board[y + 1][x] || 5 == board[y + 1][x]))
				{
					board[y++][x] = 0;
					PushBox(board, y, x, 's');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y + 1][x] || 3 == board[y + 1][x])
				{
					board[y++][x] = 0;
					MovePlay(board, y, x);
				}
			}
			else if (4 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y + 2][x]) && !(5 == board[y + 2][x]) && !(1 == board[y + 2][x]) && (2 == board[y + 1][x] || 5 == board[y + 1][x]))
				{
					board[y++][x] = 3;
					PushBox(board, y, x, 's');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y + 1][x] || 3 == board[y + 1][x])
				{
					board[y++][x] = 3;
					MovePlay(board, y, x);
				}
			}
			break;
		case 'a':
		case 'A':
		case 左:
			//判断是在空地，还是在存放点
			if (6 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y][x - 2]) && !(5 == board[y][x - 2]) && !(1 == board[y][x - 2]) && (2 == board[y][x - 1] || 5 == board[y][x - 1]))
				{
					board[y][x--] = 0;
					PushBox(board, y, x, 'a');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y][x - 1] || 3 == board[y][x - 1])
				{
					board[y][x--] = 0;
					MovePlay(board, y, x);
				}
			}
			else if (4 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y][x - 2]) && !(5 == board[y][x - 2]) && !(1 == board[y][x - 2]) && (2 == board[y][x - 1] || 5 == board[y][x - 1]))
				{
					board[y][x--] = 3;
					PushBox(board, y, x, 'a');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y][x - 1] || 3 == board[y][x - 1])
				{
					board[y][x--] = 3;
					MovePlay(board, y, x);
				}
			}
			break;
		case 'd':
		case 'D':
		case 右:
			//判断是在空地，还是在存放点
			if (6 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y][x + 2]) && !(5 == board[y][x + 2]) && !(1 == board[y][x + 2]) && (2 == board[y][x + 1] || 5 == board[y][x + 1]))
				{
					board[y][x++] = 0;
					PushBox(board, y, x, 'd');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y][x + 1] || 3 == board[y][x + 1])
				{
					board[y][x++] = 0;
					MovePlay(board, y, x);
				}
			}
			else if (4 == board[y][x])
			{
				//如果人后面是箱子就移动箱子
				if (!(2 == board[y][x + 2]) && !(5 == board[y][x + 2]) && !(1 == board[y][x + 2]) && (2 == board[y][x + 1] || 5 == board[y][x + 1]))
				{
					board[y][x++] = 3;
					PushBox(board, y, x, 'd');
				}
				//如果人后面不是箱子就移动人
				else if (0 == board[y][x + 1] || 3 == board[y][x + 1])
				{
					board[y][x++] = 3;
					MovePlay(board, y, x);
				}
			}
			break;

		case 'z':
			return;
		}

		if (JudgeVictory(board))
		{
			system("cls");
			DisplayBoard(board);
			printf("恭喜通关！\n");
			printf("按任意键继续\n");
			getchar();
			_getch();
			return;
		}

	} while (1);

}

void DisplayBoard(int board[ROW][COL])
{
	system("cls");

	int i = 0;
	int j = 0;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			switch (board[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("□");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("♂");
				break;
			case 5:
				printf("★");
				break;
			case 6:
				printf("♀");
				break;
			}
		}
		putchar('\n');
	}
}

void Game()
{
	//墙壁：1 ■
	//箱子：2 □
	//箱子存放点：3 ☆
	//人在箱子存放点：4 ♂
	//箱子在箱子存放点：5 ★
	//人：6 ♀ 
	int board[ROW][COL] = { 
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
		{ 1, 0, 2, 0, 0, 1, 0, 2, 0, 1 },
		{ 1, 0, 0, 2, 0, 1, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 1, 1, 1 },
		{ 1, 0, 2, 6, 1, 0, 0, 3, 3, 1 },
		{ 1, 0, 0, 0, 1, 0, 0, 3, 3, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	//DisplayBoard(board);
	MovePlayer(board);
}