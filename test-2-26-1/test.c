#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int y = 0;
	int k = 0;

	y = i++,i++;

	printf("%d", y);

	return 0;
}

//int main()
//{
//	int i, x, y;
//	i = x = y = 0;
//
//	do
//	{
//		++i;
//		//i = 1
//		//x = 1
//		//y = 
//
//		if (i % 2)
//		{
//			x += i,
//				i++;
//		}
//		y += i++;
//	} while (i <= 7);
//
//	printf("%d %d %d", i, x, y);
//
//	return 0;
//}