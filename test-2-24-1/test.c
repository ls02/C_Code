#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

int my_memcmp(void* dest, const void* src, unsigned int count)
{
	assert(dest && src);//断言

	if (!count)
	{
		return 0;
	}

	while (count-- && *(char*)dest == *(char*)src)//abc\0
	{
		++(char*)dest;
		++(char*)src;
	}

	return *(char*)dest - *(char*)src;
}

int main()
{
	char arr1[] = "abc";
	char arr2[] = "abc";

	if ( 0 < my_memcmp(arr1, arr2, 5))
	{
		printf("大于\n");
	}
	else if(0 > my_memcmp(arr1, arr2, 5))
	{
		printf("小于\n");
	}
	else
	{
		printf("等于\n");
	}

	return 0;
}

//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//
//	memmove(arr + 2, arr, 16);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, unsigned int count)
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
//	char arr1[20] = { 0 };
//	char arr2[] = "hello world!";
//	int arr3[10] = { 0 };
//	int arr4[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//
//	memcpy(arr1, arr2, 12);
//	memcpy(arr4 + 2, arr4, 16);
//	printf("%s\n", arr1);
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr4[i]);
//	}
//
//	return 0;
//}