#include <stdio.h>
int main()
{
	const int a = 10;//a���ܱ��޸ľ��г����� int const a = 10;���������

	const int* p1 = &a;
	int const* p2 = &a;//��������ȣ���ʾp2��p1ָ�����ָ���ָ���޷����޸�

	int* const p3 = &a;//��ʾ��ָ����������޸�ָ����Զ��ָ��a

	const int* const p4 = &a;//��ʾ��ָ����������޸�ָ����Ҳ�����޸�ָ��

	return 0;
}

//#define ABC
//int main()
//{
//	int a = 0x11223344;
//	int* const p = &a;
//	//p = 20;
//	printf("%#o %d", a, ABC);
//
//	return 0;
//}

//int main()
//{
// 
//    int i = 0;
//
//head:
//
//    while (i < 10)
//    {
//        if (i == 5)
//        {
//            i++;
//            goto head;
//        }
//        printf("%d ", i);
//        i++;
//    }
//
//	return 0;
//}