#include <stdio.h>

struct A
{
	int a : 3;//占用3个比特位
	int b : 20;//占用20个比特位
	int c : 9;//占用9个比特位
	//大小：4个字节
};

union B
{
	int age;
	char arr;
	int set;
};

//默认给值是0依次递增，如果第一个没给值，而中间的给一个值，最后没给值，那么最后的值是前面的值+1
enum RGB
{
	RED,
	GREEN,
	BLUE
};

int main()
{
	//union B b1;
	//b1.age = 30;
	//printf("%d\n", b1.age);
	//printf("%c\n", b1.arr);
	//printf("%d\n", b1.set);

	//printf("%d\n", b1.age);
	//b1.arr = 'a';
	//printf("%c\n", b1.arr);
	//b1.set = 3;
	//printf("%d\n", b1.set);


	//printf("%d\n", b1.age);
	//printf("%c\n", b1.arr);
	//printf("%d\n", b1.set);

	const char*const a = "你好";
	//const char*const arr = a;

	printf(a);


	return 0;
}

//#pragma pack(1)
//struct A
//{
//	char name;
//	int age;
//	char sex;
//};
//#pragma pack()
//
//int main()
//{
//	printf("struct A的大小：%d字节", sizeof(struct A));
//
//	return 0;
//}

////不建议使用这种匿名结构体
////别名定义匿名结构体，不过能支持任意地方创建和初始化和使用正常的结构体没有区别
//typedef struct
//{
//	char naem[20];
//	int age;
//}S;
//
////匿名结构体，使用前必须在定义结构体后就创建并初始化
//struct
//{
//	char name[20];
//	int age;
//}a = { "李四", 33 };
//
//int main()
//{
//	S s1 = { "张三", 20 };
//
//	printf("%s\t%d\n", s1.naem, s1.age);
//	printf("%s\t%d\n", a.name, a.age);
//
//	return 0;
//}


////定义结构体A并创建全局变量初始化
//struct A
//{
//	char name[20];
//	int age;
//}a1 = { "张三", 30 };
//
////定义结构体
//struct B
//{
//	char name[20];
//	int age;
//};
//
////创建全局变量
//struct B b1 = { "李四", 20 };
//
////结构体定义别名C, C == struct CBokk
//typedef struct CBook
//{
//	char name[20];
//	int age;
//}C;
//
//
//int main()
//{
//	//定义局部变量
//	struct B b2 = { "王五", 22 };
//
//	//别名定义局部变量结构体
//	C c1 = { "赵六", 23 };
//
//	printf("%s\t%d\n", a1.name, a1.age);
//	printf("%s\t%d\n", b1.name, b1.age);
//	printf("%s\t%d\n", b2.name, b2.age);
//	printf("%s\t%d\n", c1.name, c1.age);
//
//	return 0;
//}