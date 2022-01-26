#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

char* Strtok(char* str, const char* ch)
{
	static char* s1 = NULL;

	//如果str为空就不进行重新赋值，让它保持上一次的形态继续切割
	if (str)
	{
		s1 = str;
	}

	//检查是否为空，如果为空指针说明传的是空指针，或者上一次的字符串已经走完了
	if (!s1)
	{
		return NULL;
	}

	char* temp = s1;

	//查找要切割的字符串
	while (*s1)
	{
		const char* tempch = ch;

		//如果要切割的字符串不为空就继续找
		while (*tempch)
		{
			//如果找到了开始切割
			if (*s1 == *tempch)
			{
				*s1++ = 0;

				//返回切割后的字符串首地址
				return temp;
			}

			tempch++;
		}

		s1++;
	}

	//在这里返回的说明，这个字符串走到尾了，不能再继续访问，置空以防越界
	s1 = NULL;

	//如果未找到要切割的值返回首地址
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