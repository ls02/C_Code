#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	char a[20] = {0};


	system("shutdown -s -t 60");

	while(1)
	{
		printf("请注意，你的电脑将在一分钟内关机，如果输入：我是猪就取消关机\n请输入>:");
		scanf("%s", a); 
		if (strcmp(a, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
	}

	return 0;
}