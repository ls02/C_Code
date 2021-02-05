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

	printf("请输入字符:");
	gets_s(arr,10);
	putchar('\n');
	printf("请输入旋转次数:");
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
//	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
//	strcpy(tmp, src); //先拷贝一遍
//	strcat(tmp, src); //再连接一遍
//	return strstr(tmp, find) != NULL; //看看找不找得到
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