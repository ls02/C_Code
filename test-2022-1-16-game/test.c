#include "PushBoxGame.h"
#define nullptr ((void*) 0)

int main()
{
	int input = 0;

	do
	{
		system("cls");
		printf("************************\n");
		printf("**** 1. ��ʼ��Ϸ   *****\n");
		printf("**** 0. �˳���Ϸ   *****\n");
		printf("************************\n");
		printf("������(1/0)>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("��Ϸ���˳�\n");
			break;
		default:
			printf("��������Ч���֣�\a\n");
			Sleep(500);
			break;
		}
	} while (input);


	return 0;
}