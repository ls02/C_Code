#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int main()
{
	srand((signed)time(NULL));//�������
	int a = 0;
	do
	{
		printf("************************\n");
		printf("***  1.paly  0.exit  ***\n");
		printf("************************\n");
		printf("��ѡ��>:");
		scanf("%d",&a);

		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("�������!\n");
			break;
		}
	} while (a);

	return 0;
}