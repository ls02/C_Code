#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void TestHeap1()
{
	Heap php;
	int arr[] = { 22, 33, 123, 53, 6, 121, 35, 3, 66, 12, 15, 99 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapCreate(&php, arr, size);

	HeapPush(&php, 1432);
	HeapPrint(&php);
	
	HeapPop(&php);
	HeapPrint(&php);

	HeapDestory(&php);
}

int main()
{
	//TestHeap1();
	//TestTopk();

	return 0;
}