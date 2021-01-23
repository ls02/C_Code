#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int Pyte;

typedef struct Node//�ڵ�
{
	Pyte data;//����
	Node* next;//����
}Node;

typedef struct List//����
{
	Node* head;//�ڵ�ͷ
	Node* end;//�ڵ�β��
	int length;//�ڵ㳤��
}LL;


//�����ڵ�
Node* node_fount();

//��������
LL* list_fount();

//�ڵ�β������
void list_insert_end(LL* list,Pyte val);

//�ڵ�����λ�ò���
void list_insert(LL* list, int place, Pyte val);

//ð������ڵ�����
void list_bubbing_sort(LL* list);

//�ڵ������޸�
void list_amend(LL* list,int place,Pyte val);

//����ָ���ڵ�����
Pyte list_return_data(LL* list, int place);

//������������
void list_delete_all(LL** list);

//�������
void list_export(LL* list);