#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* temp = dest;

	while (count--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}

	return temp;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "hello ";

	my_memcpy(arr1, arr2, 6);
	printf("%s", arr1);

	return 0;
}

//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* temp = dest;
//
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//
//	return temp;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4 };
//	int i = 0;
//
//	my_memmove(arr1, arr2, 16);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	return 0;
//}

//int my_strlen(const char* str)
//{
//	assert(str);
//	const char* temp = str;
//
//	while (*temp++);
//
//	return temp - str - 1;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	printf("%d", my_strlen(arr));
//
//	return 0;
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//
//	return *str1 - *str2;
//}
//
//int main()
//{
//	int ret = my_strcmp("hello", "world");
//	
//	if (0 < ret)
//	{
//		printf("大于\n");
//	}
//	else if (0 > ret)
//	{
//		printf("小于\n");
//	}
//	else
//	{
//		printf("等于\n");
//	}
//
//	return 0;
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* temp = dest;
//
//	while (*dest++ = *src++);
//
//	return temp;
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "hello world";
//
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}

//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* temp = dest;
//
//	while (*dest++);
//
//	dest--;
//
//	while (*dest++ = *src++);
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
//
//	printf("%s", arr1);
//
//	return 0;
//}

//char* my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	const char* cp = s1;
//
//	if (!*s2)
//	{
//		return (char*)s1;
//	}
//
//	while (*cp)
//	{
//		const char* p1 = cp;
//		const char* p2 = s2;
//
//		while (*p1 == *p2)
//		{
//			p1++;
//			p2++;
//		}
//
//		if (!*p2)
//		{
//			return (char*)cp;
//		}
//
//		cp++;
//	}
//
//	return NULL;
//}
//
//int main()
//{
//
//	char* ret = { 0 };
//	if (ret = my_strstr("abcdef", "cde"))
//	{
//		printf("%s\nYes\n", ret);
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//int find(int arr[][3], int row, int col, int num)
//{
//	assert(arr);
//
//	int i = 0;
//	int j = col - 1;
//
//	while (j > 0 && i < col)
//	{
//		if (arr[i][j] > num)
//		{
//			j--;
//		}
//		else if (arr[i][j] < num)
//		{
//			i++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int arr[][3] = { { 1, 5, 7}, { 2, 6, 8 }, { 4, 6, 9} };
//
//	if (find(arr, 3, 3, 6))
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//void spin_move(char* fine, int count)
//{
//	assert(fine);
//	int i = 0;
//	int j = 0;
//	int len = strlen(fine);
//	int temp = 0;
//
//	for (i = 0; i < count; i++)
//	{
//		temp = fine[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			fine[j] = fine[j + 1];
//		}
//		fine[j] = temp;
//	}
//	
//}
//
//int main()
//{
//	char arr[] = "ABCDF";
//
//	printf("%s\n", arr);
//	spin_move(arr, 3);
//	printf("%s\n", arr);
//
//	return 0;
//}


//int move(char* src, char* find)
//{
//	assert(src && find);
//	char temp[512] = { 0 };
//
//	strcpy(temp, src);
//	strcat(temp, src);
//
//	if (strstr(temp, find))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//	
//}
//
//int main()
//{
//	char s1[] = "AABCD";
//	char s2[] = "BCDAA";
//
//	if (move(s1, s2))
//	{
//		printf("Yes!\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//
//
//void excharnge(int* arr, int n)
//{
//	int i = 0;
//	int j = 0;
//
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] % 2 == 0 && arr[j + 1] % 2 != 0)
//			{
//				int timep = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = timep;
//			}
//		}
//
//
//	}
//}
//
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int timep = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//
//	//for (i = 0; i < timep; i++)
//	//{
//	//	scanf("%d", &arr[i]);
//	//}
//
//
//	excharnge(arr, timep);
//
//
//	for (i = 0; i < timep; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}

//void* my_memset(void* dest, int a, unsigned int count)
//{
//	assert(dest);
//	void* temp = dest;
//
//	while (count--)
//	{
//		*(char*)dest = a;
//		++(char*)dest;
//	}
//
//	return temp;
//}
//
//int main()
//{
//	char arr[10] = { 0 };
//	int i = 0;
//
//	my_memset(arr, '6', 10);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("arr[%d]=%c\n", i, arr[i]);
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr[10] = { 0 };
//	int i = 0;
//
//	void* ret = memset(arr, '6', 10);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("arr[%d]=%c\n", i, arr[i]);
//	}
//
//	return 0;
//}