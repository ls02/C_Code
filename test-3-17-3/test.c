#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。

//void Find(int a[], int sz, int* num)
//{
//    int i = 0;
//    int pos = 0;
//    int ret = 0;
//    //遍历数组，结果为两个不同数的异或。
//    for (i = 0; i < sz; i++)
//    {
//        ret ^= a[i];
//    }
//    //寻找这两个不同数异或结果的一个位为 1 的位
//    for (pos = 0; pos < 32; pos++)
//    {
//        if (((ret >> pos) & 1) == 1)//整型 32 位，从低位向高位依次遍历
//        {
//            break;     //pos记录二进制位为 1 的数
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        //找到数组中pos位为1的数，并进行异或
//        if (((a[i] >> pos) & 1) == 1)
//        {
//            num[1] ^= a[i];
//        }
//        //找到数组中pos位为0的数，并进行异或
//        else
//        {
//            num[0] ^= a[i];
//        }
//    }
//}


//void Find(int* dest, char* store, size_t n)
//{
//	assert(dest && store);
//	
//	size_t i = 0;
//	size_t j = 0;
//	int k = 0;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		int flag = 0;
//		for (j = i; j < n - 1; j++)
//		{
//			if (dest[i] == dest[j + 1])
//			{
//				flag = 1;
//			}
//		}
//		if (!flag)
//		{
//			store[k]= dest[i + 1] + '0';
//			k++;
//		}
//	}
//}

void Find(int* dest, size_t sz, int* num)
{
	assert(dest && num);

	int pos = 0;
	int sum = 0;
	unsigned int i = 0;

	for (i = 0; i < sz; i++)
	{
		sum ^= dest[i];
	}

	for (pos = 0; pos < 32; pos++)
	{
		if (((sum >> pos) & 1) == 1)
		{
			break;
		}
	}

	for (i = 0; i < sz; i++)
	{
		if (((dest[i] >> pos) & 1) == 1)
		{
			num[1] ^= dest[i];
		}
		else
		{
			num[0] ^= dest[i];
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int arr1[2]= { 0 };

	Find(arr, sz, arr1);

	printf("%d %d", arr1[0], arr1[1]);

	return 0;
}