#pragma once
#include <stdio.h>
#include <stdlib.h>
//1.����˳���
//�ṹ�� vector:�������
typedef struct 
{
	//1.ָ�� �洢������ڴ���׵�ַ
	int* pV;
	//2.������ ��¼��ǰ�ı�����Ԫ�ظ���
	size_t capacity;
	//3.���� ��ǰӵ�е�Ԫ�س���
	int size;
}vector;
//��ʼ��
//����˳���
//����: ����(���������ڴ�Ĵ�С)
//����ֵ: ��
vector InitVector(int n);

//����˳���
//����
//����: ��ָ�� ����
//����ֵ: ��ָ��
vector* CheckCapacityVector(vector* pVector);

//����
//β������Ԫ��
//����: ��ָ�� ��ֵ
//����ֵ: ��ָ��
vector* PushBackVector(vector* pVector, int num);
//����λ�ò���Ԫ��
//����: ��ָ�� ��ֵ λ��
//����ֵ: ��ָ��
vector* InsertVector(vector* pVector, int num, int pos);

//�ͷű�
//���� ��
//����ֵ: ��
void DestoryVector(vector temp);

//����Ԫ��
//����: �� ��ֵ
//����ֵ: ����
int FindWithVector(vector temp, int num);

//ɾ��
//ɾ�������Ԫ��
//����: ��ָ�� ����
vector* DelPosVector(vector* pVector, int pos);
//ɾ��β����Ԫ��
//����: ��ָ��
//����ֵ: ��ָ��
vector* PopBackVector(vector* pVector);
