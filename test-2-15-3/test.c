#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse_string(char* str)
{
	char temp = *str;//�ѵ�һ�����ݴ�����ʱ����temp��
	int len = strlen(str);//����ַ����ĳ���

	*str = *(str + len - 1);//���һ���ַ������ݸ��ǵ�һ������
	*(str + len - 1) = 0;//����������һ�����ݷ�'\0'
	if (strlen(str + 1) >= 2)//���㳤���������������Ҫ���������ֻʣһ����λ������ô����Ҳ�����Ǹ�λ�����Բ��ö�
	{
		reverse_string(str + 1);//û���������ľͽ���
	}
	*(str + len - 1) = temp;//����ʱ�������������ݷŵ�str����ȥ
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