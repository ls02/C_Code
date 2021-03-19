#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strncpy(char* dest, const char* src, size_t n)
{
	assert(dest && src);

	char* str1 = dest;
	const char* str2 = src;

	while (*str2 && n)
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
	char str1[20] = { 0 };
	char str2[] = "hello world";

	my_strncpy(str1, str2, 60);
	printf("%s", str1);

	return 0;
}