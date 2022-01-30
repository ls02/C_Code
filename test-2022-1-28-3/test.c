#include <stdio.h>
#include <stdlib.h>

struct A
{
	int i;
	int arr[];//柔性数组必须是最后一个成员变量，且前面必须有一个成员变量。
};

int main()
{
	//不能直接定义，必须定义成指针来使用，把结构体A的大小算进去再加柔性数组的大小
	struct A* pa = (struct A*)malloc(sizeof(struct A) + sizeof(int) * 10);
	if (!pa)
	{
		printf("内存申请失败！\n");
		exit(-1);
	}

	pa->i = 10;
	int i = 0;

	for (i = 0; i < pa->i; i++)
	{
		pa->arr[i] = i;
	}

	for (i = 0; i < pa->i; i++)
	{
		printf("%d ", pa->arr[i]);
	}

	free(pa);
	pa = NULL;

	return 0;
}

//int a = 10;
//
//int main()
//{
//	char* ps1 = "hello";
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	if (!p1)
//	{
//		printf("申请空间失败！\n");
//
//		exit(-1);
//	}
//	static b = 20;
//
//
//	return 0;
//}