#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main()
{
	char input[20] = "0";


	system("shutdown -s -t 60");
	while (1)
	{
		printf("������\"������\":>");
		scanf("%s", input);

		if (strcmp(input, "������") == 0)
		{
			break;
		}
	}

	system("shutdown -a");

	return 0;
}

//int main()
//{
//	char input[20] = "0";
//
//	system("shutdown -s -t 60");
//	
//	flag:
//	printf("������\"������\":>");
//	scanf("%s", input);
//	
//	if (strcmp(input, "������") == 0)
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto flag;
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1; 10 > i; i++)//���ʽһ;�ͱ��ʽ��;���ʽ���ֱ��÷ֺŷָ�����
//	{
//		printf("%d ", i);//�������
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//
//	do//�����Ƿ�������������ִ��һ���ٿ�����
//	{
//		printf("%d\n", i);//ִ������
//		i++;
//	} while (10 > i);//ѭ������������������ż���ִ��
//
//	printf("%d\n", i);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	while (10 > i)//ѭ������
//	{
//		printf("%d ", i);//ѭ������
//		i++;//�˳�ѭ��������
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 2;
//
//	switch (a)//�����a���������ĸ�case������
//	{
//	case 1:
//		printf("1\n");
//		break;
//	case 2:
//		printf("2\n");//����a�Ƕ����Դ�case 2��ʼ����ִ�У����Ǽ�break�����
//		break;
//	case 3:
//		printf("3\n");
//		break;
//	case 4:
//		printf("4");
//		break;
//	default:
//
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 2;
//
//	switch (a)//�����a���������ĸ�case������
//	{
//	case 1:
//		printf("1\n");
//	case 2:
//		printf("2\n");//����a�Ƕ����Դ�case 2��ʼ����ִ�У�����û��break�����
//	case 3:
//		printf("3\n");
//	case 4:
//		printf("4");
//	}
//
//	return 0;
//}

//int main()
//{
//	int b = 1;
//	int c = b % 3;
//	switch
//
//	return 0;
//}

//int main()
//{
//	char input[20] = "0";
//
//	system("shutdown -s -t 60");
//
//	while (1)
//	{
//		printf("�����롱������:>");
//		scanf("%s", input);
//
//		if (strcmp(input, "������") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//
//	return 0;
//}