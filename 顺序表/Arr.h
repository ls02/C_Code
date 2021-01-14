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

//①构造一个空的顺序线性表
arr* kon_biao();

//②销毁顺序表
void xiao_hui(arr* a);

//③重置为空表
void cz_kong_biao(arr* a);

//④判断是否为空表
int pd_kong_biao(arr* a);

//⑤返回第i个数据元素的值
Pyte fang_hui(arr* a, int i);

//⑥插入顺序表元素
void chai_ru(arr* a, Pyte elem);

//⑦在顺序表指定位置插入新的数据元素
void cx_chai_ru(arr* a, int index, int elem);

//⑧删除顺序表指定位置的数据元素, 并返回元素的值
Pyte sc_fang_hui(arr* a, int leng);

//⑨输出顺序表
void shu_chu(arr* a);

Pyte arr_top(arr* a);//从头部开始删除

Pyte arr_pop(arr* a);//从尾部删除，并放回被删除元素

Pyte arr_get(arr* a,int i);//返回顺序表中i的值 ，不删除

void arr_merge(arr* a1, const arr* const a2);//把指针2的内容放到指针1里面