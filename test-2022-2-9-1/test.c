#include <stdio.h>
int main()
{
	const int a = 10;//a不能被修改具有常属性 int const a = 10;这两个相等

	const int* p1 = &a;
	int const* p2 = &a;//这两个相等，表示p2和p1指针变量指向的指针无法被修改

	int* const p3 = &a;//表示该指针变量不能修改指向，永远的指向a

	const int* const p4 = &a;//表示该指针变量不能修改指针且也不能修改指向。

	return 0;
}

//#define ABC
//int main()
//{
//	int a = 0x11223344;
//	int* const p = &a;
//	//p = 20;
//	printf("%#o %d", a, ABC);
//
//	return 0;
//}

//int main()
//{
// 
//    int i = 0;
//
//head:
//
//    while (i < 10)
//    {
//        if (i == 5)
//        {
//            i++;
//            goto head;
//        }
//        printf("%d ", i);
//        i++;
//    }
//
//	return 0;
//}