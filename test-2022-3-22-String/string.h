#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string.h>
#include <iostream>
#include <algorithm>

namespace ls
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	public:
		//默认构造函数
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{
			strcpy(_str, str);
		}

		//拷贝构造现代写法,利用默认构造函数申请空间，再把this对象的空间和temp默认构造申请的空间交换,从而达到深拷贝的目的
		string(const string& s)
			//由于会调用析构，如果不初始化成nullptr会释放不属于自己的空间会出错，如果对释放nullptr则什么都不做，因为delete内对nullptr有判断
			:_str(nullptr)
		{
			//利用temp调用默认构造函数
			string temp(s._str);
			//把nullptr和temp交换
			swap(temp);
		}

		//赋值重载，编译器生成的无法满足需求需要自己写
		//现代写法，利用拷贝构造完成内存申请，再和this一交换即可完成内存的申请，由于赋值重载一般都是经过默认构造所以不用担心随机值问题
		string& operator=(string s)
		{
			swap(s);

			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		//析构函数
		~string()
		{
			delete _str;
			_size = 0;
		}
	};
}

#endif