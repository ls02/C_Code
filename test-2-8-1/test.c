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

//#define MAX 100//这是宏
//#define ADD(x, y) (x + y)//这是带参宏
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

//extern int Add(int, int);//函数的声明
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
//	int a = 0;//没被static修饰过的变量a
//	a++;
//	printf("%d ", a);
//}
//
//void test2()
//{
//	static int a = 0;//被static修饰过的变量a
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

//typedef int zhangsan;//这里的小名可以随意取没什么要求
//
//int main()
//{
//	int a = 3;
//	zhangsan b = 2;//小名和本名等价，也就是说zhangsan就是int
//
//	printf("a=%d b=%d", a, b);
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("请输入:>");
//	scanf("%d", &input);
//
//	switch (input)
//	{
//	case 1:
//		printf("星期一\n");
//	case 2:
//		printf("星期二\n");
//	case 3:
//		printf("星期三\n");
//	case 4:
//		printf("星期四\n");
//	case 5:
//		printf("星期五\n");
//	case 6:
//		printf("星期六\n");
//	case 7:
//		printf("星期天\n");
//	default:
//		printf("输入错误！\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//	
//	printf("请输入:>");
//	scanf("%d", &input);
//
//	switch (input)//选择语句的一种，根据input的内容选择对应的case，这里只能用整形
//		//如果说能用字符型，其实字符型的本质就是整形所以在这也能用
//	{
//	case 1://case说明
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期天\n");
//		break;
//	default:
//		printf("输入错误！\n");
//		break;
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 10;
//
//	while (0 < i)//循环十次跳出循环
//	{
//		if (5 == i)//如果i等于5我们就break跳出循环不执行，也就是说只会执行5次
//		{
//			break;
//		}
//		printf("%d\n", i);//如果循环还在执行就打印i的值
//		i--;//循环退出条件，每次循环一次就自减一来接近退出条件。
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
//	printf("星期%d\n", mon1);
//	printf("星期%d\n", mon2);
//	printf("星期%d\n", mon3);
//	printf("星期%d\n", mon4);
//	printf("星期%d\n", mon5);
//	printf("星期%d\n", mon6);
//	printf("星期%d\n", mon7);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;//自动变量进这个作用域自动创建，出作用域自动销毁
//	auto int b = 0;//auto int b和int a等价可以省略掉。
//
//	return 0;
//}