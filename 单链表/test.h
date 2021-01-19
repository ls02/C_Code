#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Pyte;
typedef struct Node//����ڵ�
{
	Pyte data;
	Node *chain;
}Node;

typedef struct Linked//��������
{
	Node *head;//�ڵ㿪ͷ
	Node *end;//�ڵ�ĩβ
	int length;//�ڵ㳤��
}LL;

//��������
LL *Linked_list();

//��������ڵ�
Node *creation(Pyte val);

//�������
void display(LL *list);

//����ڵ�β��
void list_end(LL *list, Pyte val);

//��������λ�ò���
void list_insert(LL* list, int extent, Pyte val);

//ɾ������Ľڵ㲢���ر�ɾ����ֵ
Pyte list_delete(LL* list, int extent);

//��ȡָ���ڵ������
Pyte list_get(LL* list, int extent);

//�޸�ָ���ڵ������,�����ر��޸ĵ�ֵ
Pyte list_modify(LL* list, int extent,Pyte val);

//����������٣����ٸ����ڵ�
void list_delete_all(LL** list);