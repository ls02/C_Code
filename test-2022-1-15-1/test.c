#include <stdio.h>

void Move(int n, const char pos1, const char pos3)
{
	printf("第%d个盘子从%c柱子移动到%c柱子\n", n, pos1, pos3);
}

void Hanoi(int n, const char pos1, const char pos2, const char pos3)
{
	if (1 == n)
	{
		Move(n, pos1, pos3);

	}
	else
	{
		Hanoi(n - 1, pos1, pos3, pos2);
		Move(n, pos1, pos3);
		Hanoi(n - 1, pos2, pos1, pos3);

	}
}

int main()
{
	int n = 3;
	char pos1 = 'A';
	char pos2 = 'B';
	char pos3 = 'C';

	Hanoi(n, pos1, pos2, pos3);

	return 0;
}