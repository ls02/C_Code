#include <stdio.h>
#include <assert.h>
#include <string.h>

void* MemCpy(void* dest, const void* src, size_t count)
{
	assert(dest && src);

	void* temp = dest;

	while (count--)
	{
		*(char*)dest = *(char*)src;
		++((char*)dest);
		++((char*)src);
	}

	return temp;
}

void* MemMove(void* dest, const void* src, size_t count)
{
	assert(dest && src);

	void* temp = dest;

	//从前往后拷
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			++((char*)dest);
			++((char*)src);
		}
	}
	else//从后往前拷
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}

	return temp;
}

int MemCmp(const void* buf1, const void* buf2, size_t count)
{
	assert(buf1 && buf2);

	while (count--)
	{
		if (*(char*)buf1 - *(char*)buf2)
		{
			return *(char*)buf1 - *(char*)buf2;
		}

		++(char*)buf1;
		++(char*)buf2;
	}

	return 0;
}

void* MemSet(void* dest, int x, size_t count)
{
	assert(dest);

	void* temp = dest;

	while (count)
	{
		*(char*)dest = x;
		
		++(char*)dest;
		count--;
	}

	return temp;
}

void test1()
{
	//int arr1[4] = { 1, 2, 3 ,4 };
	//int arr2[4] = { 5, 6, 1, 3 };

	//int* p1 = (int*)Memcpy(arr1, arr2, 8);

	//int i = 0;

	//for (i = 0; i < 4; i++)
	//{
	//	printf("%d ", p1[i]);
	//}

	//printf("\n");

	//int arr1[4] = { 1, 2, 3 ,4 };
	//int arr2[] = { 5, 6, 1, 3 , 2, 3, 4, 5};

	//int* p1 = (int*)MemMove(arr2 + 2, arr2, 8);

	//int i = 0;

	//for (i = 0; i < 4; i++)
	//{
	//	printf("%d ", p1[i]);
	//}

	//printf("\n");

	//int arr1[4] = { 1, 2, 3 ,4 };
	//int arr2[] = { 1, 3, 3, 4, 5 };
	////int arr2[] = { 5, 6, 1, 3 , 2, 3, 4, 5 };

	////int temp = memcmp(arr1, arr2, sizeof(arr1[0]) * 5);
	//int temp = MemCmp(arr1, arr2, sizeof(arr1[0]) * 2);

	//printf("%d\n", temp);

	int arr1[4] = { 1, 2, 3 ,4 };
	int i = 0;

	memset(arr1, 50, sizeof(arr1[0]) * 4);

	for (i = 0; i < 4; i++)
	{
		printf("%d ", arr1[i]);	
	}
}

int main()
{
	test1();

	return 0;
}