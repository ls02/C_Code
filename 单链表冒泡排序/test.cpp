#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

int main()
{
	LL* list = list_fount();
	Pyte val = 0;

	do
	{
		scanf("%d",&val);
		list_insert_end(list, val);
	} while ('\n' != (getchar()));
	list_export(list);
	printf("%p\n", list);
	list_delete_all(&list);
	printf("%p", list);

	//list_insert(list, 5, 22);
	//list_export(list);

	//list_bubbing_sort(list);
	//list_export(list);

	//list_amend(list, 3, 22);
	//list_export(list);

	//printf("%d",list_return_data(list,3));
	//list_export(list);



	return 0;
}
