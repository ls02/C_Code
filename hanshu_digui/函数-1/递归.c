#include<stdio.h>
int ass(int a);
int main()
{
	int a, b;

	scanf("%d", &a);

	b = ass(a);
	printf("%d", b);
}

int ass(int a)
{
	if (a < 1)
	{
		return 0;
	}//4+3=7+2=9+1=10
	return a + ass(a - 1);
	//总结就是if为结束条件后面的return 为0就是说我执行完了就不执行了如果是1我就多执行一次如果是负一我就少 执行一次
	//return a这个值是不变的，ass（a-1）是一直变化的就是这里面的a条件不满足if他就一直循环直到满足，满足执行return 0
}