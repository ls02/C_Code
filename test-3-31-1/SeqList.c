#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps)//��ʼ��
{
	assert(ps);

	SLDateType* temp = (SLDateType*)malloc(sizeof(SLDateType) * 4);//��ʼ��Ĭ��ֵΪ4�����ݴ�С�Ŀռ�
	if (!temp)//�ж��Ƿ��ʼ���ɹ�
	{
		printf("initialization failed!\n");
		exit(-1);
	}

	ps->s = temp;//�ѳ�ʼ���ɹ��Ŀռ��˳���
	ps->size = 0;//��Ч����Ϊ0
	ps->capacity = 4;//Ĭ��ֵ����Ϊ4
}

//����
void dilatation(SeqList* ps)
{
	assert(ps);

	if (ps->size == ps->capacity)//�ж���Ч���ݵĿռ��Ƿ����ˣ������������
	{
		int newcapacity = ps->capacity *= 2;//����һ�������洢������capacity��ֵ

		SLDateType* News = (SLDateType*)realloc(ps->s, sizeof(SLDateType) * newcapacity);//����capacity�Ķ�����С
		if (!News)//����Ƿ�����ʧ��
		{
			printf("realloc fail\n");

			exit(-1);
		}

		ps->s = News;//�����ݳɹ����µ�ַ��˳���
		ps->capacity = newcapacity;//����ͬʱ�������
	}
}

void SeqListDestory(SeqList* ps)//����
{
	assert(ps);

	free(ps->s);//����˳���
	ps->s = NULL;//���ÿ�
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)//��ӡ
{
	assert(ps);
	unsigned int i = 0;

	for (i = 0; i < ps->size; i++)//��������˳���
	{
		printf("%d ", ps->s[i]);//��ӡi������
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)//ĩβ���
{
	assert(ps);

	SeqListInsert(ps, ps->size, x);//��������λ�ò���ӿ������β��
}

void SeqListPushFront(SeqList* ps, SLDateType x)//ͷ�����
{
	assert(ps);

	SeqListInsert(ps, 0, x);//��������λ�ò���ӿ������ͷ��
}

void SeqListPopFront(SeqList* ps)//ͷ��ɾ��
{
	assert(ps);

	SeqListErase(ps, 0);//��������λ��ɾ���ӿ������ͷɾ
}

void SeqListPopBack(SeqList* ps)//ĩβɾ��
{
	assert(ps);

	SeqListErase(ps, ps->size - 1);//��������λ��ɾ���ӿ������βɾ
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	size_t i = 0;

	for (i = 0; i < ps->size; i++)//����һ���ж��Ƿ��и�ֵ
	{
		if (ps->s[i] == x)//�ж�i�Ƿ���x
		{
			return ps->s[i];//��x�򷵻�x��ֵ
		}
	}

	return 0;//���δ�ҵ����ؿ�ָ��
}

//˳����޸�
void SeqListAlter(SeqList* ps, size_t x, SLDateType data)
{
	assert(ps);
	size_t i = 0;

	if (x >= 0 && x < ps->size)//�ж��Ƿ��ںϷ���Χ���޸�
	{
		ps->s[x] = data;//�޸ĵ�x��λ�õ�����
	}
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	unsigned int i = 0;

	dilatation(ps);//�ж��Ƿ���Ҫ����

	if (pos > 0 && pos <= ps->size)//�ж��Ƿ�������λ�ò���
	{
		for (i = ps->size; i > pos; i--)
		{
			ps->s[i] = ps->s[i - 1];//��ǰ����Ų����Ϊsize���λ���Ѿ���Խ�����Լ�һŲ��
		}
		ps->s[pos] = x;//�ڿ�λ���ϲ���ֵ
		ps->size++;
	}
	else if (pos == 0 && ps->size == 0)//�ж��Ƿ�����Ч���ݣ����û��ֱ���ٵ�һ��λ���ϲ���
	{
		ps->s[pos] = x;//�ڿ�λ���ϲ���ֵ
		ps->size++;
	}
	else if(pos == 0 && ps->size != 0)//�ж��Ƿ�����ͷ�壬�������Ч���ݾ���ҪŲ���ٲ���
	{
		for (i = ps->size; i > pos; i--)
		{
			ps->s[i] = ps->s[i - 1];//��ǰ����Ų��
		}
		ps->s[pos] = x;//�ڿ�λ���ϲ���ֵ
		ps->size++;
	}
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	size_t i = 0;

	if (pos >= 0 && pos < ps->size)//�ж��Ƿ��ںϷ���Χ��
	{
		for (i = pos; i < ps->size; i++)//�ҵ�Ҫɾ����λ��
		{
			ps->s[i] = ps->s[i + 1];//�Ѻ�������ݸ��ǵ�ɾ���������ϣ������������ɾ��������ɾ��
		}
		ps->size--;//�������ҪŲ��ֱ��--������Ҫ���ɾ��
	}
}