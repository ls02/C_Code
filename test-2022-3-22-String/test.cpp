#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
//
//void TestString1()
//{
//	ls::string s1("hello");
//	ls::string s2;
//	s2 += "hell";
//	ls::string s4("qqqqqqqq");
//
//	s2.resize(10);
//	s2 += "abcd";
//	//s3.push_back('q');
//	//s2.insert(5, 'a', 10);
//	//s2.push_back('a');
//	//s2.append("abcdefg");
//	//s2.append(s4);
//	std::cout << s2 << std::endl;
//	std::cout << s2.c_str() << std::endl;
//	//ls::string::iterator it = s2.begin();
//
//	//while (it != s2.end())
//	//{
//	//	std::cout << *it << std::endl;
//	//	++it;
//	//}
//	//for (auto e : s2)
//	//{
//	//	std::cout << e << std::endl;
//	//}
//	//std::cout << s2.c_str() << std::endl;
//}
//
//int main()
//{ 
//	TestString1();
//	//std::string s1("hello");
//	//s1.append("abcdefg");
//	//s1.reserve();
//	//s1.insert(2, "qq", 10);
//	//std::cout << s1 << std::endl;
//
//	return 0;
//}
#include <vector>
void foo(ls::string x)
{
}

void bar(const ls::string& x)
{
}

ls::string baz()
{
	ls::string ret("world");
	return ret;
}

int main()
{
	ls::string s0;
	ls::string s1("hello");
	ls::string s2(s0);
	ls::string s3 = s1;
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	ls::string s4 = baz();

	std::vector<ls::string> svec;
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(baz());
	svec.push_back("good job");
}