#pragma once
#include <stdio.h>

//ð������ʵ�ֵĿ���
extern void QSortBubbli(void* base, size_t num, size_t width, int (*comp)(const void* e1, const void* e2));

//��������
extern void Swap(char* e1, char* e2, size_t width);
