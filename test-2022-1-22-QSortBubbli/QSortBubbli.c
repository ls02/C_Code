#include "QSortBubbli.h"

void Swap(char* buf1, char* buf2, size_t width)
{
	size_t i = 0;

	//����width���͵�����
	for (i = 0; i < width; i++)
	{
		char temp = *buf1;
		*buf1 = *buf2;
		*buf2 = temp;

		//��Ϊ��������һ���ֽڣ�����Ҫ����width�ֽڵĽ���
		buf1++;
		buf2++;
	}
}


void QSortBubbli(void* base, size_t sz, size_t width, int (*comp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;

	for (i = 0; i < (int)sz; i++)
	{
		for (j = 0; j < (int)sz - 1 - i; j++)
		{
			//�������0�ͽ�������������
			if (comp((char*)base + j * width, (char*)base + (j + 1)* width) > 0)
			{
				//��������ֵ
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
