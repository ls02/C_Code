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
	struct Stu s1 = { "����", 28, "��" };
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
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	print1(s);  //���ṹ��
//	print2(&s); //����ַ
//	return 0;
//}

//struct Stu
//{
//	char name[20];
//	short age;
//	char sex[4];
//}s1;//�����s1��ȫ�ֱ��������������ﴴ��Ҳ���Բ������ﴴ��������ȫ�ֱ���
//
//struct Stu s2;//����Ҳ��ȫ�ֱ���
//
//int main()
//{
//	struct Stu s3;//�����Ǿֲ�����
//
//	return 0;
//}