#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct A
{
	char a;
	int b;
	short c;
}a;

int main()
{
	printf("%d", sizeof(a));

	return 0;
}

//union A
//{
//	char a;
//	int b;
//};
//
//int main()
//{
//	union A a1;
//
//	//a1.a = 97;
//	//printf("a1.a=%d\n", a1.a);
//
//	//a1.b = 0;
//	//printf("a1.b=%d\n", a1.b);
//	//printf("------------------------\n");
//	//printf("&a1.a=%p\n", &a1.a);
//	//printf("&a1.b=%p\n", &a1.b);
//	//printf("&a1=%p\n", &a1);
//	printf("%d", sizeof(a1));
//
//	return 0;
//}


//int main()
//{
//	enum sex
//	{
//		man = 5,//不给值默认值是0
//		woman
//	};
//
//	printf("%d %d", man, woman);
//
//	return 0;
//}

//int test()
//{
//	int a = 1;
//
//	return *(char*)&a;
//}

//int test()
//{
//	union on
//	{
//		int a;
//		char c;
//	}a;
//	a.a = 1;
//
//	return a.c;
//}
//
//int main()
//{
//	if (test())
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}