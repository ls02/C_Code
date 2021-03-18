#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* my_strncat(char* dest, const char* src, size_t n)
{
	assert(dest && src);
	const char* str2 = src;
	char* str1 = dest;
	
	while (*str1)
	{
		str1++;
	}

	while (str2 && n)
	{
		*str1++ = *str2++;
		n--;
	}

	str1 = NULL;
	str2 = NULL;

	return dest;
}

int main()
{
	char str1[12] = "hello ";
	char str2[] = "world";

	my_strncat(str1, str2, 7);

	printf("%s\n%s", str1, str2);

	return 0;
}