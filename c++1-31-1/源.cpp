#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>

int main()
{
	char a = -128;
	printf("%u", a);
	return 0;
}


//inline int fun(int &a, int &b)
//{
//	a = 20;
//	b = 30;
//	return a + b;
//}
//
//int main()
//{
//	int a = 100;
//	int b = 20; 
//
//	std::cout << "a=" << a <<" " << "b=" << b << '\n';
//
//	int c = fun(a, b);
//	
//	std::cout << "a&=" << a <<" " << "b&=" << b <<" " << c <<  '\n';
//
//	return 0;
//}