#include "PushBoxGame.h"
#define nullptr ((void*) 0)

int main()
{
	int input = 0;

	do
	{
		system("color 3e");
		system("mode con cols=30 lines=15");
		system("cls");
		printf("************************\n");
		printf("**** 1. ��ʼ��Ϸ   *****\n");
		printf("**** 2. �����ֲ�   *****\n");
		printf("**** 0. �˳���Ϸ   *****\n");
		printf("************************\n");
		printf("������>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//��Ϸ����
			Game();
			break;
		case 2:
			HelpMan();
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