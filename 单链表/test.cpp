#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

int main()
{
	LL *list = Linked_list();
	Pyte val;

	do
	{
		scanf("%d", &val);
		list_end(list, val);
	} while ('\n' != (getchar()));

	printf("�����е�����Ϊ��");
	display(list);
	//list_end(list, 5);
	//printf("�����е�����Ϊ��");
	//display(list);

	//list_insert(list, 0, 66);
	//printf("�����е�����Ϊ��");
	//display(list);

	//printf("ɾ�����ݣ�%d\n",list_delete(list, 3));
	//printf("�����е�����Ϊ��");
	//display(list);

	//printf("�����ǣ�%d\n", list_get(list, 6));
	//printf("�����е�����Ϊ��");
	//display(list);

	//printf("���޸ĵ������ǣ�%d\n", list_modify(list, 3,10));
	//printf("�����е�����Ϊ��");
	//display(list);

	list_delete_all(&list);
	printf("�����е�����Ϊ:%p\n",list);
	display(list);

	return 0;
}