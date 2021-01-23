#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int Pyte;

typedef struct Node//节点
{
	Pyte data;//数据
	Node* next;//链条
}Node;

typedef struct List//链表
{
	Node* head;//节点头
	Node* end;//节点尾部
	int length;//节点长度
}LL;


//创建节点
Node* node_fount();

//创建链表
LL* list_fount();

//节点尾部插入
void list_insert_end(LL* list,Pyte val);

//节点任意位置插入
void list_insert(LL* list, int place, Pyte val);

//冒泡排序节点数据
void list_bubbing_sort(LL* list);

//节点数据修改
void list_amend(LL* list,int place,Pyte val);

//返回指定节点数据
Pyte list_return_data(LL* list, int place);

//整个链表销毁
void list_delete_all(LL** list);

//输出链表
void list_export(LL* list);