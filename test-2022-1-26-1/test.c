#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* Strtok(char* str, const char* ch)
{
	static char* s1 = NULL;

	//���strΪ�վͲ��������¸�ֵ������������һ�ε���̬�����и�
	if (str)
	{
		s1 = str;
	}

	//����Ƿ�Ϊ�գ����Ϊ��ָ��˵�������ǿ�ָ�룬������һ�ε��ַ����Ѿ�������
	if (!s1)
	{
		return NULL;
	}

	char* temp = s1;

	//����Ҫ�и���ַ���
	while (*s1)
	{
		const char* tempch = ch;

		//���Ҫ�и���ַ�����Ϊ�վͼ�����
		while (*tempch)
		{
			//����ҵ��˿�ʼ�и�
			if (*s1 == *tempch)
			{
				*s1++ = 0;

				//�����и����ַ����׵�ַ
				return temp;
			}

			tempch++;
		}

		s1++;
	}

	//�����ﷵ�ص�˵��������ַ����ߵ�β�ˣ������ټ������ʣ��ÿ��Է�Խ��
	s1 = NULL;

	//���δ�ҵ�Ҫ�и��ֵ�����׵�ַ
	return temp;
}

void test1()
{
	char str1[20] = { 0 }; 
	char ch[] = " ";

	printf("%p\n%p\n", str2, strtok(str2, ch));
	printf("%p", strtok(NULL, ch));

}

void test2()
{
	char str1[20] = { 0 };
	char str2[] = "abc ddd eeee";
	char ch[] = " ";
	char* token = NULL;
	

	for (token = Strtok(str2, ch); token; token = Strtok(NULL, ch))
	{
		printf("%s\n", token);
	}
}

int main()
{
	//test1();
	test2();

	return 0;
}