#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��
void SeqListInit(SL* ps)
{
	assert(ps);
	ps->data = (SlType*)malloc(sizeof(SlType) * 4);

	if (ps->data == NULL)
	{
		printf("��ʼ��ʧ��!\n");
		return;
	}

	ps->size = 0;
	ps->capacity = 4;
}

//βɾ
void SeqListBackDelet(SL* ps)
{
	assert(ps);

	ps->size--;
}

//β��
void SeqListBackInsert(SL* ps, SlType x)
{
	assert(ps);

	SeqListCheckCapacity(ps);

	ps->size++;
	ps->data[ps->size - 1] = x;
}

//ͷ��
void SeqListHendInsert(SL* ps, SlType x)
{
	assert(ps);
	int i = 0;

	SeqListCheckCapacity(ps);

	for (i = ps->size - 1; i >= 0; i--)
	{
		ps->data[i + 1] = ps->data[i];
	}
	
	ps->data[0] = x;
	ps->size++;
}

//ͷɾ
void SeqListHendDlest(SL* ps)
{
	assert(ps && ps->data);

	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}

	ps->size--;
}

//ѡ������滻
SlType SeqListOptInsertReplce(SL* ps, SlType x, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];
		ps->data[seat - 1] = x;

		return temp;
	}
	else
	{
		printf("�˴��޷�����\n");

		return 0;
	}
}

//��ӡ����
void SeqListPrint(SL* ps)
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}

	printf("\n");
}

//�������
void SeqListCheckCapacity(SL* ps)
{
	assert(ps);

	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		SlType* x = (SlType*)realloc(ps->data, sizeof(SlType) * ps->capacity);

		if (NULL == x)
		{
			printf("�����ڴ�ʧ��!\n");

			return;
		}
		ps->data = x;
	}
}

//����
void SeqListDestory(SL* ps)
{
	assert(ps);

	free(ps->data);
	free(ps);
}

//����
SlType SeqListFind(SL* ps, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		return ps->data[seat - 1];
	}
	else
	{
		printf("������!\n");

		return 0;
	}
}

//ѡ��ɾ��
SlType SeqListOptDelete(SL* ps, int seat)
{
	assert(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];
		int i = 0;

		for (i = seat; i < ps->size; i++)
		{
			ps->data[i - 1] = ps->data[i];
		}
		ps->size--;

		return temp;
	}
	else
	{
		printf("�޿�ɾ������!\n");
		
		return 0;
	}

}


//ѡ�����
SlType SeqListOptInsertt(SL* ps, SlType x, int seat)
{
	assert(ps);
	int i = 0;
	SeqListCheckCapacity(ps);

	if (0 < seat && seat <= ps->size)
	{
		int temp = ps->data[seat - 1];

		for (i = ps->size; i >= seat; i--)
		{
			ps->data[i] = ps->data[i - 1];
		}

		ps->data[seat - 1] = x;
		ps->size++;

		return temp;
	}
	else
	{
		printf("�޷�����!\n");

		return 0;
	}
}