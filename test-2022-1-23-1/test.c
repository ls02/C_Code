#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t Strlen(const char* str)
{
	assert(str);

	const char* temp = str;

	while (*temp++)
	{
		;
	}

	return temp - str - 1;
}


char* Strcpy(char* dest, const char* sour)
{
	assert(dest && sour);

	char* temp = dest;

	while (*dest++ = *sour++)
	{
		;
	}

	return temp;
}

char* Strncpy(char* dest, const char* sour, size_t n)
{
	assert(dest && sour);

	char* temp = dest;

	//拷贝
	while (n && (*dest++ = *sour++))
	{
		n--;
	}

	//如果考完了，n还有值那么剩下的空间会置空
	if (n)
	{
		while (--n)
		{
			*dest++ = 0;
		}
	}

	return temp;
}

char* Strcat(char* dest, const char* sour)
{
	assert(dest && sour);
	
	char* temp = dest;

	while (*dest++)
	{
		;
	}

	dest--;

	while (*dest++ = *sour++)
	{
		;
	}

	return temp;
}

char* Strncat(char* dest, const char* sour, size_t n)
{
	assert(dest && sour);

	char* temp = dest;

	while (*dest++)
	{
		;
	}

	dest--;

	while (n--)
	{
		if (!(*dest++ = *sour++))
		{
			return temp;
		}
	}

	*dest = 0;

	return temp;
}

int Strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);

	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2;
		}

		str1++;
		str2++;
	}

	return 0;
}

int Strncmp(const char* str1, const char* str2, size_t n)
{
	assert(str1 && str2);

	while (n-- && *str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return *str1 - *str2;
		}

		str1++;
		str2++;
	}

	return 0;
}

char* Strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);

	char* cp = (char*)str1;
	char* s1 = NULL;
	char* s2 = NULL;

	//如果字串为空直接返回
	if (!(*str2))
	{
		return (char*)str1;
	}
	 
	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;

		//s2不为空且相等就继续匹配
		while (*s2 && !(*s1 - *s2))
		{
			s1++;
			s2++;
		}

		//如果s2为空说明匹配了就返回
		if (!*s2)
		{
			return cp;
		}

		//未匹配就在字符串上的下一个元素继续匹配
		cp++;
	}

	//未匹配返回空
	return NULL;
}

void test1()
{

	int i = 0;
	int j = 0;

	for (i = 0; i < 11; i++)
	{
		printf("%d ", i);
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}

		printf("1\n");
	}
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[20] = "ab";

	const char* p1 = arr1;


	//printf("%d", Strlen(arr1));
	//printf("%s", strncpy(arr2, arr1, 1));
	//printf("%d", Strncmp(arr1, arr2, 2));
	printf("%s\n", Strstr(arr1, arr2));

	//test1();

	return 0;
}