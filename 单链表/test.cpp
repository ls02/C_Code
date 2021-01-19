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

	printf("链表中的数据为：");
	display(list);
	//list_end(list, 5);
	//printf("链表中的数据为：");
	//display(list);

	//list_insert(list, 0, 66);
	//printf("链表中的数据为：");
	//display(list);

	//printf("删除数据：%d\n",list_delete(list, 3));
	//printf("链表中的数据为：");
	//display(list);

	//printf("数据是：%d\n", list_get(list, 6));
	//printf("链表中的数据为：");
	//display(list);

	//printf("被修改的数据是：%d\n", list_modify(list, 3,10));
	//printf("链表中的数据为：");
	//display(list);

	list_delete_all(&list);
	printf("链表中的数据为:%p\n",list);
	display(list);

	return 0;
}