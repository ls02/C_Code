//#include<stdio.h>
//
//int main()//main������������0��Ҳ�������������ڣ�һ������ֻ����һ��main����
//{
//	int ass[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int a = 0;
//	int sz = sizeof(ass) / sizeof(ass[0]);
//	int b = sz - 1;
//	
//	int kk;
//	printf("������һ��ֵ��");
//	scanf_s("%d",&kk);
//	while (a <= b)
//	{
//		int mid = (a + b) / 2;
//		if (ass[mid] > kk)
//		{
//			b = mid - 1;
//		}
//		else if (ass[mid] < kk)
//		{
//			a = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ�%d", mid);
//			break;
//		}
//		
//	}
//	if(a>b)
//	{
//		printf("�Ҳ�����Ҫ������");
//	}
//
//	return 0;
//} 