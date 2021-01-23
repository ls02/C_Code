#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//创建一个节点
Node* node_fount()
{
	Node* tem = (Node*)malloc(sizeof(Node));//申请一个节点空间
	tem->data = 0;//初始化
	tem->next = NULL;//初始化

	return tem;
}

//创建链表
LL* list_fount()
{
	LL* tem = (LL*)malloc(sizeof(LL));//申请一个链表空间
	tem->end = tem->head = NULL;//初始化
	tem->length = 0;//初始化

	return tem;
}

//节点尾部插入
void list_insert_end(LL* list, Pyte val)
{
	assert(list);
	if (list->head == NULL)//判断是否有头部节点
	{
		list->end = list->head = node_fount();//没有头部头即尾，尾即头
		list->end->data = 0;

		list -> end = list->head->next = node_fount();
		list->end->data = val;
		list->length++;
		
		return;
	}

	Node* tem = node_fount();//新的节点
	list->end = list->end->next = tem;//新节点成为尾部
	list->end->data = val;
	list->length++;//节点长度加一
}

//节点任意位置插入
void list_insert(LL* list, int place, Pyte val)
{
	assert(list);
	if (list->head == NULL)
	{
		printf("链表为空！\n");

		return;
	}
	if (list->length + 1 < place || 0 >= place)
	{
		printf("插入错误！\n");

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

//输出链表
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

//冒泡排序数据
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

//节点数据修改
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

//返回指定节点数据
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

//整个链表销毁
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