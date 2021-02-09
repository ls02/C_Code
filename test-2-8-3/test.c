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
		printf("请输入\"我是猪\":>");
		scanf("%s", input);

		if (strcmp(input, "我是猪") == 0)
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
//	printf("请输入\"我是猪\":>");
//	scanf("%s", input);
//	
//	if (strcmp(input, "我是猪") == 0)
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
//	for (i = 1; 10 > i; i++)//表达式一;和表达式二;表达式三分别用分号分隔开来
//	{
//		printf("%d ", i);//语句内容
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//
//	do//不管是否满足条件，先执行一次再看条件
//	{
//		printf("%d\n", i);//执行内容
//		i++;
//	} while (10 > i);//循环条件如果满足条件才继续执行
//
//	printf("%d\n", i);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	while (10 > i)//循环条件
//	{
//		printf("%d ", i);//循环内容
//		i++;//退出循环的条件
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 2;
//
//	switch (a)//这里的a决定进入哪个case的条件
//	{
//	case 1:
//		printf("1\n");
//		break;
//	case 2:
//		printf("2\n");//我们a是二所以从case 2开始依次执行，这是加break的情况
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
//	switch (a)//这里的a决定进入哪个case的条件
//	{
//	case 1:
//		printf("1\n");
//	case 2:
//		printf("2\n");//我们a是二所以从case 2开始依次执行，这是没加break的情况
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
//		printf("请输入”我是猪“:>");
//		scanf("%s", input);
//
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//	}
//
//	return 0;
//}