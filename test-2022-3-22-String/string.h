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
		//Ĭ�Ϲ��캯��
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
			,_size(strlen(str))
			,_capacity(strlen(str))
		{
			strcpy(_str, str);
		}

		//���������ִ�д��,����Ĭ�Ϲ��캯������ռ䣬�ٰ�this����Ŀռ��tempĬ�Ϲ�������Ŀռ佻��,�Ӷ��ﵽ�����Ŀ��
		string(const string& s)
			//���ڻ�����������������ʼ����nullptr���ͷŲ������Լ��Ŀռ�����������ͷ�nullptr��ʲô����������Ϊdelete�ڶ�nullptr���ж�
			:_str(nullptr)
		{
			//����temp����Ĭ�Ϲ��캯��
			string temp(s._str);
			//��nullptr��temp����
			swap(temp);
		}

		//��ֵ���أ����������ɵ��޷�����������Ҫ�Լ�д
		//�ִ�д�������ÿ�����������ڴ����룬�ٺ�thisһ������������ڴ�����룬���ڸ�ֵ����һ�㶼�Ǿ���Ĭ�Ϲ������Բ��õ������ֵ����
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

		//��������
		~string()
		{
			delete _str;
			_size = 0;
		}
	};
}

#endif