#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

struct Student//�ṹ������
{
	char nema[20];//�ṹ���Ա
	int age;
};

int main()
{
	struct Student S1 = { "����", 22 };//�ṹ�����ͱ�����������ʼ��
	
	printf("%s %d\n", S1.nema, S1.age);//ͨ��.�����ʽṹ������ĳ�Ա������Ա���ʲ�����

	struct Student *p = &S1;//�ṹ��ָ�룬�ṹ��S1�ĵ�ַ���ṹ��ָ��p

	printf("%s %d\n", p->nema, p->age);//ͨ��->ָ���������ã���ó�Ա

	return 0;
}

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[10];//������±����ò�����
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
//	printf("a > b ? a : b = %d\n", a > b ? a : b);//a�������b�����ð������Ǹ�ֵ�����С�ھ����ð���ұߵ�ֵ
//	printf("b > a ? b : a = %d\n", b > a ? b : a);//b�������a�����ð������Ǹ�ֵ�����С�ھ����ð���ұߵ�ֵ
//
//	if (a > b)//������ھ����a
//	{
//		printf("%d\n", a);
//	}
//	else//С�ھ����b
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
//	printf("c&&d=%d\n", c && d);//ֻ�����߶�Ϊ���Ϊ��ֻҪһ��Ϊ�پ��Ǽ�
//
//	printf("a||b=%d\n", a || b);//ֻ������Ϊ�ٲ�Ϊ��
//	printf("a||c=%d\n", a || c);//ֻҪһ��Ϊ�������
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int b = 0;
//
//	printf("!a=%d\n", !a);//���a���棬a���߼�������֮��ͻ��ɼ�
//	printf("!b=%d\n", !b);//���b�Ǽ٣�b���߼�������֮��ͻ�����
//	
//	int c = 2;
//	-c;//��ʾ���������һ������
//	+c;
//	c;//c��+c�ȼۣ���ʾ��������Ǹ�����
//
//	printf("&a=%p\n", &a);//ȡ��a�ĵ�ַ������a�ĵ�ַÿ�ζ���һ��Ҳ��������ģ������ҾͲ����������ˣ�ֱ�ӿ����,%p���Ե�ַ����ʽ��ӡ
//
//	printf("sizeof(a)=%d\n", sizeof a);//���Լ�����Ҳ���Բ������ţ���������һ��Ҫ������
//	printf("sizeof(int)=%d\n", sizeof(int));//�������С����������������
//
//	{
//		int a = 2;
//		int b = a++;//���üӼӣ���ʹ����a��ֵ�������һ
//		printf("a=%d b=%d\n", a, b);//b����ֵǰaû�Ӽ���Ϊ��ûʹ�ã���ʹ��֮��żӼӵ�
//
//		int k = 5;
//		int n = ++k;//k�ȼ�һ��ʹ��
//		printf("k=%d n=%d\n", k, n);//n�Ǳ���ֵǰk���ȼӼ��ٱ���ֵ����Ϊ++���ȼ���=(��ֵ���ȼ���)
//		//ǰ�á�����--�ͼӼ�ͬ��
//	}
//
//	int cc = 8;
//
//	int* p = &cc;//�����*p��˵������ָ�벻�ǽ����ò�����,��cc�ĵ�ַ��ָ��p��ָ��p���˵�ַ�����ҵ�cc��ֵ
//	printf("*p=%d\n", *p);//�����*p�ǽ����ã�p��*������֮���ҵ���cc��ֵ�������a��ֵ
//
//	float pp = 3.14;
//	int aa = (int)pp;//һ�������͸�ֵ�����������ϻ���ֲ����ݻᾯ�棬�������һҪ
//	//ǿ������ת������ppת���ɺ�aa��Ӧ�����ͣ�������ֵ�Ų��ᱨ��
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
//	c = c + a;//���������һ����ȫ�ȼ�Ҳ����Ч��һ���������������������д
//
//	c -= a;
//	c = c - a;//���Ҳ�Ǻ���Ķ�һ���ҾͲ�һһ׸����
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
//	printf("7/2=%d\n", 7 / 2);//���û��С��������ͻᶪʧ���ȴӶ���ɽ����С��
//	printf("7.0/2=%f\n", 7.0 / 2);//����еĻ��Ͳ��ᶪʧ����Ҳ���ǲ��ᱻ�ضϣ��Ӷ��������Ĵ�ӡ
//	printf("7%2=%d\n", 7 % 2);//ȡģ��ȡ������3��1�������ȡģ�ͳ���������
//
//	return 0;
//}

//int Add(int a, int b)//Add�����������ֱ���int a,int b
//{
//	return a + b;//����a+b�ļ�����������ֵΪ���Σ��������Աߵ����ξ�����������ķ�������
//}
//
//int main()
//{
//	int sum1 = 0;
//	int sum2 = 0;
//	
//	scanf("%d%d", &sum1, &sum2);
//	int ret = Add(sum1, sum2);//Add�Ǻ�����ret����������Add����ֵ��sum1��sum2����������
//	printf("%d", ret);//��ӡAdd�����ķ���ֵ
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	while (0 <= a)//a����1����ִ��
//	{
//		printf("%d ", a);//ûִ��һ�δ�ӡһ��
//		a--;//a--�������һ����˼����Ϊ����ѭ��������
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("�����������>:");
//	scanf("%d", &input);
//
//	if (15 <= input)
//	{
//		printf("����\n");
//	}
//	else if (18 <= input)
//	{
//		printf("����\n");
//	}
//	else if(40 <= input)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("����\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int input = 0;
//
//	printf("�����������>:");
//	scanf("%d", &input);
//
//	if (18 <= input)
//	{
//		printf("����\n");
//	}
//	else
//	{
//		printf("δ����\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	//����c++��ע�ͷ��
//	//int a = 10;
//	int b = 20;//����\\��ע��
//	
//	//�ܵ���˵c++��ע�ͷ��ȽϺ�
//	 /*����c��ע�ͷ��c��ע�ͷ��֧��Ƕ��ע��
//	int k = 29;
//	*/
//	return 0;//����0
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