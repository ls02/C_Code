#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Pyte;

typedef struct array
{
	Pyte* defi;
	int len;
}arr;

typedef struct xue_sheng
{
	int ID;
	char name[20];
}xs;

arr* chushihua();//��ʼ��˳���

void xiaohui(arr* a);//����˳���

void kongbiao(arr* a);//����Ϊ�ձ�

void mao_pao(int* x, int y);//ð������

void xuan_ze(int* x,int y);//ѡ������

void cha_ru(int* x, int y);//��������

void kuai_su(int* x, int l,int h);//��������

void mao_pao1(xs* x, int y);//ð������

void xuan_ze1(xs* x, int y);//ѡ������

void cha_ru1(xs* x, int y);//��������

void mao_pao22(Pyte* x, int y);//ð������

void shu_chu(arr* a);

void chai_ru(arr* a, Pyte elem);//����˳���