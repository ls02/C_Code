#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void* elem1, const void* elem2));



void test1()
{
	printf("666\n");
}

void test2(void (*p)())
{
	p();
}

int main()
{
	test2(test1);

	return 0;
}

//int main()
//{
//	int (*p)(int, int);//����ָ��
//	int (*pp[4])(int, int);//����ָ������
//	int (*(*ppp)[4])(int, int);//����ָ�������ָ��
//
//	return 0;
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//
//int Mou(int x, int y)
//{
//	return x % y;
//}
//
//int main()
//{
//	int (*p[2])(int, int) = { add, Mou };//����ָ��Ĵ���
//	int a = 5;
//	int b = 5;
//
//	printf("%d\n", p[0](a, b));//����ָ���ʹ��
//	printf("%d\n", p[1](a, b));
//
//	return 0;
//}

//typedef void(*pfun)(int);
//
//pfun strqqq(int, pfun);
//
//int my_strlen(const char* str)
//{
//	assert(str);
//
//	const char* p = str;
//
//	while (*++str)
//	{
//		;
//	}
//	
//	return str - p;
//}
//
//int main()
//{
//	int (*p)(char const*) = my_strlen;
//
//	printf("%d\n", p("abcdef"));
//	printf("%d\n", p("qqqqqqqqq"));
//
//	return 0;
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*p)(int, int) = add;
//	int a = 10;
//	int b = 20;
//
//	printf("(*p)(a, b) = %d\n", (*p)(a, b));//�൱��add(a, b);
//	printf("p(a, b) = %d\n", p(a, b));
//	printf("(*******************p)(a, b) = %d\n", (*******************p)(a, b));
//
//	return 0;
//}

//int main()
//{
//	int (*p)(int, int) = &add;//����Ǻ���ָ��Ĵ���
//	int (*p1)(int, int) = add;//&add��add�ȼ���Ϊû����Ԫ��֮�ֲ������飬���Կ��Ժ������������ĵ�ַ����ȡ��ַ�ǵȼ۵�
//
//	printf("add=%p\n", add);//���ǵĵ�ַһ��
//	printf("&add=%p\n", &add);
//
//	return 0;
//}

//int main()
//{
//	int n = 5;
//	float* pa = (float*)&n;
//	float a = 5.0;
//
//	printf("n = %d\n", n);
//	printf("*pa = %f\n", *pa);
//	printf("-------------------------\n");
//	
//	*pa = 5.0;
//
//	printf("n = %d\n", n);
//	printf("*pa = %f", *pa);
//
//	return 0;
//}