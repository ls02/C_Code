#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* my_strstr(const char* s1, const char* s2)
{
	assert(s1 && s2);
	const char* cp = s1;
	if (!s2)
	{
		return (char*)s1;
	}

	while (*cp)
	{
		const char* p1 = cp;
		const char* p2 = s2;

		while ((*p1) && (*p2) && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (!*p2)
		{
			return (char*)cp;
		}
		cp++;
	}

	return NULL;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cd";

	char* ret = my_strstr(arr1, arr2);

	if (ret)
	{
		printf("%s\n", ret);
	}
	else
	{
		printf("ÕÒ²»µ½×Ó´®\n");
	}

	return 0;
}

//int my_strncmp(const char* str1, const char* str2, size_t num)
//{
//	while (num && (*str1 == *str2))
//	{
//		if (*str1)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//		num--;
//	}
//	
//	return *str1 - *str2;
//}
//
//int main()
//{
//	int ret = my_strncmp("qbc", "abcb", 3);
//	printf("%d", ret);
//
//	return 0;
//}

//char* my_strncat(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* temp = dest;
//
//	while (*dest)
//	{
//		dest++;
//	}
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//
//	return temp;
//}
//
//int main()
//{
//	char arr1[20] = "##########";
//	char arr2[] = "abc";
//
//	my_strncat(arr1, arr2, 10);
//	printf("%s", arr1);
//
//	return 0;
//}

//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* temp = dest;
//
//	while (count && (*dest++ = *src++))
//	{
//		count--;
//	}
//
//	if (count)
//	{
//		while (--count)
//		{
//			*dest++ = 0;
//		}
//	}
//
//	return temp;
//}
//
//int main()
//{
//	char arr1[20] = "##########";
//	char arr2[] = "abcd";
//
//	my_strncpy(arr1, arr2, 6);
//	printf("%s", arr1);
//
//	return 0;
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (!*str1)
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//
//	return *str1 - *str2;
//}
//
//int main()
//{
//	int ret = my_strcmp("abc", "abc");
//	int str = strcmp("abc", "abc");
//
//	printf("%d %d", ret, str);
//
//	return 0;    
//}

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* temp = dest;
//
//	while (*++dest)
//	{
//		;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return temp;
//}
//
//int main()
//{
//	char arr1[20] = "hello ";
//	char arr2[] = "world";
//
//	my_strcat(arr1, arr2);
//	printf("arr1=%s\narr2=%s", arr1, arr2);
//	
//	return 0;
//}

//char* my_strcpy(char* dest, const char* sre)
//{
//	assert(dest && sre);
//	char* temp = dest;
//
//	while (*dest++ = *sre++)
//	{
//		;
//	}
//
//	return temp;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//
//	my_strcpy(arr1, arr2);
//	printf("arr1=%s\narr2=%s", arr1, arr2);
//
//	return 0;
//}

//unsigned int my_strlen(const char* base)
//{
//	assert(base);
//	const char* p = base;
//
//	while (*++p)
//	{
//		;
//	}
//
//	return p - base;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	unsigned int ret = my_strlen(arr);
//	printf("%d", ret);
//
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1, 2, 3, 4 };
//	int* ptr = (&arr + 1);
//
//	return 0;
//}