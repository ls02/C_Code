#define _CRT_SECURE_NO_WARNINGS 1
#include "Contacts.h"

void Menu()
{
	printf("************************************\n");
	printf("****    1.add       2.del       ****\n");
	printf("****    3.revise    4.find      ****\n");
	printf("****    5.Alldel    6.show      ****\n");
	printf("****    7.sort      8..save     ****\n");
	printf("****         0.Exit             ****\n");
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

int  CheckCapacity(Contacts* pc)//扩容
{
	assert(pc);

	if (pc->size == pc->capacity)
	{
		information* temp = (information*)realloc(pc->data, (pc->capacity * 2) * sizeof(information));

		if (!temp)
		{
			printf("Space expansion failed\n");
			Sleep(1000);

			return 1;
		}

		pc->capacity *= 2;
	}

	return 0;
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

void LoadContacts(Contacts* pc)
{
	//打开文件
	FILE* fpIn = fopen("contacts.dat", "rb");
	if (!fpIn)
	{
		printf(" LoadContacts:%s\n", strerror(errno));
		Sleep(1000);
		return;
	}

	information temp = { 0 };
	//读文件，放进通讯录
	while (fread(&temp, sizeof(information), 1, fpIn))
	{
		if (CheckCapacity(pc))
		{
			printf("fail to load\n");

			return;
		}
		pc->data[pc->size] = temp;
		pc->size++;
	}

	//关闭文件
	fclose(fpIn);
	fpIn = NULL;

	printf("Load the success\n");
	Sleep(1000);
}

void ContactsInitialize(Contacts* pc)// 初始化
{
	assert(pc);

	information* temp = (information*)malloc(sizeof(information) * 4);
	if (!temp)
	{
		printf("initialization failed\n");
		Sleep(1000);

		return;
	}
	pc->data = temp;
	pc->size = 0;
	pc->capacity = 4;

	//加载文件
	LoadContacts(pc);
}


void ContactsPush(Contacts* pc)//添加联系人
{
	assert(pc);
	
	CheckCapacity(pc);//扩容

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
	char name[NAME] = { 0 };
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

void ContactsPrint(const Contacts* pc)//打印
{
	assert(pc);

	unsigned int i = 0;

	printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t%-15s\t\n", "ID", "name", "sex", "age", "number", "addess");
	for (i = 0; i < pc->size; i++)
	{
		printf("%-15d\t%-15s\t%-15s\t%-15d\t%-15d\t%-15s\n",
			i + 1, pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].number,
			pc->data[i].address);
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

void DestroyContact(Contacts* pc)//销毁通讯录
{
	assert(pc);
	
	pc->size = 0;
	pc->capacity = 0;
	free(pc->data);
	pc->data = NULL;

	pc = NULL;
}

void SaveFile(Contacts* pc)//保存通讯录
{
	assert(pc);
	unsigned int i = 0;
	//打开文件
	FILE* fpOut = fopen("contacts.dat", "wb");
	if (!fpOut)
	{
		printf("fail in keeping:%s", strerror(errno));

		return;
	}
	//写入文件
	for (i = 0; i < pc->size; i++)
	{
		fwrite(pc->data + i, sizeof(information), 1, fpOut);
	}
	//关闭文件
	fclose(fpOut);
	fpOut = NULL;

	printf("save successfully!\n");
	Sleep(1000);
}