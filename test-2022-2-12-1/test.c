#include <stdio.h>
#include <assert.h>
#include <Windows.h>

int Max(int n, ...)
{
	va_list arg;
	va_start(arg, n);
	int max = va_arg(arg, int);

	int i = 0;
	for (i = 1; i < n; i++)
	{
		int cur = va_arg(arg, int);

		if (cur > max)
		{
			max = cur;
		}
	}

	va_end(arg);

	return max;
}

int main()
{
	char* p = "hello";
	p[0] = 97;
	static int b = 0;
	printf("%p\n", p);
	printf("%p\n", &b);
	//printf("%d\n", Max(5, 1, 2, 3, 4, 5));
	//assert(1);

	//while (1)
	//{
	//	int* p1 = (int*)malloc(1024);
	//	//Sleep(2);
	//}
		
	//- 3.5e-10;
	return 0;
}