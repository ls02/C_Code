#pragma once
#include "test.h"

//创建链表
LL *Linked_list()
{
	LL *tem = (LL*)malloc(sizeof(LL));//创建一个空间给链表
	if (tem == NULL)//判断是否创建成功
	{
		return NULL;
	}

	tem->head = NULL;//防止生成野指针
	tem->end = NULL;
	tem->length = 0;

	return tem;//返回这个链表创建好的地址
}

//创建链表节点
Node *creation(Pyte val)
{
	Node *tem = (Node*)malloc(sizeof(Node));//创建一个空间给节点

	if (tem == NULL)//判断是否生创建成功
	{
		return NULL;
	}

	tem->data = val;//给数据域赋值
	tem->chain = NULL;//后面无节点连接给NULL，防止生成野指针

	return tem;//返回这个创建好的节点地址
}

//链表节点尾插
void list_end(LL *list, Pyte val)
{
	if (list == NULL)
	{
		printf("没有此链表！\n");
	}
	if (list->head == NULL)//如果没有节点就创建节点作为头部
	{
		//因为只有一个节点所以头即尾
		list->head = list->end = creation(val);//创建一个节点
		list->length++;//计算节点长度，每增加一个节点就自增一
	}
	else
	{
		list->end->chain = creation(val);//先用尾巴的铁链连接新创建的节点，再用尾巴连接新创建的节点
		list->end = list->end->chain;//新创建的节点成为新的尾部
		list->length++;//节点加一
	}
}

//链表输出
void display(LL *list)
{
	if (list == NULL || list->head == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	for (Node *tem = list->head; tem != NULL; tem = tem->chain)//如果不为空执行，并且把下一个连接点的地址给tem
	{
		printf("%d->", tem->data);//输出数据域
	}
	printf("NULL\n");
}

//任意位置插入
void list_insert(LL* list, int extent, Pyte val)
{
	if (list == NULL)
	{
		printf("链表为空\n");
		return;
	}
	if (0 >= extent)//不能在没有链表的情况下插入
	{
		printf("输入错误！\n");
		return;
	}
	
	if (extent > list->length + 1)//不能超过整链表的长度
	{
		printf("超出链表长度!\n");
		return;
	}

	if (1 == extent)//新的头节点创建
	{
		Node* tem = creation(val);//创建界一个节点
		tem->chain = list->head;//新节点连接头节点
		list->head = tem;//新节点成为新的头节点
		list->length++;//节点长度加一
		return;
	}

	if (extent == list->length + 1)//新的尾部节点
	{
		Node* tem = creation(val);//创建一个节点
		list->end->chain = tem;//尾部的空节点连接上新创建的节点
		list->end = tem;//新创建的节点成为新的尾部
		list->length++;//节点长度加一
		return;
	}

	Node* tem = list->head;//tem存放头部节点
	for (int i = 1; i < extent-1; i++)
	{

		tem = tem->chain;//找到要插入的节点前一个
	}
	Node *Nex = creation(val);//创建一个节点
	Nex->chain = tem->chain;//Nex连接tem的下一个节点
	tem->chain = Nex;//tem连接Nex这个节点
	list->length++;//链表长度加一
}

//删除链表上的节点并返回被删除的节点的值
Pyte list_delete(LL* list, int extent)
{
	if (list == NULL || 0 >= extent)//判断是否是空链
	{
		printf("此链表是空链表！\n");
		return NULL;
	}
	
	if (list->length < extent)//判断是否超出链表长度
	{
		printf("超出链表范围！\n");
		return NULL;
	}

	if (1 == extent)//头部节点删除
	{
		Node* tem = list->head;//头节点的地址给tem
		Pyte a = tem->data;//把删除的值给a
		list->head = tem->chain;//头节点指向下个节点，下个节点成为新的头部
		free(tem);//释放曾经的头部节点
		list->length--;//整个链表减少一个
		return a;//返回被删除的值
	}

	if (extent == list->length)//尾部节点删除
	{
		Node* tem = list->head;//创建一个变量存放尾部节点
		for (int i = 1; i < extent - 1; i++)
		{
			tem = tem->chain;//尾部的前一个节点
		}
		Pyte a = list->end->data;//把尾部的节点数据给a
		Node* Nex = list->end;//Nex存放尾部节点
		list->end = tem;//end成为前一个节点
		list->length--;//整个链表减一
		free(Nex);//释放曾经的尾部节点
		list->end->chain = NULL;//新的尾部节点的chain指向空，表示后面自己是末尾后面不需要连接东西
		return a;//返回被删除的末尾节点的数据
	}

	Node* tem = list->head;//tem指向头节点
	for (int i = 1; i < extent-1; i++)
	{
		tem = tem->chain;//插入前一个节点
	}
	Node* Nex= tem->chain;//把前一个节点的下个节点给Nex
	Pyte a = Nex->data;//把Nex的数据给a
	tem->chain = Nex->chain;//前一个节点连接下下个节点
	free(Nex);//释放Nex这个节点
	list->length--;//整个链表减一
	return a;//返回被删除的值
}

Pyte list_get(LL* list, int extent)
{
	if (list == NULL || 0 >= extent)//判断是否为空，或者范围是1以下
	{
		printf("此链表为空！\n");
		return 0;
	}

	if (extent > list->length)//判断是否超出整个链表的长度
	{
		printf("超出链表长度！\n");
		return 0;
	}

	Node* tem = list->head;//把头节点给tem
	for (int i = 1; i < extent; i++)
	{
		tem = tem->chain;//tem指向前一个节点
	}
	return tem->data;//返回节点数据
}

//修改指定节点的数据，并返回被修改的值
Pyte list_modify(LL* list, int extent, Pyte val)
{
	if (list == NULL || 0 >= extent)//判断是否为空链表
	{
		printf("此链表为空");

		return 0;
	}

	if (list->length < extent)//判断是否超出整个链表长度
	{
		printf("超出链表长度！\n");

		return 0;
	}

	Node* tem = list->head;//tem存放头节点
	for (int i = 1; i < extent; i++)
	{
		tem = tem->chain;//extent指定的节点
	}
	Pyte a = tem->data;//把当前节点数据给a
	tem->data = val;//修改节点数据

	return a;//返回被修改节点的值
}

void list_delete_all(LL** list)//要实参改变指向必须得传址，实参是一级指针所以要二级指针才能指向实参
{
	for (Node* tem1=(*list)->head, *tem2; tem1 != NULL;)//创建两个tem来删除
	{
		tem2 = tem1;//tem2用来存放tem一开始的地址
		tem1 = tem1->chain;//tem1连接下个要释放的节点，如果不这样做释放了第一个找不到下一个的地址
		free(tem2);//tem2释放前一个tem1的地址
	}

	free(*list);//释放了整个链表
	*list = NULL;//因为整个链表都释放了实参此时是野指针，为防止生成野指针指向NULL
}