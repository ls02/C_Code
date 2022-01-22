#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int test(int (*pa)(int, int))
{
	return pa(30, 40);//回调函数，通过在该函数被动调用其它函数
}

int main()
{
	printf("%d",test(Add));//传要被调用的函数地址即可完成回调函数

	return 0;
}

//int Sub(int a, int b)
//{
//	return a - b;
//}



//int main()
//{
//	int (*arr[2])(int, int) = { Add, Sub };//函数指针数组
//	int (*(*p1)[2])(int, int) = &arr;//函数指针数组指针
//
//	printf("%d %d", (*(*p1)[0])(30, 40), (*(*p1)[1])(50, 20));//使用函数指针数组指针
//
//	return 0;
//}

//int main()
//{
//
//	int (*arr[2])(int, int) = { Add, Sub };//如果怕写不出来，就先写成函数指针，然后再函数指针的变量名后面+[元素个数]就成了函数指针数组
//
//	printf("%d %d", (*(arr[0]))(20, 10), (*arr[1])(40, 80));//函数指针数组的调用
//
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//typedef int(*pf)(int, int);//类型重定义
//
//int main()
//{
//	pf p1 = Add;//函数指针类型创建初始化
//
//	printf("%d",(*p1)(30, 40));	//解引用函数指针调用该函数
//
//	return 0;
//}