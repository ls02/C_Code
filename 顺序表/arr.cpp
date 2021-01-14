#define _CRT_SECURE_NO_WARNINGS 1
#include "Arr.h"

arr* kon_biao()//˳����ʼ��
{
	arr* tem = (arr*)malloc(sizeof(arr));
	assert(tem != NULL);
	tem->defi = (Pyte*)malloc(sizeof(Pyte));
	tem->len = 0;
	return tem;
}

void xioa_hui(arr* a)//����˳���
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a->defi);
	free(a);
}

void cz_kong_biao(arr* a)//����Ϊ�ձ�
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a);
	a->defi = (Pyte*)calloc(1,sizeof(Pyte));
	a->len = 0;
}

Pyte fang_hui(const arr* a, int i)//���ص�i����ֵ
{
	assert(a != NULL);
	assert(a->defi != NULL);
	return a->defi[i];
}

void chai_ru(arr* a, Pyte elem)//����˳���
{
	assert(a != NULL);
	assert(a->defi != NULL);
	a->len++;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	a->defi[a->len - 1] = elem;
}

void cx_chai_ru(arr* a, int index, int elem)
{
	assert(a->defi!=NULL);
	assert(a!=NULL);
	int i = a->len++;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);	//˳����������ڴ�����
	for (; i > index - 1; i--)
	{
		a->defi[i] = a->defi[i - 1];
	}
	a->defi[i] = elem;
}

Pyte sc_fang_hui(arr* a, int leng)//ɾ��˳���ָ��λ�õ�����Ԫ��, ������Ԫ�ص�ֵ
{
	assert(a != NULL);
	assert(a->defi != NULL);
	Pyte ene = a->defi[leng - 1];
	int i = leng - 1;
	for (; i < a->len; i++)
	{
		a->defi[i] = a->defi[i + 1];
	}
	a->len--;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	return ene;
}

void shu_chu(arr* a)
{
	assert(a != NULL);
	assert(a->defi != NULL);
	int i = 0;
	for (i = 0; i < a->len; i++)
	{
		printf(P, a->defi[i]);
	}
	putchar('\n');
}

Pyte arr_top(arr* a)//ɾ��˳���ͷ��λ�õ�����Ԫ��, ������Ԫ�ص�ֵ
{
	assert(a != NULL);
	assert(a->defi != NULL);
	
	int i,k;
	k = a->defi[0];
	for (i = 0; i < a->len; i++)
	{
		a->defi[i] = a->defi[i + 1];
	}
	a->len--;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	return k;
}

Pyte arr_pop(arr* a)//��β��ɾ�������Żر�ɾ��Ԫ��
{
	assert(a != NULL);
	assert(a->defi != NULL);

	int k;
	k = a->len;
	a->len--;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	return k;
}

Pyte arr_get(arr* a, int i)
{
	assert(a->defi != NULL);
	assert(a != NULL);

	return a->defi[i-1];
}

void arr_merge(arr* a1, const arr* const a2)//��ָ��2�����ݷŵ�ָ��1����
{
	assert(a2 != NULL);
	assert(a2->defi != NULL);
	for (int i = 0; i < a2->len; i++)
	{
		chai_ru(a1, a2->defi[i]);
	}
}