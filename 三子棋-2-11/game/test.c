#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

extern void menu_play();
extern void game();

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu_play();
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//��Ϸ����
			break;
		case 0:
			printf("�˳�����!\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;
		}

	} while (input);

	return 0;
}