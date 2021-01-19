#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Pyte;
typedef struct Node//链表节点
{
	Pyte data;
	Node *chain;
}Node;

typedef struct Linked//整个链表
{
	Node *head;//节点开头
	Node *end;//节点末尾
	int length;//节点长度
}LL;

//创建链表
LL *Linked_list();

//创建链表节点
Node *creation(Pyte val);

//链表输出
void display(LL *list);

//链表节点尾插
void list_end(LL *list, Pyte val);

//链表任意位置插入
void list_insert(LL* list, int extent, Pyte val);

//删除链表的节点并返回被删除的值
Pyte list_delete(LL* list, int extent);

//获取指定节点的数据
Pyte list_get(LL* list, int extent);

//修改指定节点的数据,并返回被修改的值
Pyte list_modify(LL* list, int extent,Pyte val);

//单链表的销毁，销毁各个节点
void list_delete_all(LL** list);