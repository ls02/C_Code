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

////����һ���ṹ������
//struct Stu//struct�ǽṹ��ؼ���-Stu��������
//{
//	//���������ǽṹ���Ա
//	char name[20];
//	short age;
//	char sex[4];
//}S = { "����", 18, "��" };//����ʱ��ʼ��
//
//int main()
//{
//	struct Stu* pa = &S;
//
//	printf("������%s\n���䣺%d\n�Ա�%s\n", pa->name, pa->age, pa->sex);//ͨ��->�ṹ��ָ����ʲ����������ʽṹ���Ա
//
//	return 0;
//}

//int main()
//{
//	struct Stu* pa = &S;//����һ���ṹ�����͵�ָ���Žṹ��S�ĵ�ַ
//	
//	printf("������%s\n���䣺%d\n�Ա�%s\n", (*pa).name, (*pa).age, (*pa).sex);
//}

//int main()
//{
//	struct Stu S = { "����", 18, "��" };//�ýṹ�����ʹ���һ���ṹ�����ͱ���S����ʼ��
//	
//	printf("������%s\n���䣺%d\n�Ա�%s", S.name, S.age, S.sex);//ͨ��.�����ʽṹ��ĳ�Ա��.�ǽṹ����ʲ�����
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
//	//test;//���Ǻ���
//	test1();//��������
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
//	if (5 && 5)//ֻ�����߶�Ϊ���ʱ���ִ��if���������
//	{
//		printf("6\n");
//	}
//
//	if (5 || 5)//ֻ�����߶�Ϊ�ٵ�ʱ��Ų�ִ�����������
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
//	if (a = 5)//ԭ������Ƚ��Ƿ���ȵĿ�����д��һ��=�������Ǹ�ֵ�˱���ֵ�Ļ����ľ���a��ֵ�����Ǽ���
//	{
//		printf("666\n");
//	}
//
//	//����α����أ�
//	if (5 = a)//��ʵ����д�Ϳ����ˣ��������޷�����ֵ���������ȽϾ�����д
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
//	printf("sizeof(arr)=%d\n", sizeof(arr));//�������������������Ԫ�ص�ַ���������������
//	printf("sizeof(int[10])=%d\n", sizeof(int[10]));//�������������
//	printf("sizeof a =%d\n", sizeof a);//�������Ϳ���ʡ�ԣ������ţ�����������ʡ��
//	printf("sizeof(a)=%d\n", sizeof(a));//����������ȫ�ȼ�
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = 5;//�ڴ�����ʱ��ֵ�ǳ�ʼ��
//	int* p = NULL;
//	p = &c;//ȡ��ַ
//	
//	*p = 20;//������
//	printf("c=%d *p = %d\n", c, *p);
//
//	(short)b;//ǿ������ת��
//
//	if (!a)//�߼��ǣ����٣��ٱ���
//	{
//		printf("�ٱ��棬���١�a=%d\n", !a);
//	}
//
//	-b;//����
//	+b;//����
//
//
//	return 0;

//int main()
//{
//	int weight = 120;//����
//	weight = 80;//���������¸�ֵ
//	double salary = 10000.000;//н��
//	salary = 20000.000;//���������¸�ֵ
//
//	//��ֵ��������������ʹ�ã����磺
//	int x = 10;
//	int y = 0;
//	int k = 0;
//
//	k = y = x + 1;//������ֵ
//	//�����Ĵ���о�������
//
//	//��ͬ��������㿴����
//	y = x + 1;
//	k = y;
//	//������д���ǲ��ǿ�������������ˬ�ʣ������ڵ���
//
//	return 0;
//}

//int main()
//{
//	int a = 5;//011 101
//	int b = 3;
//	int c = 0;
//
//	c = a & b;//���������ƣ�λ��
//	printf("a&b=%d\n", c);
//
//	c = a | b;//��λ��������λ����
//	printf("a|b=%d\n", c);
//
//	c = a ^ b;//���������ƣ�λ�����ͬΪ�㣬����Ϊһ
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
//	printf("7/2=%d\n", 7 / 2);//���γ���
//	printf("7/2.0=%f\n", 7 / 2.0);//�����ͳ���
//	printf("7.0/2=%f\n", 7.0 / 2.0);//�����ͳ���
//	printf("7%%2=%d\n", 7 % 2);//ȡģ�Ľ���ǳ�����������������С��ֻ�������Σ�Ұ���ܺ���ȡģ
//
//	return 0;
//}