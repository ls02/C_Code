#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include "test.h"
#include <stdlib.h>
#include <time.h>

void menu()
{
		printf("*********************************************\n");
		printf("***    1.��ʼ��Ϸ         0.�˳���Ϸ      ***\n");
		printf("*********************************************\n");
}

void game()
{
	//��Ϸ����
	char ret;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//���̵�����
	while (1)
	{
		//�������
		Wan_Jia(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж������Ӯ
		ret = Pan_Duan1(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Dian_Nao(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ�����Ӯ
		ret = Pan_Duan1(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '#')
	{
		printf("����Ӯ�ˣ�\n");
	}
	else if (ret == '*') 
	{
		printf("���Ӯ�ˣ�\n");
	}
	else
	{
		printf("ƽ�֣�\n");
	}
}

int main()
{
	//1.ѡ�����   2.��Ϸ����  3.����Ľ���  4.��Ϸ�Ĳ����߼� 5.�ж����Ƿ����ظ������������ͬһ�ص�  6.�ж���Ϸ״̬

	int u_a=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();

		printf("��ѡ��>:");
		scanf("%d", &u_a);

		switch (u_a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������Ч���֣�\n");
			break;
		}
	} while (u_a);
	

}