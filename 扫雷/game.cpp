#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

//��Ϸ����
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//��ʼ������
	Initialize_board(mine, ROW, COL,'0');
	Initialize_board(show, ROW, COL, '*');
	//��ӡ����
	exhibit_board(show, ROW, COL);
	//exhibit_board(mine, ROW, COL);
	//������
	assign_mine(mine, ROW, COL);
	exhibit_board(mine, ROW, COL);
	//�ж��Ƿ�����
	determine(mine, show, ROW, COL);

}

//��ʼ������
void Initialize_board(char board[ROWS][COLS], int row, int col, char val)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			board[i][j] = val;//����Ԫ�س�ʼ��
		}
	}
}

//��ӡ����
void exhibit_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);//��ӡ����
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ����
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//��ӡ*
		}
		printf("\n");
	}
}

//������
void assign_mine(char board[ROWS][COLS], int row, int col)
{
	int count = 0;//������
	count = DIFFICULTY;//�����׵�����

	while (count)//�ﵽ����������
	{
		int x = 0;//����x��������
		int y = 0;//����y��������

		x = rand() % row + 1;//���ֵ�����ף���Χ1-9
		y = rand() % col + 1;//���ֵ�����ף���Χ1-9

		if (board[x][y] == '0')//�ж��Ƿ�û�����ù���
		{
			board[x][y] = '1';//���û�����ù��Ͳ���һ����
			count--;//�ɹ������׾ͼ�һ
		}
	}
}

//������
int counter_mine(char mine[ROWS][COLS], int x, int y)
{
	return	mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';//ͳ����Χ���е��ײ�����������

}

//�ж��Ƿ�����
void determine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;//ͳ�����Ƿ�����

	while (count < row * col - DIFFICULTY)//��������������ѭ��
	{
		printf("����������:>");
		scanf("%d %d", &x, &y);
		
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը���ˣ�\n");
				exhibit_board(mine, row, col);
				break;
			}
			else
			{
				int count_mine = counter_mine(mine, x, y);//ͳ���׵ķŻ�ֵ��count_mine
				show[x][y] = count_mine + '0';//show��ʾ��Χ��������
				exhibit_board(show, row, col);
				count++;//û�ȵ��׾ͼ�һֱ����ͼ����ȫ���׾�����ѭ��
			}
		}
		else
		{
			printf("�����������\n");
		}
	}
	if (count == row * col - DIFFICULTY)//�ж��Ƿ�ֻʣ����
	{
		printf("��ϲ�����׳ɹ�!\n");
	}
}