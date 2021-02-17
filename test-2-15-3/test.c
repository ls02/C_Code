#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse_string(char* str)
{
	char temp = *str;//把第一个内容存在临时变量temp里
	int len = strlen(str);//获得字符串的长度

	*str = *(str + len - 1);//最后一个字符的内容覆盖第一个内容
	*(str + len - 1) = 0;//覆盖完成最后一个内容放'\0'
	if (strlen(str + 1) >= 2)//计算长度如果还有两个就要交换，如果只剩一个它位置再怎么逆向也还是那个位置所以不用动
	{
		reverse_string(str + 1);//没被交换过的就交换
	}
	*(str + len - 1) = temp;//把临时变量里面存的内容放到str里面去
}

int main()
{
	char arr[] = "abcdefg";

	reverse_string(arr);
	printf("%s", arr);

	return 0;
}

//char* My_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* p = dest;
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return p;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//
//	My_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	
//	return 0;
//}