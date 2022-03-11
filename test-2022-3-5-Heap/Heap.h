#pragma once
#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>

namespace ls
{
	typedef int HPDateType;
	class Heap
	{
	private:
		HPDateType* _data;
		int _size;
		int _capacity;

	public:
		Heap(HPDateType* arr, int size)
		{
			_data = new HPDateType[size];
			_capacity = size;
			_size = size;

			memcpy(_data, arr, sizeof(HPDateType) * size);

			for (int i = (size - 2) / 2; i >= 0; i--)
			{
				AdjustDown(_size, i);
			}
		}
		
		//向下调整
		void AdjustDown(int size, HPDateType parent)
		{
			HPDateType child = parent * 2 + 1;

			while (child < size)
			{
				if (child + 1 < size && _data[child + 1] > _data[child])
				{
					child++;
				}

				if (_data[child] > _data[parent])
				{
					Swap(_data + child, _data + parent);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		//向上调整
		void AdjustUp(HPDateType child)
		{
			HPDateType parent = (child - 1) / 2;

			while (child > 0)
			{
				if (_data[child] > parent)
				{
					Swap(_data + child, _data + parent);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void Swap(HPDateType* p1, HPDateType* p2)
		{
			HPDateType temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}

		void Push(HPDateType val)
		{
			if (_size == _capacity)
			{
				HPDateType* temp = new HPDateType[_capacity * 2];
				memcpy(temp, _data, sizeof(HPDateType) * _size);
				delete[] _data;
				_data = temp;
			}
			_data[_size++] = val;
			AdjustUp(_size - 1);
		}

		void Print(void)
		{
			for (int i = 0; i < _size; i++)
			{
				std::cout << _data[i] << " ";
			}

			putchar('\n');
		}
		
		void Pop(void)
		{
			Swap(_data, _data + _size - 1);
			_size--;
			AdjustDown(_size, 0);
		}

		int Top(void)
		{
			return _data[0];
		}

		int Size(void)
		{
			return _size;
		}

	};
}

#endif
