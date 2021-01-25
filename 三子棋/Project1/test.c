#define _CRT_SECURE_NO_DEPRECATE 1
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL],int row,int col)
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
	putchar('\n');
}

void  DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
			if (j < col - 1)
			{
				printf("|");
			}
			
		}
		putchar('\n');
	}
	putchar('\n');
}

void Wan_Jia(char board[ROW][COL],int row,int col)
{
	int x,y;
	printf("���:>\n");

	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d %d", &x,&y);
		if (x>=1&&x<=row&&y>=1&&y<=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("���λ���Ѿ���������\n");
			}
		}
		else
		{
			printf("�����λ�ò��������ڣ�����������\n");
		}
	}
	
}

void Dian_Nao(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("������:>\n");
	
	while(1)
	{
		x = rand()%row;
		y = rand()%col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}
//����1��ʾ��������
//����0����ʾ����û��
int Pan_Duan(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
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

char Pan_Duan1(char board[ROW][COL], int row, int  col)
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
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (Pan_Duan(board, ROW, COL)==1)
	{
		return 'Q';
	}
	return 'C';
}