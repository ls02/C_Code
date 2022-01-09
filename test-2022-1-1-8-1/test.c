#include <stdio.h>

void test1()
{
	int a = 0;
	int b = 0;

	printf("请输入两个数\n");
	printf("整数A：");
	scanf("%d", &a);
	printf("整数B：");
	scanf("%d", &b);

	//printf("平均值是：%f\n", (float)(a + b) / 2);
	printf("百分比是：%f%%", ((float)a / b) * 100);
}

void test2()
{
	int a = 0;
	int b = 0;
	int c = 0;

	printf("请输入两个数\n");
	printf("整数A：");
	scanf("%d", &a);
	printf("整数B：");
	scanf("%d", &b);
	printf("整数C：");
	scanf("%d", &c);

	printf("合计值是：%.4d\n", a + b + c);
	printf("平均值是：%.1f\n", (float)(a + b + c) / 3);
}

void test3()
{
	float height = 0;

	printf("请输入你的身高：");
	scanf("%fl", &height);

	printf("你的标准体重为：%.1f公斤\n", (height - 100) * 0.9);
}

void test4()
{
	int a = 0;
	
	printf("请输入一个整数：");
	scanf("%d", &a);

	if (a % 5)
	{
		printf("%d不能被5整除！\n", a);
	}
}

void test5()
{
	int a = 0;

	printf("请输入一个数：");
	scanf("%d", &a);

	if (a % 2)
	{
		printf("你输入的是一个奇数\n");
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	test5();

	return 0;
}

//void Swap(int* a, int* b)
//{
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//int main()
//{
//    int a = 100;
//    int b = 3;
//
//    printf("交换前：a:%d\tb:%d\n", a, b);
//
//    Swap(&a, &b);
//
//    printf("交换后：a:%d\tb:%d\n", a, b);
//
//    return 0;
//}
//
//int add(int a, int b)
//{
//    int ret = a + b;
//
//    return ret;
//}
//int main()
//{
//    int a = 10;
//    int b = 20;
//
//    int ret = add(a, b);
//
//    printf("%d\n", ret);
//
//    return 0;
//}