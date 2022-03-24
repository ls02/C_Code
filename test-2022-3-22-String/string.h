#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string.h>
#include <iostream>
#include <algorithm>
#include <assert.h>

namespace ls
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos;

	public:
		//迭代器
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin(void)
		{
			return _str;
		}

		const_iterator begin(void)const
		{
			return _str;
		}

		iterator end(void)
		{
			return _str + _size;
		}

		const_iterator end(void)const
		{
			return _str + _size;
		}

		//默认构造函数
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capacity(strlen(str))
		{
			strcpy(_str, str);
		}

		//拷贝构造现代写法,利用默认构造函数申请空间，再把this对象的空间和temp默认构造申请的空间交换
		//从而达到深拷贝的目的
		string(const string& s)
			//由于会调用析构，如果不初始化成nullptr会释放不属于自己的空间会出错，
			//如果对释放nullptr则什么都不做，因为delete内对nullptr有判断
			:_str(nullptr)
		{
			//利用temp调用默认构造函数
			string temp(s._str);
			//把nullptr和temp交换
			swap(temp);
		}

		//赋值重载，编译器生成的无法满足需求需要自己写
		//现代写法，利用拷贝构造完成内存申请，再和this一交换即可完成内存的申请
		//由于赋值重载一般都是经过默认构造所以不用担心随机值问题
		string& operator=(string s)
		{
			swap(s);

			return *this;
		}

		//扩容
		void reserve(size_t n = 0)
		{
			//如果不相等或大于容量那么没必要扩容
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strncpy(temp, _str, _size + 1);
				delete _str;

				_str = temp;
				_capacity = n;
			}
		}

		//增加size大小
		void resize(size_t n, const char val = 0)
		{
			//如果n小于当前大小说明是缩容，容量不动动大小
			if (n < _size)
			{
				_size = n;
				_str[_size] = 0;
			}
			else
			{
				//检查是否需要扩容
				if (n >= _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = val;
				}

				_size = n;
				//最后一个元素设定为'\0'
				_str[_size] = 0;
			}
		}

		//插入接口
		//任意位置插入
		string& insert(size_t pos, const string& str)
		{
			assert(pos <= _size);
			size_t len = str.size();
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			//中间和头插
			if (pos < _size)
			{
				size_t end = _size + 1;
				while (end > pos)
				{
					_str[end + len - 1] = _str[end - 1];
					end--;
				}

				strncpy(_str + pos, str._str, str._size);
			}
			//尾插
			else
			{
				strcpy(_str + _size, str._str);
			}

			_size += len;

			return *this;
		}

		string& insert(size_t pos, const char* s)
		{
			assert(pos <= _size);

			size_t len = strlen(s);
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			//中间和头插
			if (pos < _size)
			{
				size_t end = _size + 1;
				while (end > pos)
				{
					_str[end + len - 1] = _str[end - 1];
					end--;
				}

				strncpy(_str + pos, s, len);
			}
			//尾插
			else
			{
				strcpy(_str + _size, s);
			}

			_size += len;

			return *this;
		}

		string& insert(size_t pos, const char* s, size_t n)
		{
			assert(pos <= _size);

			size_t len = n;
			if (len > strlen(s))
			{
				len = strlen(s);
			}

			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			//中间和头插
			if (pos < _size)
			{
				size_t end = _size + 1;
				while (end > pos)
				{
					_str[end + len - 1] = _str[end - 1];
					end--;
				}

				strncpy(_str + pos, s, len);
			}
			//尾插
			else
			{
				strncpy(_str + _size, s, len);
			}

			_size += len;
			_str[_size] = 0;
			return *this;
		}

		string& insert(size_t pos, const char ch)
		{
			assert(pos <= _size);

			if (_size >= _capacity)
			{
				reserve(_size * 2);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;
			_size++;

			return *this;
		}

		string& insert(size_t pos, const char ch, size_t n)
		{
			assert(pos <= _size);

			size_t len = n;
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end + len - 1] = _str[end - 1];
				end--;
			}

			memset(_str + pos, ch, len);
			_size += len;

			return *this;
		}

		//尾插一个字符
		void push_back(const char ch)
		{
			insert(_size, ch);
		}

		//尾部插入一个类
		string& append(const string& str)
		{
			insert(_size, str);

			return *this;
		}
		//尾插一个字符串
		string& append(const char* s)
		{
			insert(_size, s);

			return *this;
		}

		//+=重载
		string& operator+=(const string& str)
		{
			insert(_size, str);

			return *this;
		}

		string& operator+=(const char* s)
		{
			insert(_size, s);

			return *this;
		}

		string& operator+=(const char ch)
		{
			insert(_size, ch);

			return *this;
		}
		
		//查找接口
		//找一个字符
		size_t find(const char ch, size_t pos = 0)const
		{
			assert(pos < _size);

			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* s, size_t pos = 0)const
		{
			char* index = strstr(_str + pos, s);

			if (nullptr != index)
			{
				return index - _str;
			}
			else
			{
				return npos;
			}
		}

		//改接口
		//下标重载
		//只读
		const char& operator[](size_t i)const
		{
			assert(i < _size);

			return _str[i];
		}
		//可读可写
		char& operator[](size_t i)
		{
			assert(i < _size);

			return _str[i];
		}

		//删接口
		//任意位置删除
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			
			//求出pos位置后面的长度
			size_t leftLen = _size - pos;

			//如果该长度和len相等或大于说明是全删
			if (len >= leftLen)
			{
				_size = pos;
				_str[_size] = 0;
			}
			//否则就是删除部分
			else
			{
				//我们把后面的数据往前覆盖即可
				strcpy(_str + pos, _str + len + pos);
				_size -= len;
			}

			return *this;
		}

		//尾删一个字符
		void pop_back(void)
		{
			if (_size > 0)
			{
				_size--;
			}
		}

		//清除字符串
		void clear(void)
		{
			_size = 0;
			_str[_size] = 0;
		}

		//获取实际个数
		size_t size(void)const
		{
			return _size;
		}

		//检查是否为空串
		bool empty(void)const
		{
			return _size == 0;
		}

		//获取容量大小
		size_t capacity(void)const
		{
			return _capacity;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		const char* c_str(void)const
		{
			return _str;
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	};

	const size_t ls::string::npos = -1;

	inline bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	inline bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	
	inline bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	inline bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		
		return out;
	}


	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		int ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	std::istream& getline(std::istream& in, string& s)
	{
		s.clear();

		int ch = in.get();
		while (ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}
}
#endif