#include "test.h"

void game()
{
	 //�׵���Ϣ
	//1.���ú��׵����
	char mine[ROWS][COLS] = {0};//11*11
	//2.�Ų��׵����
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ����
	DisplayBoard(mine,ROW,COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//ɨ��
	FindMine(mine, show, ROW, COL);
}

void menu()
{
	printf("*************************\n");
	printf("***   1.����Ϸ        ***\n");
	printf("***   0.�˳���Ϸ      ***\n");
	printf("*************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�������!\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}