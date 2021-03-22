#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	int input = 0;
	srand((size_t)time);

	int i = 30;

	while (i)
	{
		int ret = rand() % 10 + 1;
		//printf("请输入一个值:");
		//scanf("%d", input);
		printf("2 4 8\n");
		printf("%d", ret);
		Sleep(1000);
		system("cls");
		i--;
	}

	return 0;
}