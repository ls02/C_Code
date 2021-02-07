#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

struct Student//结构体类型
{
	char nema[20];//结构体成员
	int age;
};

int main()
{
	struct Student S1 = { "张三", 22 };//结构体类型变量创建并初始化
	
	printf("%s %d\n", S1.nema, S1.age);//通过.来访问结构体里面的成员叫做成员访问操作符

	struct Student *p = &S1;//结构体指针，结构体S1的地址给结构体指针p

	printf("%s %d\n", p->nema, p->age);//通过->指向来解引用，获得成员

	return 0;
}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[10];//这就是下标引用操作符
//	int a = 4;
//	int b = 4;
//
//	int ret = Add(a, b);
//
//	return 0;
//}

//int main()
//{
//	int c = 0;
//	int a = (c++, 2, 3, 4, 5, 6);
//
//	printf("a = %d c = %d\n", a, c);
//
//	a = 1, 2, 3, 4, 5, c++;
//	printf("a = %d c = %d\n", a, c);
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	printf("a > b ? a : b = %d\n", a > b ? a : b);//a如果大于b就输出冒号左边那个值，如果小于就输出冒号右边的值
//	printf("b > a ? b : a = %d\n", b > a ? b : a);//b如果大于a就输出冒号左边那个值，如果小于就输出冒号右边的值
//
//	if (a > b)//如果大于就输出a
//	{
//		printf("%d\n", a);
//	}
//	else//小于就输出b
//	{
//		printf("%d\n", b);
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//
//	printf("~a=%d", ~a);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 1;
//	int d = 1;
//
//	printf("a&&b=%d\n", a && b);
//	printf("a&&c=%d\n", a && c);
//	printf("c&&d=%d\n", c && d);//只有两边都为真才为真只要一个为假就是假
//
//	printf("a||b=%d\n", a || b);//只有两个为假才为假
//	printf("a||c=%d\n", a || c);//只要一个为真就是真
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 0;
//
//	printf("!a=%d\n", !a);//如果a是真，a被逻辑非作用之后就会变成假
//	printf("!b=%d\n", !b);//如果b是假，b被逻辑非作用之后就会变成真
//	
//	int c = 2;
//	-c;//表示这个变量是一个负数
//	+c;
//	c;//c和+c等价，表示这个变量是个正数
//
//	printf("&a=%p\n", &a);//取出a的地址，由于a的地址每次都不一样也就是随机的，所以我就不给出特列了，直接看结果,%p是以地址的形式打印
//
//	printf("sizeof(a)=%d\n", sizeof a);//可以加括号也可以不加括号，但是类型一定要加括号
//	printf("sizeof(int)=%d\n", sizeof(int));//类型求大小必须有括号括起来
//
//	{
//		int a = 2;
//		int b = a++;//后置加加，先使用了a的值再自身加一
//		printf("a=%d b=%d\n", a, b);//b被赋值前a没加加因为它没使用，它使用之后才加加的
//
//		int k = 5;
//		int n = ++k;//k先加一再使用
//		printf("k=%d n=%d\n", k, n);//n是被赋值前k是先加加再被赋值的因为++优先级比=(赋值优先级高)
//		//前置、后置--和加加同理
//	}
//
//	int cc = 8;
//
//	int* p = &cc;//这里的*p是说明它是指针不是解引用操作符,把cc的地址给指针p，指针p有了地址就能找到cc的值
//	printf("*p=%d\n", *p);//这里的*p是解引用，p被*解引用之后找到了cc的值所以输出a的值
//
//	float pp = 3.14;
//	int aa = (int)pp;//一个浮点型赋值给整形类型上会出现不兼容会警告，如果我们一要
//	//强制类型转换把怕pp转换成和aa对应的类型，这样赋值才不会报错。
//
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 3;
//	int c = 0;
//
//	c += a;
//	c = c + a;//这和上面哪一个完全等价也就是效果一样，你可以理解上面的是缩写
//
//	c -= a;
//	c = c - a;//这个也是后面的都一样我就不一一赘述了
//
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 3;
//	printf("a&b=%d ", a & b);
//	printf("a|b=%d ", a | b);
//	printf("a^b=%d ", a ^ b);
//	
//	return 0;
//}

//int main()
//{
//	int a = 14;
//	int b = 14;
//
//	printf("a=%d ", a << 1);
//	printf("b=%d ", b >> 1);
//
//	return 0;
//}

//int main()
//{
//
//	printf("7/2=%d\n", 7 / 2);//如果没有小数，相除就会丢失精度从而造成结果无小数
//	printf("7.0/2=%f\n", 7.0 / 2);//如果有的话就不会丢失精度也就是不会被截断，从而能完美的打印
//	printf("7%2=%d\n", 7 % 2);//取模是取余数商3余1，这就是取模和除数的区别
//
//	return 0;
//}

//int Add(int a, int b)//Add有两个参数分别是int a,int b
//{
//	return a + b;//返回a+b的计算结果，返回值为整形，函数名旁边的整形就是这个函数的返回类型
//}
//
//int main()
//{
//	int sum1 = 0;
//	int sum2 = 0;
//	
//	scanf("%d%d", &sum1, &sum2);
//	int ret = Add(sum1, sum2);//Add是函数，ret是用来接收Add返回值，sum1和sum2的两个参数
//	printf("%d", ret);//打印Add函数的返回值
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	while (0 <= a)//a大于1他就执行
//	{
//		printf("%d ", a);//没执行一次打印一次
//		a--;//a--是自身减一的意思，作为跳出循环的条件
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("输入你的年龄>:");
//	scanf("%d", &input);
//
//	if (15 <= input)
//	{
//		printf("少年\n");
//	}
//	else if (18 <= input)
//	{
//		printf("青年\n");
//	}
//	else if(40 <= input)
//	{
//		printf("中年\n");
//	}
//	else
//	{
//		printf("老年\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("输入你的年龄>:");
//	scanf("%d", &input);
//
//	if (18 <= input)
//	{
//		printf("成年\n");
//	}
//	else
//	{
//		printf("未成年\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	//这是c++的注释风格
//	//int a = 10;
//	int b = 20;//两个\\是注释
//	
//	//总的来说c++的注释风格比较好
//	 /*这是c的注释风格，c的注释风格不支持嵌套注释
//	int k = 29;
//	*/
//	return 0;//返回0
//}

//int main()
//{
//	printf("\123\n");
//	printf("\x41");
//
//	return 0;
//}

//int main()
//{
//	printf("%d\n", 'a');
//	printf("%c\n", 'a');
//
//	return 0;
//}

//int main()
//{
//	printf("c:\\test\\test.c\n");
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a', 'b', 'c' };
//
//	printf("%d ", strlen(arr1));
//	printf("%d", strlen(arr2));
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = { 'a', 'b', 'c', 'd', 'e', 'f','\0' };
//	char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f',0 };
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//	return 0;
//}

//int main()
//{
//	printf("%d", 10);
//
//	return 0;
//}