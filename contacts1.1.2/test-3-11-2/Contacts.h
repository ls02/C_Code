#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <errno.h>

#define NAME 20
#define ADDRESS 50

enum  option
{
	EXIT,
	ADD,
	DEL,
	REVISE,
	FIND,
	ALLDEL,
	SHOW,
	SORT,
	SAVE
};

enum optionDel
{
	RETURN,
	SELECTDEL,
	TAIDEL,
	HEADDEL
};

enum  optionRevise
{
	REVISENAME = 1,
	REVISESEX,
	REVISEAGE,
	REVISENUMBER,
	REVISEADDRESS,
	REVISEALL
};

enum optionSort
{
	NAMESORT = 1,
	AGESORT,
	SEXSORT
};

typedef struct information//通讯录信息
{
	char name[NAME];
	char sex[6];
	short age;
	int number;
	char address[ADDRESS];
}information;

typedef struct Contacts//通讯录
{
	information* data;
	size_t size;//当前容量
	size_t capacity;//最大容量
}Contacts;

void ContactsPush(Contacts* pc);//添加联系人

void ContactsInitialize(Contacts* pc);// 初始化

void ContactsInsertErase(Contacts* pc, size_t num);//指定位置删除联系人

void ContactsPopFront(Contacts* pc);//删除末尾的联系人

void ContactsPopHead(Contacts* pc);//删除开头的联系人

Contacts* ContactsFind(const Contacts* pc, char* name);//查找

void Contactsrevise(Contacts* pc);//修改

void ContactsAllBrase(Contacts* pc);//删除所有联系人

void* ContactsBubblesort(void* base, size_t num, size_t width, int (compare)(const void* e1, const void* e2));//排序

void ContactsPrint(const Contacts* pc);//打印

int  CheckCapacity(Contacts* pc);//扩容

void DestroyContact(Contacts* pc);//销毁通讯录

void SaveFile(Contacts* pc);//保存通讯录