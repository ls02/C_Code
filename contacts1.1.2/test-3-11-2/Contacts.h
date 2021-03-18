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

typedef struct information//ͨѶ¼��Ϣ
{
	char name[NAME];
	char sex[6];
	short age;
	int number;
	char address[ADDRESS];
}information;

typedef struct Contacts//ͨѶ¼
{
	information* data;
	size_t size;//��ǰ����
	size_t capacity;//�������
}Contacts;

void ContactsPush(Contacts* pc);//�����ϵ��

void ContactsInitialize(Contacts* pc);// ��ʼ��

void ContactsInsertErase(Contacts* pc, size_t num);//ָ��λ��ɾ����ϵ��

void ContactsPopFront(Contacts* pc);//ɾ��ĩβ����ϵ��

void ContactsPopHead(Contacts* pc);//ɾ����ͷ����ϵ��

Contacts* ContactsFind(const Contacts* pc, char* name);//����

void Contactsrevise(Contacts* pc);//�޸�

void ContactsAllBrase(Contacts* pc);//ɾ��������ϵ��

void* ContactsBubblesort(void* base, size_t num, size_t width, int (compare)(const void* e1, const void* e2));//����

void ContactsPrint(const Contacts* pc);//��ӡ

int  CheckCapacity(Contacts* pc);//����

void DestroyContact(Contacts* pc);//����ͨѶ¼

void SaveFile(Contacts* pc);//����ͨѶ¼