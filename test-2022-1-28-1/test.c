#include <stdio.h>

struct A
{
	int a : 3;//ռ��3������λ
	int b : 20;//ռ��20������λ
	int c : 9;//ռ��9������λ
	//��С��4���ֽ�
};

union B
{
	int age;
	char arr;
	int set;
};

//Ĭ�ϸ�ֵ��0���ε����������һ��û��ֵ�����м�ĸ�һ��ֵ�����û��ֵ����ô����ֵ��ǰ���ֵ+1
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

	const char*const a = "���";
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
//	printf("struct A�Ĵ�С��%d�ֽ�", sizeof(struct A));
//
//	return 0;
//}

////������ʹ�����������ṹ��
////�������������ṹ�壬������֧������ط������ͳ�ʼ����ʹ�������Ľṹ��û������
//typedef struct
//{
//	char naem[20];
//	int age;
//}S;
//
////�����ṹ�壬ʹ��ǰ�����ڶ���ṹ���ʹ�������ʼ��
//struct
//{
//	char name[20];
//	int age;
//}a = { "����", 33 };
//
//int main()
//{
//	S s1 = { "����", 20 };
//
//	printf("%s\t%d\n", s1.naem, s1.age);
//	printf("%s\t%d\n", a.name, a.age);
//
//	return 0;
//}


////����ṹ��A������ȫ�ֱ�����ʼ��
//struct A
//{
//	char name[20];
//	int age;
//}a1 = { "����", 30 };
//
////����ṹ��
//struct B
//{
//	char name[20];
//	int age;
//};
//
////����ȫ�ֱ���
//struct B b1 = { "����", 20 };
//
////�ṹ�嶨�����C, C == struct CBokk
//typedef struct CBook
//{
//	char name[20];
//	int age;
//}C;
//
//
//int main()
//{
//	//����ֲ�����
//	struct B b2 = { "����", 22 };
//
//	//��������ֲ������ṹ��
//	C c1 = { "����", 23 };
//
//	printf("%s\t%d\n", a1.name, a1.age);
//	printf("%s\t%d\n", b1.name, b1.age);
//	printf("%s\t%d\n", b2.name, b2.age);
//	printf("%s\t%d\n", c1.name, c1.age);
//
//	return 0;
//}