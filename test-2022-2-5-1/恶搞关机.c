#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	char a[20] = {0};


	system("shutdown -s -t 60");

	while(1)
	{
		printf("��ע�⣬��ĵ��Խ���һ�����ڹػ���������룺�������ȡ���ػ�\n������>:");
		scanf("%s", a); 
		if (strcmp(a, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
	}

	return 0;
}