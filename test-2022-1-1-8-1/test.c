#include <stdio.h>

void test1()
{
	int a = 0;
	int b = 0;

	printf("������������\n");
	printf("����A��");
	scanf("%d", &a);
	printf("����B��");
	scanf("%d", &b);

	//printf("ƽ��ֵ�ǣ�%f\n", (float)(a + b) / 2);
	printf("�ٷֱ��ǣ�%f%%", ((float)a / b) * 100);
}

void test2()
{
	int a = 0;
	int b = 0;
	int c = 0;

	printf("������������\n");
	printf("����A��");
	scanf("%d", &a);
	printf("����B��");
	scanf("%d", &b);
	printf("����C��");
	scanf("%d", &c);

	printf("�ϼ�ֵ�ǣ�%.4d\n", a + b + c);
	printf("ƽ��ֵ�ǣ�%.1f\n", (float)(a + b + c) / 3);
}

void test3()
{
	float height = 0;

	printf("�����������ߣ�");
	scanf("%fl", &height);

	printf("��ı�׼����Ϊ��%.1f����\n", (height - 100) * 0.9);
}

void test4()
{
	int a = 0;
	
	printf("������һ��������");
	scanf("%d", &a);

	if (a % 5)
	{
		printf("%d���ܱ�5������\n", a);
	}
}

void test5()
{
	int a = 0;

	printf("������һ������");
	scanf("%d", &a);

	if (a % 2)
	{
		printf("���������һ������\n");
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
//    printf("����ǰ��a:%d\tb:%d\n", a, b);
//
//    Swap(&a, &b);
//
//    printf("������a:%d\tb:%d\n", a, b);
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