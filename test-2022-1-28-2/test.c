#include <stdio.h>
#include <stdlib.h>

void test4()
{
	int* p1 = (int*)malloc(sizeof(int) * 10);
	if (!p1)
	{
		printf("����ռ�ʧ��\n");
		exit(-1);
	}

	//��һ����ʱ�������洢����ʹ����ʧ��Ҳ����Ӱ��ԭ�еĿռ�
	int* temp = (int*)realloc(p1, sizeof(int) * 20);
	if (!temp)
	{
		printf("�ڴ�����ʧ�ܣ�\n");

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
		printf("����ռ�ʧ��\n");
		exit(-1);
	}

	//��һ����ʱ�������洢����ʹ����ʧ��Ҳ����Ӱ��ԭ�еĿռ�
	int* temp = (int*)realloc(p1, sizeof(int) * 20);
	if (!temp)
	{
		printf("�ڴ�����ʧ�ܣ�\n");

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
	//��ϵͳ�Ķ�������10����С����ʼ����0��������1���������������2������ĸ�����С��10 * sizeof(int) == 10, sizeof(int)
	int* p1 = (int*)calloc(10, sizeof(int));

	//����ڴ��Ƿ�����ɹ�
	if (!p1)
	{
		printf("�ڴ�����ʧ��\n");

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
	//��ϵͳ�Ķ�������10�����ʹ�С�Ŀռ�
	int* p1 = (int*)malloc(sizeof(int) * 10);

	//����ڴ��Ƿ�����ɹ�
	if (!p1)
	{
		printf("�ڴ�����ʧ��\n");

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