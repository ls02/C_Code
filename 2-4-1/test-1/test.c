#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void alternation(char* arr, int n)
{
	int i = 0; 
	int j = 0;

	for (i = 0; i < strlen(arr); i++)

	{
		int temp = 0;

	}
}

int main()
{
	char arr[10] = "0";
	int n = 0;

	printf("�������ַ�:");
	gets_s(arr,10);
	putchar('\n');
	printf("��������ת����:");
	scanf("%d", &n);

	alternation(arr, n);
	

	return 0;
}

//int parallel(const char* arr1, const char* arr2)
//{
//	char temp[1024];
//	strcpy(temp, arr1);
//	strcat(temp, arr1);
//	return strstr(temp, arr2) != NULL;
//}
//
//int main()
//{
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//
//	int temp = parallel(arr1, arr2);
//	printf("%d", temp);
//
//	return 0;
//}

//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
//	strcpy(tmp, src); //�ȿ���һ��
//	strcat(tmp, src); //������һ��
//	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
//}
//
//int main()
//{
//
//	char arr1[] = "AABCD";
//	char arr2[] = "BCDAA";
//	int temp = 0;
//
//	temp = findRound(arr1, arr2);
//
//	printf("%d", temp);
//
//	return 0;
//}