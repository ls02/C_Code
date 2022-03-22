#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"

void TestString1()
{
	ls::string s1("hello");
	ls::string s2(s1);
	ls::string s3;
	s3 = s1;

	std::cout << s3 << std::endl;
}

int main()
{ 
	TestString1();

	return 0;
}