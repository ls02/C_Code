#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int main()
{
	char* arr[2] = { "hello", "world" };
	int i = 0;

	for (i = 0; i < 2; i++)
	{
		printf("%s\n", arr[i]);
	}

	return 0;
}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	//ָ�����飬�����������ŵ��ǵ�ַ��ָ��
//	int* p[3] = { &a, &b, &c };//���Ǵ�����ε�ָ�����飬int*
//	char* q[3];//���Ǵ���ַ��͵�ָ�����飬char*
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int * p = &a;//��һ�����ʹ�ŵ�ָ�����p����ȥ
//	int * * pp = &p;//��pָ������ĵ�ַ��ŵ�����ָ��pp����ȥ
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9,0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("*(p+%d)=%d\n", i, *(p + i));
//	}
//
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9,0 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p <<------->> p+%d=%p\n", i, &arr[i], i, p + i);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//
//	printf("arr=%p\n", arr);
//	printf("&arr=%p\n", &arr[0]);
//
//	return 0;
//}

//int My_strlen(char* arr)
//{
//	assert(arr);
//	char* p = arr;
//
//	while (*p)
//	{
//		p++;
//	}
//
//	return p - arr;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//
//	int ret = My_strlen(arr);
//
//	printf("ret = %d", ret);
//
//	return 0;
//}

//int main()
//{
//	int arr[10];
//
//	printf("%d", &arr[9] - &arr[0]);
//
//	return 0;
//}

//int main()
//{
//	int arr1[5] = { 0 };
//	int arr2[5] = { 0 };
//	int* p1 = arr1;
//	int* p2 = arr2;
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		*(p1 + i) = i;//���ָı�ָ���ָ�򲢻�Ա�����ɸı䣬����1+1����ֵһ���������++�Ƕ��Լ���������˸ı�
//	}
//
//	for (i = 0; i < 5; i++)
//	{
//		*p2++ = i;//���ּӼӵ������ᵼ��ָ��ƫ��Ҳ����˵ԭ����ָ���׵�ַ�ĵ�������Ӽ��ָ꣬��ָ������������ĩβ������ı�ָ���ָ������Ҫ����һ���׵�ַ��
//	}
//
//	p2 = &arr2;//���¸�ָ��p2��ָ��ָ�����׵�ַ������԰���δ���ע�͵���ӡһ�¿�һ������
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("*(p1+%d)=%d\n", i, *(p1 + i));
//	}
//	printf("-------------------------------------\n");
//	for (i = 0; i < 5; i++)
//	{
//		printf("*p2++=%d\n", *p2++);
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//
//	//��p����arr�ķ�Χ��ʱ��ͻ����Խ����ʣ�Խ�����ʱp����Ұָ��
//	for (i = 0; i < 11; i++)
//	{
//		*p++ = i;
//	}
//
//	return 0;
//}

//int main()
//{
//	int* p = NULL;//ָ��գ������Ͳ����γ�Ұָ�룬NULL�ǿ�ָ�룬��ʵ��ֵ��0
//	*p = 20;
//
//	return 0;
//}

//int main()
//{
//	int num = 0x11223344;
//	int* p1 = &num;
//	char* p2 = (char*)&num;
//
//	*p2 = 0;
//	*p1 = 0;
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int* p1 = arr;
//	char* p2 = (char*)arr;
//
//	printf("p1=%p\n", p1);
//	printf("p1+1=%p\n", p1 + 1);
//	printf("------------------------\n");
//	printf("p2=%p\n", p2);
//	printf("p2+1=%p\n", p2 + 1);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	char* p = &a;//��������ʹ�ŵ����Ͳ�ƥ�����־��浱Ȼ��Ӳ��Ҳ���ܴ��
//	//��������������֮��ָ�����ֻ�ܷ���1���ֽ���Ϊ�����ַ��͵�
//	//��a��һ�����ʹ���ĸ��ֽڣ���ָ�����ֻ�ܷ��ʺ��޸�һ���ֽڵ�����
//	//���Ա���a��ֵ�㲻�ܺܺõ��޸�
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;//����һ��ָ�������ȡ��a�ĵ�ַ�����ָ�����p����
//
//	*p = 20;//�����ô����p����a�ĵ�ַ���޸ĳ�20
//
//	return 0;
//}