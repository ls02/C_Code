#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}

int test(int (*pa)(int, int))
{
	return pa(30, 40);//�ص�������ͨ���ڸú�������������������
}

int main()
{
	printf("%d",test(Add));//��Ҫ�����õĺ�����ַ������ɻص�����

	return 0;
}

//int Sub(int a, int b)
//{
//	return a - b;
//}



//int main()
//{
//	int (*arr[2])(int, int) = { Add, Sub };//����ָ������
//	int (*(*p1)[2])(int, int) = &arr;//����ָ������ָ��
//
//	printf("%d %d", (*(*p1)[0])(30, 40), (*(*p1)[1])(50, 20));//ʹ�ú���ָ������ָ��
//
//	return 0;
//}

//int main()
//{
//
//	int (*arr[2])(int, int) = { Add, Sub };//�����д������������д�ɺ���ָ�룬Ȼ���ٺ���ָ��ı���������+[Ԫ�ظ���]�ͳ��˺���ָ������
//
//	printf("%d %d", (*(arr[0]))(20, 10), (*arr[1])(40, 80));//����ָ������ĵ���
//
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//typedef int(*pf)(int, int);//�����ض���
//
//int main()
//{
//	pf p1 = Add;//����ָ�����ʹ�����ʼ��
//
//	printf("%d",(*p1)(30, 40));	//�����ú���ָ����øú���
//
//	return 0;
//}