#pragma once
typedef int Pyte;
#define P "%d "
#define S "%d"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Array
{
	Pyte* defi;
	int len;
}arr;

//�ٹ���һ���յ�˳�����Ա�
arr* kon_biao();

//������˳���
void xiao_hui(arr* a);

//������Ϊ�ձ�
void cz_kong_biao(arr* a);

//���ж��Ƿ�Ϊ�ձ�
int pd_kong_biao(arr* a);

//�ݷ��ص�i������Ԫ�ص�ֵ
Pyte fang_hui(arr* a, int i);

//�޲���˳���Ԫ��
void chai_ru(arr* a, Pyte elem);

//����˳���ָ��λ�ò����µ�����Ԫ��
void cx_chai_ru(arr* a, int index, int elem);

//��ɾ��˳���ָ��λ�õ�����Ԫ��, ������Ԫ�ص�ֵ
Pyte sc_fang_hui(arr* a, int leng);

//�����˳���
void shu_chu(arr* a);

Pyte arr_top(arr* a);//��ͷ����ʼɾ��

Pyte arr_pop(arr* a);//��β��ɾ�������Żر�ɾ��Ԫ��

Pyte arr_get(arr* a,int i);//����˳�����i��ֵ ����ɾ��

void arr_merge(arr* a1, const arr* const a2);//��ָ��2�����ݷŵ�ָ��1����