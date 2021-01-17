#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>

//int main()//二分查找法
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int hen = sz - 1;
//	int mid = 0;
//	int k;
//
//	scanf("%d", &k);
//
//	while (len <= hen)
//	{
//		mid = (len + hen) / 2;
//		if (arr[mid] > k)
//		{
//			hen = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			len = mid + 1;
//		}
//		else
//		{
//			printf("找到了！下标是：%d", mid);
//			break;
//		}
//	}
//
//	if (len > hen)
//	{
//		printf("找不到！\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int hen = sz - 1;
//	int len = 0;
//	int i = 0;
//
//	int k = 9;
//
//	while (len<=hen)
//	{
//		int mid = (len + hen) / 2;
//		if (arr[mid]>k)
//		{
//			hen = mid-1;
//		}
//		else if (arr[mid] < k)
//		{
//			len = mid+1;
//		}
//		else
//		{
//			printf("找到了！下标是：%d",mid);
//			break;
//		}
//	}
//
//	if (len > hen)
//	{
//		printf("找不到！\n");
//	}
//
//	return 0;
//}

//int main()//n的阶乘相加
//{
//	int a;
//	int i = 0;
//	int ret = 1;
//	int k = 0;
//
//	scanf("%d", &a);
//
//	for (i = 1; i <= a; i++)
//	{
//		ret *= i;
//		k += ret;
//	}
//	printf("%d\n", k);
//	return 0;
//}

//int main()
//{
//	int a;
//	int i = 0;//n的阶乘
//	int ret = 2;
//
//	scanf("%d",&a);
//
//	for (i = 1; i <= a; i++)
//	{
//		ret *=i;
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	do//先执行一次内容
//	{
//		printf("%d ", i);//此时的i=1
//		i++;//此时的i=1
//	} while (i <= 10);//此时的i=2不大于10继续循环
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1; i <= 10; i++)//打印1-10的数，表达式1只会在for开始的时候执行一次，它也是第一个执行的
//	{//表达式2是第二个执行的用于判断是否继续循环表达式3是最后执行的用于跳出循环
//		printf("%d ", i);//打印i的值每执行一次就打印一次
//		continue;//后面的代码不执行但是不影响i++，因为i++执行顺序是最后一个也就是在代码块执行完了才执行它
//	}
//	//执行顺序是：第一个表达式1，第二个表达式2，第三个for语句里面的内容，第四个表达式3
//	return 0;
//}

//int main()
//{
//	char mima[10] = { 0 };
//	
//	printf("请输入密码:>");
//	scanf("%d", mima);//回车作为结束但是它不拿回车，此时的缓冲区留有回车
//	int ch1;
//	while ((ch1 = getchar()) != '\n')//用来清空缓冲区
//	{
//		;
//	}
//	printf("请确认(Y/N):>");
//	int ch = getchar();//此时应该等待用户输入但是缓冲区有回车它直接拿了所以会出现自己不想看到的结果
//
//	if (ch == 'Y')
//	{
//		printf("确认成功！\n");
//	}
//	else
//	{
//		printf("确认失败！\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//
//	while ((ch = getchar()) != EOF)//读取失败EOF就结束EOF是ctrl+z，EOF
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	
//	ch = getchar();//接收一个字符给ch
//	putchar(ch);//输出ch里面的值
//
//	
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;//如果等于5后面的代码不执行
//		printf("%d ", i);//打印出：1,2,3,4，就会死循环不打印一直退不出去
//		i++;//不执行此时的i不会改变所以会造成死循环
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (i == 5)//如果i等于5跳出整个循环也就是共打印：4次，第五次跳出
//			break;
//		printf("%d ", i);
//		i++;
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//
//	while (a<=10)//满足条件就执行，如果a不大于10就一直执行
//	{
//		printf("%d ", a);//没执行一次打印一次
//		a++;//退出循环的条件
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	if(a)//如果不加大括号只能有一个语句是if 的内容；
//		printf("haha\n");
//	printf("999");
//
//	if (a)//此时的两个输出函数才是if语句里面的
//	{
//		printf("heh");
//		printf("6666");
//	}
//
//	return 0;
//}

//int mian()
//{
//	int a = 10;
//
//	switch (a)//括号内为判断内容
//	{
//		case 1:
//			printf("星期一\n");//如果括号内是1则和输入此如果后面没跟break则全部输出直到结束
//			break;
//		case 2:
//			printf("星期二\n");//要么遇到break结束要么全部执行完
//			break;
//		case 3:
//			printf("星期三\n");
//			break;
//		case 4:
//			printf("星期四\n");
//			break;
//		case 5:
//			printf("星期五\n");
//			break;
//		case 6:
//			printf("星期六\n");
//			break;
//		case 7:
//			printf("星期日\n");
//			break;
//		default://defulat如果以上的case没有配对则执行deflaut
//			printf("输入错误！\n");
//			break;
//	}
//
//	return 0;
//}

//int mian()
//{
//	int a = 10;
//
//	if (a != 2)//如果不等于2就执行里面的内容等于就不执行，这是条件判断。
//	{
//		printf("hehe");
//	}
//	else if (a == 4)//else if如果上面的if为假则判断下一个else if
//	{
//		printf("666\n");
//	}
//	else//else语句如果上面的if没有满足的时候执行
//	{
//		printf("haha\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	if (a)//如果没条件只有数字，非零为真，零为假，如果为真执if里面的内容，如果为假，则不执行
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int j = 1;
//	int i = 0;
//	int n = 1;
//	int k = 0;
//
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)//相加的阶乘
//	{
//		j *= i;
//	return 0;
//}

//int main()
//{
//	int b;
//	int k;
//	k = b = 1;
//	printf("%d %d", k, b);
//	return 0;
//}