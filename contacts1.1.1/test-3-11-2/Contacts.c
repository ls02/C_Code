#define _CRT_SECURE_NO_WARNINGS 1
#include "Contacts.h"

void Menu()
{
	printf("************************************\n");
	printf("****	1.add		2.del	****\n");
	printf("****	3.revise	4.find	****\n");
	printf("****	5.Alldel	6.show	****\n");
	printf("****	7.sort      0.exit	****\n");
	printf("************************************\n");
	printf("select:");
}

void MenuDel()
{
	printf("******************************************\n");
	printf("***    1.SelectDel    2.TailDel       ****\n");
	printf("***    3.HeadDel      0.Return        ****\n");
	printf("******************************************\n");
	printf("select:");
}

void Menurevise()
{
	printf("******************************************\n");
	printf("****    1.ReviseName    2.ReviseSex    ***\n");
	printf("***     3.ReviseAge     4.ReviseNumber ***\n");
	printf("***     5.ReviseAddress 6.ReviseAll    ***\n");
	printf("***              0.Return              ***\n");
	printf("******************************************\n");
	printf("select:");
}

void Menusort()
{
	printf("*************************************\n");
	printf("***    1.NameSort    2.AgeSort    ***\n");
	printf("***    3.SexSort     0.Return     ***\n");
	printf("*************************************\n");
	printf("select:");
}

void ContactsDel(Contacts* pc)
{
	int input = 0;
	size_t num = 0;

	do
	{
		system("cls");

		MenuDel();
		scanf("%d", &input);

		switch (input)
		{
		case RETURN:
			break;
		case SELECTDEL:
			printf("Enter Delete Location:");
			scanf("%d", &num);
			ContactsInsertErase(pc, num);//指定位置删除联系人
			break;
		case TAIDEL:
			ContactsPopFront(pc);//删除末尾的联系人
			break;
		case HEADDEL:
			ContactsPopHead(pc);//删除开头的联系人
			break;
		default:
			printf("select error\n");
			Sleep(1000);
		}
	} while (input);
}

void ContactsInitialize(Contacts* pc)// 初始化
{
	assert(pc);
	pc->size = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void ContactsPush(Contacts* pc)//添加联系人
{
	assert(pc);
	
	if (pc->size == MAX)
	{
		printf("The address book is full\n");
		Sleep(1000);

		return;
	}
	else
	{
		printf("name:");
		scanf("%s", &pc->data[pc->size].name);
		printf("sxe:");
		scanf("%s", &pc->data[pc->size].sex);
		printf("age:");
		scanf("%hd", &pc->data[pc->size].age);
		printf("number:");
		scanf("%d", &pc->data[pc->size].number);
		printf("address:");
		scanf("%s", &pc->data[pc->size].address);

		pc->size++;
		printf("successfully added\n");
		Sleep(1000);
	}
}

void ContactsInsertErase(Contacts* pc, size_t num)//指定位置删除联系人
{
	assert(pc);

	if (num && num <= pc->size)
	{
		if (num == pc->size)
		{
			pc->size--;
			printf("successfully delete\n");
			Sleep(1000);
		}
		else
		{
			pc->data[num - 1] = pc->data[num];
			pc->size--;

			printf("successfully delete\n");
			Sleep(1000);
		}
	}
	else
	{
		printf("This location cannot be deleted\n");
		Sleep(1000);
	}
}

void ContactsPopFront(Contacts* pc)//删除末尾的联系人
{
	assert(pc);

	pc->size--;
	printf("successfully delete\n");
	Sleep(1000);
}

void ContactsPopHead(Contacts* pc)//删除开头的联系人
{
	assert(pc);

	ContactsInsertErase(pc, 1);
}

void ContactsAllBrase(Contacts* pc)//删除所有联系人
{
	assert(pc);

	pc->size = 0;
}

Contacts* ContactsFind(const Contacts* pc, char* name)//查找
{
	assert(pc);

	Contacts* left = (Contacts*)&pc->data[0];
	Contacts* right = (Contacts*)&pc->data[pc->size - 1];

	while (left <= right)
	{
		if (!strcmp(name, left->data->name))
		{
			return left;
		}

		if (!strcmp(name, right->data->name))
		{
			return right;
		}

		left++;
		right--;
	}

	printf("No information on that person.\n");
	Sleep(1000);

	return 0;
}

void Contactsrevise(Contacts* pc)//修改
{
	assert(pc);
	int input = 0;
	char name[MAX] = { 0 };
	Contacts* temp = NULL;

	do
	{
		printf("inputName:");
		scanf("%s", &name);

		ContactsFind(pc, name);//查找

		if (!temp)
		{
			return;
		}

		system("cls");
		Menurevise();
		scanf("%d", &input);

		switch (input)
		{
		case REVISENAME:
			temp = ContactsFind(pc, name);
			printf("name:");
			scanf("%s", &temp->data->name);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case REVISESEX:
			temp = ContactsFind(pc, name);
			printf("sex:");
			scanf("%s", &temp->data->sex);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case REVISEAGE:
			temp = ContactsFind(pc, name);
			printf("age:");
			scanf("%hd", &temp->data->age);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case REVISENUMBER:
			temp = ContactsFind(pc, name);
			printf("number:");
			scanf("%d", &temp->data->number);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case REVISEADDRESS:
			temp = ContactsFind(pc, name);
			printf("address:");
			scanf("%s", &temp->data->address);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case REVISEALL:
			temp = ContactsFind(pc, name);
			printf("name:");
			scanf("%s", &temp->data->name);
			printf("sex:");
			scanf("%s", &temp->data->sex);
			printf("age:");
			scanf("%hd", &temp->data->age);
			printf("number:");
			scanf("%d", &temp->data->number);
			printf("address:");
			scanf("%s", &temp->data->address);
			printf("Modified successfully\n");
			Sleep(1000);
			break;
		case RETURN:
			break;
		default:
			printf("select error\n");
			Sleep(1000);
			break;
		}
	} while (input);

}

void ContactsPrint(const Contacts* ps)//打印
{
	assert(ps);

	unsigned int i = 0;

	printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t\n", "ID", "name", "sex", "age", "number", "addess");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-15d\t%-15s\t%-15s\t%-15d\t%-15d\t%-15s\n",
			i + 1, ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].number,
			ps->data[i].address);
	}

	int input = 1;

	while (input)
	{
		printf("Enter zero to exit:");
		scanf("%d", &input);
	}
}

int compareName(const void* e1, const void* e2)
{
	return strcmp(((Contacts*)e1)->data->sex, ((Contacts*)e2)->data->sex);
}

int compareAge(const void* e1, const void* e2)
{
	return ((Contacts*)e1)->data->age - ((Contacts*)e2)->data->age;
}

int compareSex(const void* e1, const void* e2)
{
	return strcmp(((Contacts*)e1)->data->sex, ((Contacts*)e2)->data->sex);
}

void my_swap(char* e1, char* e2, size_t width)
{
	size_t i = 0;

	for (i = 0; i < width; i++)
	{
		char temp = *e1;
		*e1 = *e2;
		*e2 = temp;

		e1++;
		e2++;
	}
}

void* ContactsBubblesort(void* base, size_t num, size_t width, int (compare)(const void* e1, const void* e2))//排序
{
	assert(base);

	size_t i = 0;
	size_t j = 0;

	for (i = 0; i < num - 1; i++)
	{
		for (j = i; j < num - 1 - i; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				my_swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}

	return base;
}

void ContactsSort(Contacts* pc)
{
	int input = 0;

	do
	{
		system("cls");

		Menusort();
		scanf("%d", &input);

		switch (input)
		{
		case NAMESORT:
			ContactsBubblesort(pc->data, pc->size, sizeof(pc->data[0]), compareName);
			printf("sequence\n");
				Sleep(1000);
			break;
		case AGESORT:
			ContactsBubblesort(pc->data, pc->size, sizeof(pc->data[0]), compareAge);
			printf("sequence\n");
			Sleep(1000);
			break;
		case SEXSORT:
			ContactsBubblesort(pc->data, pc->size, sizeof(pc->data[0]), compareSex);
	
			printf("sequence\n");
			Sleep(1000);
			break;
		case RETURN:
			break;
		default:
			printf("select error\n");
			Sleep(1000);
			break;
		}
	} while (input);
}