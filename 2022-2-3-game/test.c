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
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//��Ϸʵ��
			break;
		case 2://����ѡ��
			system("cls");
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default:
			printf("�����������������!\n");
			Sleep(1000);
			system("cls");
			break;
		}
	} while (input);

	return 0;
}
//��һ������Ϸ�˵�����ѡ��ʼ��Ϸ���˳���Ϸ
//�ڶ�������Ϸ�����ʼ����ȫ����ʼ��Ϊ�ַ���
//�����������ף�������µ���
//���Ĳ���ɨ�ף����ж���������ĵ��Ƿ�Ϊ�ף��������Ϸ������������Ǽ�����һ���ж���Χ�ж�����
//���岽���ݹ���չ�������Χ��û���׾͵ݹ����ɨ��ֱ��������
//����������ɣ�������Ϸ������