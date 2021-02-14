#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int i = 1;
    int ret = (++i) + (++i) + (++i);

    printf("%d\n", ret);
    printf("%d\n", i);

    return 0;
}

//int main()
//{
//	char a = 3;
//	char b = 127;
//	char c = a + b;
//
//	printf("%d", c);
//
//	return 0;
//}

////创建一个结构体类型
//struct Stu//struct是结构体关键字-Stu是类型名
//{
//	//以下三个是结构体成员
//	char name[20];
//	short age;
//	char sex[4];
//}S = { "张三", 18, "男" };//创建时初始化
//
//int main()
//{
//	struct Stu* pa = &S;
//
//	printf("姓名：%s\n年龄：%d\n性别：%s\n", pa->name, pa->age, pa->sex);//通过->结构体指针访问操作符来访问结构体成员
//
//	return 0;
//}

//int main()
//{
//	struct Stu* pa = &S;//创建一个结构体类型的指针存放结构体S的地址
//	
//	printf("姓名：%s\n年龄：%d\n性别：%s\n", (*pa).name, (*pa).age, (*pa).sex);
//}

//int main()
//{
//	struct Stu S = { "张三", 18, "男" };//用结构体类型创建一个结构体类型变量S并初始化
//	
//	printf("姓名：%s\n年龄：%d\n性别：%s", S.name, S.age, S.sex);//通过.来访问结构体的成员，.是结构体访问操作符
//
//	return 0;
//}

//void test1()
//{
//	printf("666\n");
//}
//
//void test2()
//{
//	printf("222\n");
//}
//
//int main()
//{
//	//test;//不是函数
//	test1();//函数调用
//	test2();
//
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	a = 20 + 1, 20 + 3, 10 + 5;
//
//	printf("%d", a);
//
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 1, b = 2, c = 3, d = 4;
//
//	i = a++ || ++b || d++;
//	printf("a=%d b=%d c=%d d=%d i=%d", a, b, c, d, i);
//
//	return 0;
//}

//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//
//	i = a++ && ++b && b++;
//	printf("a=%d b=%d c=%d d=%d i=%d", a, b, c, d, i);
//
//	return 0;
//}

//int main()
//{
//	if (5 && 5)//只有两边都为真的时候才执行if里面的内容
//	{
//		printf("6\n");
//	}
//
//	if (5 || 5)//只有两边都为假的时候才不执行里面的内容
//	{
//		printf("7\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	if (a = 5)//原本是想比较是否相等的可是少写了一个=，这样是赋值了被赋值的话看的就是a的值是真是假了
//	{
//		printf("666\n");
//	}
//
//	//那如何避免呢？
//	if (5 = a)//其实这样写就可以了，常量是无法被赋值的如果你想比较就这样写
//	{
//		printf("5555\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//
//	printf("~a=%d", ~a);
//
//	return 0;
//}

//int main()
//{
//	short a = 3;
//	int b = 10;
//
//	printf("sizeof(a = b + 5)=%d\n", sizeof(a = b + 5));
//	printf("a=%d\n", a);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int a = 5;
//
//	printf("sizeof(arr)=%d\n", sizeof(arr));//这里的数组名不代表首元素地址代表的是整个数组
//	printf("sizeof(int[10])=%d\n", sizeof(int[10]));//这是数组的类型
//	printf("sizeof a =%d\n", sizeof a);//不是类型可以省略（）括号，类型名不能省略
//	printf("sizeof(a)=%d\n", sizeof(a));//它和上面完全等价
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 5;//在创建的时候赋值是初始化
//	int* p = NULL;
//	p = &c;//取地址
//	
//	*p = 20;//解引用
//	printf("c=%d *p = %d\n", c, *p);
//
//	(short)b;//强制类型转换
//
//	if (!a)//逻辑非，真变假，假变真
//	{
//		printf("假变真，真变假。a=%d\n", !a);
//	}
//
//	-b;//负数
//	+b;//正数
//
//
//	return 0;

//int main()
//{
//	int weight = 120;//体重
//	weight = 80;//不满意重新赋值
//	double salary = 10000.000;//薪资
//	salary = 20000.000;//不满意重新赋值
//
//	//赋值操作符可以连续使用，比如：
//	int x = 10;
//	int y = 0;
//	int k = 0;
//
//	k = y = x + 1;//连续赋值
//	//这样的代码感觉怎样？
//
//	//那同样的语句你看看：
//	y = x + 1;
//	k = y;
//	//这样的写法是不是看起来更加清晰爽朗，更易于调试
//
//	return 0;
//}

//int main()
//{
//	int a = 5;//011 101
//	int b = 3;
//	int c = 0;
//
//	c = a & b;//按（二进制）位与
//	printf("a&b=%d\n", c);
//
//	c = a | b;//按位（二进制位）或
//	printf("a|b=%d\n", c);
//
//	c = a ^ b;//按（二进制）位异或，相同为零，相异为一
//	printf("a^b=%d\n", c);
//
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	int b = a >> 1;
//
//	printf("%d", b);
//
//	return 0;
//}

//int main()
//{
//	int a = -1;
//	
//	printf("%d", a << 1);
//
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 0;
//	
//	b = a << 1;
//
//	printf("a=%d ", a);
//	printf("b=%d", b);
//
//	return 0;
//}

//int main()
//{
//	printf("7/2=%d\n", 7 / 2);//整形除法
//	printf("7/2.0=%f\n", 7 / 2.0);//浮点型除法
//	printf("7.0/2=%f\n", 7.0 / 2.0);//浮点型除法
//	printf("7%%2=%d\n", 7 % 2);//取模的结果是除法的余数，不能是小数只能是整形，野不能和零取模
//
//	return 0;
//}