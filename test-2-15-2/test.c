#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct Stu
{
	char name[20];
	short age;
	char sex[4];
};

int main()
{
	struct Stu s1 = { "张三", 28, "男" };
	struct Stu* S = &s1;

	printf("%s %d %s\n", s1.name, s1.age, s1.sex);

	printf("%s %d %s", S->name, S->age, S->sex);

	return 0;
}

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //传结构体
//	print2(&s); //传地址
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	short age;
//	char sex[4];
//}s1;//这里的s1是全局变量，可以在这里创建也可以不在这里创建，它是全局变量
//
//struct Stu s2;//这里也是全局变量
//
//int main()
//{
//	struct Stu s3;//这里是局部变量
//
//	return 0;
//}