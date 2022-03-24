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
		//������
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

		//Ĭ�Ϲ��캯��
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			, _size(strlen(str))
			, _capacity(strlen(str))
		{
			strcpy(_str, str);
		}

		//���������ִ�д��,����Ĭ�Ϲ��캯������ռ䣬�ٰ�this����Ŀռ��tempĬ�Ϲ�������Ŀռ佻��
		//�Ӷ��ﵽ�����Ŀ��
		string(const string& s)
			//���ڻ�����������������ʼ����nullptr���ͷŲ������Լ��Ŀռ�����
			//������ͷ�nullptr��ʲô����������Ϊdelete�ڶ�nullptr���ж�
			:_str(nullptr)
		{
			//����temp����Ĭ�Ϲ��캯��
			string temp(s._str);
			//��nullptr��temp����
			swap(temp);
		}

		//��ֵ���أ����������ɵ��޷�����������Ҫ�Լ�д
		//�ִ�д�������ÿ�����������ڴ����룬�ٺ�thisһ������������ڴ������
		//���ڸ�ֵ����һ�㶼�Ǿ���Ĭ�Ϲ������Բ��õ������ֵ����
		string& operator=(string s)
		{
			swap(s);

			return *this;
		}

		//����
		void reserve(size_t n = 0)
		{
			//�������Ȼ����������ôû��Ҫ����
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strncpy(temp, _str, _size + 1);
				delete _str;

				_str = temp;
				_capacity = n;
			}
		}

		//����size��С
		void resize(size_t n, const char val = 0)
		{
			//���nС�ڵ�ǰ��С˵�������ݣ�������������С
			if (n < _size)
			{
				_size = n;
				_str[_size] = 0;
			}
			else
			{
				//����Ƿ���Ҫ����
				if (n >= _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; i++)
				{
					_str[i] = val;
				}

				_size = n;
				//���һ��Ԫ���趨Ϊ'\0'
				_str[_size] = 0;
			}
		}

		//����ӿ�
		//����λ�ò���
		string& insert(size_t pos, const string& str)
		{
			assert(pos <= _size);
			size_t len = str.size();
			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			//�м��ͷ��
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
			//β��
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

			//�м��ͷ��
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
			//β��
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

			//�м��ͷ��
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
			//β��
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

		//β��һ���ַ�
		void push_back(const char ch)
		{
			insert(_size, ch);
		}

		//β������һ����
		string& append(const string& str)
		{
			insert(_size, str);

			return *this;
		}
		//β��һ���ַ���
		string& append(const char* s)
		{
			insert(_size, s);

			return *this;
		}

		//+=����
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
		
		//���ҽӿ�
		//��һ���ַ�
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

		//�Ľӿ�
		//�±�����
		//ֻ��
		const char& operator[](size_t i)const
		{
			assert(i < _size);

			return _str[i];
		}
		//�ɶ���д
		char& operator[](size_t i)
		{
			assert(i < _size);

			return _str[i];
		}

		//ɾ�ӿ�
		//����λ��ɾ��
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			
			//���posλ�ú���ĳ���
			size_t leftLen = _size - pos;

			//����ó��Ⱥ�len��Ȼ����˵����ȫɾ
			if (len >= leftLen)
			{
				_size = pos;
				_str[_size] = 0;
			}
			//�������ɾ������
			else
			{
				//���ǰѺ����������ǰ���Ǽ���
				strcpy(_str + pos, _str + len + pos);
				_size -= len;
			}

			return *this;
		}

		//βɾһ���ַ�
		void pop_back(void)
		{
			if (_size > 0)
			{
				_size--;
			}
		}

		//����ַ���
		void clear(void)
		{
			_size = 0;
			_str[_size] = 0;
		}

		//��ȡʵ�ʸ���
		size_t size(void)const
		{
			return _size;
		}

		//����Ƿ�Ϊ�մ�
		bool empty(void)const
		{
			return _size == 0;
		}

		//��ȡ������С
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

		//��������
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