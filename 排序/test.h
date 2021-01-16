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

arr* chushihua();//初始化顺序表

void xiaohui(arr* a);//销毁顺序表

void kongbiao(arr* a);//重置为空表

void mao_pao(int* x, int y);//冒泡排序法

void xuan_ze(int* x,int y);//选择排序法

void cha_ru(int* x, int y);//插入排序法

void kuai_su(int* x, int l,int h);//快速排序法

void mao_pao1(xs* x, int y);//冒泡排序法

void xuan_ze1(xs* x, int y);//选择排序法

void cha_ru1(xs* x, int y);//插入排序法

void mao_pao22(Pyte* x, int y);//冒泡排序法

void shu_chu(arr* a);

void chai_ru(arr* a, Pyte elem);//插入顺序表