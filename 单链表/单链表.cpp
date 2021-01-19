#pragma once
#include "test.h"

//��������
LL *Linked_list()
{
	LL *tem = (LL*)malloc(sizeof(LL));//����һ���ռ������
	if (tem == NULL)//�ж��Ƿ񴴽��ɹ�
	{
		return NULL;
	}

	tem->head = NULL;//��ֹ����Ұָ��
	tem->end = NULL;
	tem->length = 0;

	return tem;//��������������õĵ�ַ
}

//��������ڵ�
Node *creation(Pyte val)
{
	Node *tem = (Node*)malloc(sizeof(Node));//����һ���ռ���ڵ�

	if (tem == NULL)//�ж��Ƿ��������ɹ�
	{
		return NULL;
	}

	tem->data = val;//��������ֵ
	tem->chain = NULL;//�����޽ڵ����Ӹ�NULL����ֹ����Ұָ��

	return tem;//������������õĽڵ��ַ
}

//����ڵ�β��
void list_end(LL *list, Pyte val)
{
	if (list == NULL)
	{
		printf("û�д�����\n");
	}
	if (list->head == NULL)//���û�нڵ�ʹ����ڵ���Ϊͷ��
	{
		//��Ϊֻ��һ���ڵ�����ͷ��β
		list->head = list->end = creation(val);//����һ���ڵ�
		list->length++;//����ڵ㳤�ȣ�ÿ����һ���ڵ������һ
	}
	else
	{
		list->end->chain = creation(val);//����β�͵����������´����Ľڵ㣬����β�������´����Ľڵ�
		list->end = list->end->chain;//�´����Ľڵ��Ϊ�µ�β��
		list->length++;//�ڵ��һ
	}
}

//�������
void display(LL *list)
{
	if (list == NULL || list->head == NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	for (Node *tem = list->head; tem != NULL; tem = tem->chain)//�����Ϊ��ִ�У����Ұ���һ�����ӵ�ĵ�ַ��tem
	{
		printf("%d->", tem->data);//���������
	}
	printf("NULL\n");
}

//����λ�ò���
void list_insert(LL* list, int extent, Pyte val)
{
	if (list == NULL)
	{
		printf("����Ϊ��\n");
		return;
	}
	if (0 >= extent)//������û�����������²���
	{
		printf("�������\n");
		return;
	}
	
	if (extent > list->length + 1)//���ܳ���������ĳ���
	{
		printf("����������!\n");
		return;
	}

	if (1 == extent)//�µ�ͷ�ڵ㴴��
	{
		Node* tem = creation(val);//������һ���ڵ�
		tem->chain = list->head;//�½ڵ�����ͷ�ڵ�
		list->head = tem;//�½ڵ��Ϊ�µ�ͷ�ڵ�
		list->length++;//�ڵ㳤�ȼ�һ
		return;
	}

	if (extent == list->length + 1)//�µ�β���ڵ�
	{
		Node* tem = creation(val);//����һ���ڵ�
		list->end->chain = tem;//β���Ŀսڵ��������´����Ľڵ�
		list->end = tem;//�´����Ľڵ��Ϊ�µ�β��
		list->length++;//�ڵ㳤�ȼ�һ
		return;
	}

	Node* tem = list->head;//tem���ͷ���ڵ�
	for (int i = 1; i < extent-1; i++)
	{

		tem = tem->chain;//�ҵ�Ҫ����Ľڵ�ǰһ��
	}
	Node *Nex = creation(val);//����һ���ڵ�
	Nex->chain = tem->chain;//Nex����tem����һ���ڵ�
	tem->chain = Nex;//tem����Nex����ڵ�
	list->length++;//�����ȼ�һ
}

//ɾ�������ϵĽڵ㲢���ر�ɾ���Ľڵ��ֵ
Pyte list_delete(LL* list, int extent)
{
	if (list == NULL || 0 >= extent)//�ж��Ƿ��ǿ���
	{
		printf("�������ǿ�����\n");
		return NULL;
	}
	
	if (list->length < extent)//�ж��Ƿ񳬳�������
	{
		printf("��������Χ��\n");
		return NULL;
	}

	if (1 == extent)//ͷ���ڵ�ɾ��
	{
		Node* tem = list->head;//ͷ�ڵ�ĵ�ַ��tem
		Pyte a = tem->data;//��ɾ����ֵ��a
		list->head = tem->chain;//ͷ�ڵ�ָ���¸��ڵ㣬�¸��ڵ��Ϊ�µ�ͷ��
		free(tem);//�ͷ�������ͷ���ڵ�
		list->length--;//�����������һ��
		return a;//���ر�ɾ����ֵ
	}

	if (extent == list->length)//β���ڵ�ɾ��
	{
		Node* tem = list->head;//����һ���������β���ڵ�
		for (int i = 1; i < extent - 1; i++)
		{
			tem = tem->chain;//β����ǰһ���ڵ�
		}
		Pyte a = list->end->data;//��β���Ľڵ����ݸ�a
		Node* Nex = list->end;//Nex���β���ڵ�
		list->end = tem;//end��Ϊǰһ���ڵ�
		list->length--;//���������һ
		free(Nex);//�ͷ�������β���ڵ�
		list->end->chain = NULL;//�µ�β���ڵ��chainָ��գ���ʾ�����Լ���ĩβ���治��Ҫ���Ӷ���
		return a;//���ر�ɾ����ĩβ�ڵ������
	}

	Node* tem = list->head;//temָ��ͷ�ڵ�
	for (int i = 1; i < extent-1; i++)
	{
		tem = tem->chain;//����ǰһ���ڵ�
	}
	Node* Nex= tem->chain;//��ǰһ���ڵ���¸��ڵ��Nex
	Pyte a = Nex->data;//��Nex�����ݸ�a
	tem->chain = Nex->chain;//ǰһ���ڵ��������¸��ڵ�
	free(Nex);//�ͷ�Nex����ڵ�
	list->length--;//���������һ
	return a;//���ر�ɾ����ֵ
}

Pyte list_get(LL* list, int extent)
{
	if (list == NULL || 0 >= extent)//�ж��Ƿ�Ϊ�գ����߷�Χ��1����
	{
		printf("������Ϊ�գ�\n");
		return 0;
	}

	if (extent > list->length)//�ж��Ƿ񳬳���������ĳ���
	{
		printf("���������ȣ�\n");
		return 0;
	}

	Node* tem = list->head;//��ͷ�ڵ��tem
	for (int i = 1; i < extent; i++)
	{
		tem = tem->chain;//temָ��ǰһ���ڵ�
	}
	return tem->data;//���ؽڵ�����
}

//�޸�ָ���ڵ�����ݣ������ر��޸ĵ�ֵ
Pyte list_modify(LL* list, int extent, Pyte val)
{
	if (list == NULL || 0 >= extent)//�ж��Ƿ�Ϊ������
	{
		printf("������Ϊ��");

		return 0;
	}

	if (list->length < extent)//�ж��Ƿ񳬳�����������
	{
		printf("���������ȣ�\n");

		return 0;
	}

	Node* tem = list->head;//tem���ͷ�ڵ�
	for (int i = 1; i < extent; i++)
	{
		tem = tem->chain;//extentָ���Ľڵ�
	}
	Pyte a = tem->data;//�ѵ�ǰ�ڵ����ݸ�a
	tem->data = val;//�޸Ľڵ�����

	return a;//���ر��޸Ľڵ��ֵ
}

void list_delete_all(LL** list)//Ҫʵ�θı�ָ�����ô�ַ��ʵ����һ��ָ������Ҫ����ָ�����ָ��ʵ��
{
	for (Node* tem1=(*list)->head, *tem2; tem1 != NULL;)//��������tem��ɾ��
	{
		tem2 = tem1;//tem2�������temһ��ʼ�ĵ�ַ
		tem1 = tem1->chain;//tem1�����¸�Ҫ�ͷŵĽڵ㣬������������ͷ��˵�һ���Ҳ�����һ���ĵ�ַ
		free(tem2);//tem2�ͷ�ǰһ��tem1�ĵ�ַ
	}

	free(*list);//�ͷ�����������
	*list = NULL;//��Ϊ���������ͷ���ʵ�δ�ʱ��Ұָ�룬Ϊ��ֹ����Ұָ��ָ��NULL
}