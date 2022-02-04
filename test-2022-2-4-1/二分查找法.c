//#include<stdio.h>
//
//int main()//main是主函数接收0的也是整个程序的入口，一个程序只能有一个main（）
//{
//	int ass[] = { 0,1,2,3,4,5,6,7,8,9 };
//	int a = 0;
//	int sz = sizeof(ass) / sizeof(ass[0]);
//	int b = sz - 1;
//	
//	int kk;
//	printf("请输入一个值：");
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
//			printf("找到了！%d", mid);
//			break;
//		}
//		
//	}
//	if(a>b)
//	{
//		printf("找不到你要的数！");
//	}
//
//	return 0;
//} 