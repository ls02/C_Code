#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = NULL;

	int *ptr = (int*)realloc(p, 40);
	if (ptr)
	{
		p = ptr;
	}
	else
	{
		printf("�ڴ�����ʧ��!\n");

		return 0;
	}

	return 0;
}

//int main()
//{
//	int* p = NULL;
//	int i = 0;
//
//	int* ptr = (int*)calloc(40, 4);
//
//	if (ptr)
//	{
//		p = ptr;
//	}
//	else
//	{
//		printf("�����ڴ�ʧ��!");
//
//		return 0;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//	int* p = NULL;//��ֹ��ΪҰָ��
//	int i = 0;
//
//	int* ptr = (int*)malloc(NULL);//����40���ֽ�
//	if (ptr != NULL)//�ж��Ƿ�����ɹ�
//	{
//		p = ptr;
//	}
//	else
//	{
//		printf("�����ڴ�ʧ��!");
//		return 0;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	return 0;
//}