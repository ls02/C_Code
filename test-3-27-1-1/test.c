#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	int a = 0;
	int b = 0;

	while (1)
	{
		system("cls");

		printf("������������:");
		scanf("%d%d", &a, &b);

		
		printf("����ǣ�%d\n", a ^ b);
		Sleep(1000);
	}
	
	return 0;
}