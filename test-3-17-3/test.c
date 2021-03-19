#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�

//void Find(int a[], int sz, int* num)
//{
//    int i = 0;
//    int pos = 0;
//    int ret = 0;
//    //�������飬���Ϊ������ͬ�������
//    for (i = 0; i < sz; i++)
//    {
//        ret ^= a[i];
//    }
//    //Ѱ����������ͬ���������һ��λΪ 1 ��λ
//    for (pos = 0; pos < 32; pos++)
//    {
//        if (((ret >> pos) & 1) == 1)//���� 32 λ���ӵ�λ���λ���α���
//        {
//            break;     //pos��¼������λΪ 1 ����
//        }
//    }
//    for (i = 0; i < sz; i++)
//    {
//        //�ҵ�������posλΪ1���������������
//        if (((a[i] >> pos) & 1) == 1)
//        {
//            num[1] ^= a[i];
//        }
//        //�ҵ�������posλΪ0���������������
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