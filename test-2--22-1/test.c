#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

int my_memcmp(void* dest, const void* src, unsigned int count)
{
	assert(dest && src);

	if (!count)
	{
		return 0;
	}

	while (count-- && *(char*)dest == *(char*)src)
	{
		++(char*)dest;
		++(char*)src;
	}

	return *(char*)dest - *(char*)src;
}

int main()
{
	int arr1[] = { 1, 2, 3, 5, 7 };
	int arr2[] = { 1, 2, 3, 6, 9 };
	
	int ret = my_memcmp(arr1, arr2, 13);
	printf("%d", ret);

	return 0;
}

//void* my_memmove(void* dest, const void* src, unsigned int count)
//{
//	assert(dest && src);
//	void* temp = dest;
//
//	if (dest < src)
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//
//	return temp;
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr3[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	my_memmove(arr1, arr2, 16);
//
//	return 0;
//}

//int main()
//{
//    int arr[20] = { 0 };
//    int n = 0;
//    int i = 0;
//    int count = 0;
//
//    scanf("%d", &n);//2
//
//    for (i = 0; i < n; i++)//arr[0] = 3,arr[1] = 2
//    {
//        scanf("%d", &arr[i]);
//    }
//
//    int temp = 0;
//    scanf("%d", &temp);//3
//
//    for (i = 0; i < n; i++)
//    {
//        if (temp == arr[i])
//        {
//            count++;//+1
//        }
//    }
//
//    printf("%d", count);
//
//    return 0;
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
//	int arr1[10] = { 0 };
//	int arr2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//	my_memcpy(arr1, arr2, 16);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "zhangpengwei@bitedu.tech";
//	const char* sep = ".@";
//	char arr[30];
//	char* str = NULL;
//	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//}