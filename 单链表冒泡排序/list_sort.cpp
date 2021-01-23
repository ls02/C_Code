#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//����һ���ڵ�
Node* node_fount()
{
	Node* tem = (Node*)malloc(sizeof(Node));//����һ���ڵ�ռ�
	tem->data = 0;//��ʼ��
	tem->next = NULL;//��ʼ��

	return tem;
}

//��������
LL* list_fount()
{
	LL* tem = (LL*)malloc(sizeof(LL));//����һ������ռ�
	tem->end = tem->head = NULL;//��ʼ��
	tem->length = 0;//��ʼ��

	return tem;
}

//�ڵ�β������
void list_insert_end(LL* list, Pyte val)
{
	assert(list);
	if (list->head == NULL)//�ж��Ƿ���ͷ���ڵ�
	{
		list->end = list->head = node_fount();//û��ͷ��ͷ��β��β��ͷ
		list->end->data = 0;

		list -> end = list->head->next = node_fount();
		list->end->data = val;
		list->length++;
		
		return;
	}

	Node* tem = node_fount();//�µĽڵ�
	list->end = list->end->next = tem;//�½ڵ��Ϊβ��
	list->end->data = val;
	list->length++;//�ڵ㳤�ȼ�һ
}

//�ڵ�����λ�ò���
void list_insert(LL* list, int place, Pyte val)
{
	assert(list);
	if (list->head == NULL)
	{
		printf("����Ϊ�գ�\n");

		return;
	}
	if (list->length + 1 < place || 0 >= place)
	{
		printf("�������\n");

		return;
	}

	if (place == 1)
	{
		Node* tem = node_fount();
		tem->next = list->head->next;
		list->head->next = tem;
		tem->data = val;
		list->length++;
		
		return;
	}
	
	int i = 1;
	Node* tem = list->head->next;
	for (i = 1; i < place-1; i++)
	{
		tem = tem->next;
	}

	Node* Nex = node_fount();
	Nex->next = tem->next;
	tem->next = Nex;
	Nex->data = val;
	list->length++;
}

//�������
void list_export(LL* list)
{
	assert(list);
	for (Node* tem = list->head->next; tem != NULL;)
	{
		printf("%d->", tem->data);
		tem = tem->next;
	}
	printf("NULL\n");
}

//ð����������
void list_bubbing_sort(LL* list)
{
	assert(list);
	assert(list->head->next);
	Node* tem1 = list->head->next;
	Node* tem2 = tem1->next;
	int i = 0;
	int j = 0;
	for (i = 1; i < list->length - 1; i++)
	{
		for (j = 1; j < list->length - 1; j++)
		{
			if (tem1->data > tem2->data)
			{
				int tem = tem1->data;
				tem1->data = tem2->data;
				tem2->data = tem;
			}
			tem1 = tem1->next;
			tem2 = tem2->next;
		}
		tem1 = list->head->next;
		tem2 = tem1->next;
	}
}

//�ڵ������޸�
void list_amend(LL* list, int place, Pyte val)
{
	assert(list);
	assert(list->head->next);
	Node* tem = list->head->next;
	int i = 0;

	for (i = 1; i < place; i++)
	{
		tem = tem->next;
	}

	tem->data = val;

}

//����ָ���ڵ�����
Pyte list_return_data(LL* list, int place)
{
	assert(list);
	assert(list->head->next);
	Node* tem = list->head->next;
	int i = 0;

	for (i = 1; i < place; i++)
	{
		tem = tem->next;
	}

	return tem->data;
}

//������������
void list_delete_all(LL** list)
{
	assert(*list);
	assert(list);

	Node* tem1 = (*list)->head;
	Node* tem2;

	for (; tem1 != NULL;)
	{
		tem2 = tem1;
		tem1 = tem1->next;
		free(tem2);
	}
	free(*list);
	(*list) = NULL;
}