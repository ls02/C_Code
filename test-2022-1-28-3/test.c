#include <stdio.h>
#include <stdlib.h>

struct A
{
	int i;
	int arr[];//����������������һ����Ա��������ǰ�������һ����Ա������
};

int main()
{
	//����ֱ�Ӷ��壬���붨���ָ����ʹ�ã��ѽṹ��A�Ĵ�С���ȥ�ټ���������Ĵ�С
	struct A* pa = (struct A*)malloc(sizeof(struct A) + sizeof(int) * 10);
	if (!pa)
	{
		printf("�ڴ�����ʧ�ܣ�\n");
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
//		printf("����ռ�ʧ�ܣ�\n");
//
//		exit(-1);
//	}
//	static b = 20;
//
//
//	return 0;
//}