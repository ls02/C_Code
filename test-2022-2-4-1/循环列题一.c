#include<stdio.h>


int main()
{
	int ass[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int a = 0, b = 0;
	int sz;
	sz = sizeof(ass) / sizeof(ass[0]);
	b = ass[0];
	int k;
	a = sz - 1;

	printf("请输入一个值：");
	scanf("%d", &k);

	while (a >= b)
	{
		int mid = (a + b) / 2;
		if (ass[mid] > k)
		{
			a = mid - 1;
		}
		else if (ass[mid] < k)
		{
			b = mid + 1;
		}
		else
		{
			printf("找到了，%d", mid);
			break;
		}
	}
	if (a > b)
	{
		printf("没找到");
	}
	return 0;
}