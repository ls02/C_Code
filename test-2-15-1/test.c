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
//	//指针数组，本质是数组存放的是地址、指针
//	int* p[3] = { &a, &b, &c };//这是存放整形的指针数组，int*
//	char* q[3];//这是存放字符型的指针数组，char*
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int * p = &a;//把一个整型存放到指针变量p里面去
//	int * * pp = &p;//把p指针变量的地址存放到二级指针pp里面去
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
//		*(p1 + i) = i;//这种改变指针的指向并会对本身造成改变，就像1+1不赋值一样，下面的++是对自己本身造成了改变
//	}
//
//	for (i = 0; i < 5; i++)
//	{
//		*p2++ = i;//这种加加的做法会导致指针偏移也就是说原本是指向首地址的但是这里加加完，指针指向了这个数组的末尾，它会改变指针的指向所以要备份一个首地址。
//	}
//
//	p2 = &arr2;//重新给指针p2的指向指回了首地址，你可以把这段代码注释掉打印一下看一下区别
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
//	//当p超出arr的范围的时候就会产生越界访问，越界访问时p就是野指针
//	for (i = 0; i < 11; i++)
//	{
//		*p++ = i;
//	}
//
//	return 0;
//}

//int main()
//{
//	int* p = NULL;//指向空，这样就不会形成野指针，NULL是空指针，真实数值是0
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
//	char* p = &a;//如果这样和存放的类型不匹配会出现警告当然你硬存也是能存的
//	//但是你这样存了之后指针变量只能访问1个字节因为它是字符型的
//	//而a是一个整型存放四个字节，你指针变量只能访问和修改一个字节的内容
//	//所以变量a的值你不能很好的修改
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* p = &a;//创建一个指针变量，取出a的地址存放在指针变量p里面
//
//	*p = 20;//解引用存放在p里面a的地址并修改成20
//
//	return 0;
//}