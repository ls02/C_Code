#include <stdio.h>

//返回真是小端
//返回假是大端
int CheckSys()
{
	int x = 1;

	return (*(char*)&x);
}

int main()
{
	if (CheckSys())
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	
	//6.8
	//110.1
	//S=(-1)^0
	//E=2^2
	//M=1.101,M去掉第一位：101
	//中间值：2 + 127 = 129（ps：E的指数加上中间值127（32位：127，64位：1023））
	//中间值二进制：00000000 00000000 00000000 10000001
	//




	return 0;
}