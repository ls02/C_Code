#include <stdio.h>
#include <stdlib.h>

void test4()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (!p1)
	{
		printf("申请空间失败\n");
		exit(-1);
	}

	//用一个临时变量来存储，即使开辟失败也不会影响原有的空间
	int* temp = (int*)realloc(p1, sizeof(int) * 20);
	if (!temp)
	{
		printf("内存申请失败！\n");

		exit(-1);
	}

	p1 = temp;
	temp = NULL;

	int i = 0;

	for (i = 0; i < 20; i++)
	{
		p1[i] = i;
	}

	for (i = 0; i < 20; i++)
	{
		printf("%d ", p1[i]);
	}

	free(p1);
	p1 = NULL;
}

void test3()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (!p1)
	{
		printf("申请空间失败\n");
		exit(-1);
	}

	//用一个临时变量来存储，即使开辟失败也不会影响原有的空间
	int* temp = (int*)realloc(p1, sizeof(int) * 20);
	if (!temp)
	{
		printf("内存申请失败！\n");

		exit(-1);
	}

	p1 = temp;
	temp = NULL;

	int i = 0;

	for (i = 0; i < 20; i++)
	{
		p1[i] = i;
	}

	for (i = 0; i < 20; i++)
	{
		printf("%d ", p1[i]);
	}
}

void test2()
{
	//向系统的堆中申请10个大小并初始化成0，而参数1是申请个数，参数2是申请的个数大小：10 * sizeof(int) == 10, sizeof(int)
	int* p1 = (int*)calloc(10, sizeof(int));

	//检查内粗是否申请成功
	if (!p1)
	{
		printf("内存申请失败\n");

		exit(-1);
	}

	int i = 0;


	for (i = 0; i < 10; i++)
	{
		printf("%d ", p1[i]);
	}
}

void test1()
{
	//向系统的堆中申请10个整型大小的空间
	int* p1 = (int*)malloc(sizeof(int) * 10);

	//检查内粗是否申请成功
	if (!p1)
	{
		printf("内存申请失败\n");

		exit(-1);
	}

	int i = 0;

	for (i = 0; i < 10; i++)
	{
		p1[i] = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", p1[i]);
	}

}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}