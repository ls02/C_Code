#define _CRT_SECURE_NO_WARNINGS 1
#include "Game.h"

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		printf("****************************\n");
		printf("******    1. play    *******\n");
		printf("******    0. exit    *******\n");
		printf("****************************\n");
		printf("������:>");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			game();//��Ϸ����
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}

	} while (input);

	return 0;
}