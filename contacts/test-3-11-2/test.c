#define _CRT_SECURE_NO_WARNINGS 1
#include "Contacts.h"
#include <stdio.h>

extern void Menu();

int main()
{
	Contacts ps;
	char name[NAME] = { 0 };
	int input = 0;

	ContactsInitialize(&ps);// ³õÊ¼»¯

	do
	{
		system("cls");

		Menu();
		scanf("%d", &input);

		switch (input)
		{
		case EXIT:
			printf("exit\n");
			break;
		case ADD:
			ContactsPush(&ps);
			break;
		case DEL:
			ContactsDel(&ps);
			break;
		case REVISE:
			Contactsrevise(&ps);
			break;
		case FIND:
			printf("enter the name:");
			scanf("%s", name);
			getchar();
			Contacts* temp = ContactsFind(&ps, name);

			if (temp)
			{
				printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "name", "sex", "age", "number", "addess");
				printf("%-15s\t%-15s\t%-15hd\t%-15d\t%-15s\n",
					temp->data->name,
					temp->data->sex,
					temp->data->age,
					temp->data->number,
					temp->data->address);
				printf("Press Enter to exit\n");
				getchar();
			}

			break;
		case ALLDEL:
			break;
		case SHOW:
			system("cls");
			ContactsPrint(&ps);
			break;
		case SORT:
			ContactsSort(&ps);
			break;
		default:
			printf("select error\n");
			Sleep(1000);
			break;
		}

	} while (input);

	return 0;
}