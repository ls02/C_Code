#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//extern int b;
//
//int main()
//{
//
//
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	char *p = (char*)&arr;
//	int i = 0;
//
//	while (10 > i)
//	{
//		*(p + i) = 1;
//		i++;
//	}
//
//	return 0;
//}

//int main()
//{
//	printf("char*=%d\n", sizeof(char*));
//	printf("short*=%d\n", sizeof(short*));
//	printf("int*=%d\n", sizeof(int*));
//	printf("long*=%d\n", sizeof(long*));
//	printf("long long*=%d\n", sizeof(long long*));
//	printf("float*=%d\n", sizeof(float*));
//	printf("double*=%d\n", sizeof(double*));
//
//	return 0;

//int main()
//{
//	int a = 22;
//	int *p = &a;
//
//	printf("%d", *p);
//
//	return 0;
//}

//#define MAX 100//���Ǻ�
//#define ADD(x, y) (x + y)//���Ǵ��κ�
//
//int main()
//{
//	int a = 5;
//	int b = 3;
//
//	int ret = ADD(a, b);
//
//	printf("%d\n", MAX);
//	printf("%d\n", ret);
//
//	return 0;
//}

//int main()
//{
//	register int a = 2;
//	int b = 5;
//
//	return 0;
//}

//extern int Add(int, int);//����������
//
//int main()
//{
//	int a = 5;
//	int b = 3;
//
//	int ret = Add(a, b);
//	printf("ret=%d", ret);
//
//	return 0;
//}

//extern int g_val;
//
//int main()
//{
//	printf("%d", g_val);
//
//	return 0;
//}

//void test1()
//{
//	int a = 0;//û��static���ι��ı���a
//	a++;
//	printf("%d ", a);
//}
//
//void test2()
//{
//	static int a = 0;//��static���ι��ı���a
//	a++;
//	printf("%d ", a);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//
//	while (a < 10)
//	{
//		test1();
//		a++;
//	}
//
//	printf("\n");
//
//	while (b < 10)
//	{
//		test2();
//		b++;
//	}
//
//	return 0;
//}

//typedef int zhangsan;//�����С����������ȡûʲôҪ��
//
//int main()
//{
//	int a = 3;
//	zhangsan b = 2;//С���ͱ����ȼۣ�Ҳ����˵zhangsan����int
//
//	printf("a=%d b=%d", a, b);
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("������:>");
//	scanf("%d", &input);
//
//	switch (input)
//	{
//	case 1:
//		printf("����һ\n");
//	case 2:
//		printf("���ڶ�\n");
//	case 3:
//		printf("������\n");
//	case 4:
//		printf("������\n");
//	case 5:
//		printf("������\n");
//	case 6:
//		printf("������\n");
//	case 7:
//		printf("������\n");
//	default:
//		printf("�������\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	
//	printf("������:>");
//	scanf("%d", &input);
//
//	switch (input)//ѡ������һ�֣�����input������ѡ���Ӧ��case������ֻ��������
//		//���˵�����ַ��ͣ���ʵ�ַ��͵ı��ʾ���������������Ҳ����
//	{
//	case 1://case˵��
//		printf("����һ\n");
//		break;
//	case 2:
//		printf("���ڶ�\n");
//		break;
//	case 3:
//		printf("������\n");
//		break;
//	case 4:
//		printf("������\n");
//		break;
//	case 5:
//		printf("������\n");
//		break;
//	case 6:
//		printf("������\n");
//		break;
//	case 7:
//		printf("������\n");
//		break;
//	default:
//		printf("�������\n");
//		break;
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//
//	while (0 < i)//ѭ��ʮ������ѭ��
//	{
//		if (5 == i)//���i����5���Ǿ�break����ѭ����ִ�У�Ҳ����˵ֻ��ִ��5��
//		{
//			break;
//		}
//		printf("%d\n", i);//���ѭ������ִ�оʹ�ӡi��ֵ
//		i--;//ѭ���˳�������ÿ��ѭ��һ�ξ��Լ�һ���ӽ��˳�������
//	}
//
//	return 0;
//}

//int main()
//{
//	enum
//	{
//		mon1 = 1,
//		mon2,
//		mon3,
//		mon4,
//		mon5,
//		mon6,
//		mon7
//	};
//
//	printf("����%d\n", mon1);
//	printf("����%d\n", mon2);
//	printf("����%d\n", mon3);
//	printf("����%d\n", mon4);
//	printf("����%d\n", mon5);
//	printf("����%d\n", mon6);
//	printf("����%d\n", mon7);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;//�Զ�����������������Զ����������������Զ�����
//	auto int b = 0;//auto int b��int a�ȼۿ���ʡ�Ե���
//
//	return 0;
//}