#define _CRT_SECURE_NO_WARNINGS 1
#include "GAME.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		printf("***********************\n");
		printf("**** 1.play 0.exit ****\n");
		printf("***********************\n");
		printf("��ѡ��:>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default :
			printf("ѡ�����������ѡ��!\n");
		}
	} while (input);

	return 0;
}

//int main()
//{
//	char input[20] = "0";
//	int i = 0;
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:>");
//		scanf("%s", &input);
//		if (strcmp(input, "123456789") == 0)
//		{
//			printf("������ȷ!��¼�ɹ���\n");
//		}
//	}
//	
//	if (3 == i)
//	{
//		printf("������������˳�����!");
//	}
//
//	return 0;
//}

//int main()
//{
//	printf("Hello world\n");
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int input = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int leftr = 0;
//	int right = sz - 1;
//
//	scanf("%d", &input);
//
//	while (leftr <= right)
//	{
//		int mid = (leftr + right) / 2;
//
//		if (arr[mid] > input)
//		{
//			right--;
//		}
//		else if (arr[mid] < input)
//		{
//			leftr++;
//		}
//		else
//		{
//			printf("�е��ˣ��±꣺%d,��ֵ:%d\n", mid, arr[mid]);
//			break;
//		}
//	}
//
//	if (leftr > right)
//	{
//		printf("û�ҵ�\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "bit bit bit bit";
//	char arr2[] = "###############";
//
//	int right = strlen(arr1) - 1;
//	int left = 0;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++;
//		right--;
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 2;
//
//	if (1 == a)
//	if (2 == b)
//		printf("666\n");
//	else
//		printf("222\n");
//}

//int main()
//{
//	int a = 20;
//
//	if (18 <= a && 30 > a)
//	{
//		printf("����\n");
//	}
//	else if (30 <= a && 60 > a)
//	{
//		printf("����\n");
//	}
//	else if (60 <= a && 100 > a)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("�ϲ���\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 18;
//
//	if (18 <= a)
//		printf("����\n");
//	printf("666\n");
//	else
//		printf("δ����\n");
//
//	return 0;
//}