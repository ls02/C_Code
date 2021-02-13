#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int count = 0;//ͳ�ƻ�ʣ���ٸ���û��ɨ


void game()//��Ϸʵ��
{
	char mine[ROWS][COLS] = { 0 };//��������
	char show[ROWS][COLS] = { 0 };//������Ϸ�Ļ�����ʾ

	//��ʼ��
	initzeboard(show, ROWS, COLS, '*');
	initzeboard(mine, ROWS, COLS, '0');

	//��ʾ����
	Display_board(show, ROW, COL);
	//Display_board(mine, ROW, COL);

	//����
	random_mine(mine, ROW, COL);
	Display_board(mine, ROW, COL);
	
	//ɨ��
	mine_sweeping(mine, show, ROW, COL);
}

//��ʼ��
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

//��ʾ����
void Display_board(char mine[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	printf("            ɨ����Ϸ\n");
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

//����
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

//ͳ����Χ�׵ĸ���
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

//����
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

//ɨ��
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;

	while (count < row * col - EASILY)
	{
		printf("����������:>");
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
				printf("���ź��㱻ը����\n");
				Display_board(mine, ROW, COL);
				break;
			}
		}
		else
		{                                                                                                                                            
			printf("��������Ч����!\n");
		}
	}

	if (count == row * col - EASILY)
	{
		printf("��ϲ��ɨ�׳ɹ�!\n");
		Display_board(mine, ROW, COL);
	}
}