#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	int vaule = rand()%100;//�̶��������Χ
	int a = 0;
	printf("���1-100����\n");
	while (1)
	{
		printf("�������>:");
		scanf("%d", &a);
		if (a == vaule)
		{
			printf("�¶��ˣ���>:%d\n",vaule);
			return;
		}
		else if (a > vaule)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��С��\n");
		}
	}
}