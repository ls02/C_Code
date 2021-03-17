#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int my_atoi(char* str)
{
	assert(str);

	int flag = 1;
	long long ret = 0;

	while (isspace(*str))
	{
		str++;
	}

	if (!*str)
	{
		return 0;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	while (isdigit(*str))
	{
		ret = ret * 10 + flag * (*str - '0');

		if (!*str)
		{
			return 0;
		}

		str++;
	}

	if (*str)
	{
		return (int)ret;
	}
	else
	{
		return (int)ret;
	}
}

int main()
{
	char* str = "1a21312";
	int i  = my_atoi(str);
	
	printf("%d", i);

	return 0;
}