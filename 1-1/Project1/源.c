#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char ass1[20] = "0";//�˺�
	char ass2[20] = "0";//����
	char ass3[20] = "147852369";//�˺�
	char ass4[20] = "741852963";//����

	for (int i = 0; i < 3; i++)
	{
		printf("�������˺�>:");
		scanf("%s", &ass1);
		printf("����������>:");
		scanf("%s", &ass2);
		if (strcmp(ass1, ass3) == 0)
		{
			;
		}

		else if (strcmp(ass2, ass4) == 0 && strcmp(ass1, ass3) == 0)
		{
			printf("��½�ɹ�");
			break;
		}
		else
		{
			printf("�˺Ż��������");
			putchar('\n');
		}
	}
	return 0;
}