#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void mao_pao(int* x, int y)//ð������
{
	int i, j, k;//k����������

	for (i = 0; i < y - 1; i++)//��Ϊ���һ�������ñȽ����Լ�һ
	{
		for (j = 0; j < y - 1 - i; j++)//����i�Ǽ���û��Ҫ�Ľ�������Ϊĩβ�������ֵ����Сֵ������õģ�ֻ��ǰ��ļ���
		{
			if (x[j] > x[j + 1])//�±�j��ֵ���������ǰ��һ���ͽ��н��������մ�Ļᵽ��������ҪС�����������ж���������
			{
				k = x[j];//�ѵ�j��ֵ��k
				x[j] = x[j + 1];//��jǰ��һ����ֵ��j
				x[j + 1] = k;//��k ��ֵ��j+1ʵ�ֽ���
			}
		}
	}
}

void xuan_ze(int* x, int y)//ѡ������
{
	int i, j, k, min;//min�洢���µ��±�
	for (i = 0; i < y; i++)
	{
		min = i;//minȡ��һ���±�
		for (j = i; j < y; j++)
		{
			if (x[min] > x[j])//��min���±���ڵ�j�������ֵ��ִ�У�����ɸѡ��Щ������ֵ��С���±�
			{
				min = j;//��С��min��ֵ���±��min
			}
		}
		k = x[i];//���±�i��ֵ��k
		x[i] = x[min];//����С���±��i��Ϊi�Ǵ��㿪ʼ��Ҳ���ǵ�һ������С��������
		x[min] = k;//�ڰ�i��ֵ��min�Դ˵��ｻ������ʹ�����ʵ��
	}
}

void cha_ru(int* x, int y)//��������
{
	int i, j, k;
	for (i = 1; i < y; i++)
	{
		k = x[i];//k��¼Ҫ��������ֵ
		j = i - 1;//������㿪ʼ������i-1����0�±��1�±��ֵ���бȽ�
		while (j >= 0 && x[j] > k)//�жϵ�0���±��ֵ�Ƿ���ڵ�һ���±��ֵ
		{
			x[j + 1] = x[j];//�Ѵ��ֵ�ź���
			j--;//�Լ�һ�˳�ѭ��
		}
		x[j + 1] = k;//�����j��-1������j+1�����±�0���ѽ�С��ֵ��ǰ��
	}
}


void kuai_su(int* x, int l,int h)//��������
{
	int i, j, k;
	if (l < h)//l������±꣬h ������±�
	{
		k = x[l];//k�������Ĭ��Ϊ��ǰ�������е�λ����е�����
		i = l;//ѭ������
		j = h;//ѭ������
		while (i < j)
		{
			while (i < j && x[j] >= k)j--;//���j����k��ֵ˵�����������Լ�һ
			if (i < j)x[i++] = x[j];//j������k��ֵ˵����Ҫ����j��ֵ��ii������һ
			while (i < j && x[i] <= k)i++;//���i��ֵС��k��˵������Ҫ��������һ
			if (i < j)x[j--] = x[i];//i��ֵ����k��Ҫ���򣬰�i��ֵ��j����j�Լ�һ
		}
		x[i] = k;//��i��j��ȾͰ�k��ֵ��i
		kuai_su(x, l, i - 1);//�ݹ�������ߵ��������Ϊ��С���������������ҵ���ֱ��ȫ�������
		kuai_su(x, j + 1, h);//�ݹ������ұߵ������ұ�Ϊ�ϴ���������������ҵ���ֱ��ȫ�������
	}
}

arr* chushihua()//��ʼ��˳���
{
	arr* tem;
	tem = (arr*)malloc(sizeof(arr));
	assert(tem != NULL);
	tem->defi = (Pyte*)malloc(sizeof(Pyte));
	tem->len = 0;
	return tem;
}

void xiaohui(arr* a)//˳�������
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a->defi);
	free(a);
}

void kongbiao(arr* a)//����Ϊ�ձ�
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a->defi);
	a->defi = (Pyte*)calloc(1, sizeof(Pyte));
	a->len = 0;
}



void mao_pao1(xs* x, int y)//ð������
{
	int i, j;//k����������
	xs k;

	for (i = 0; i < y - 1; i++)//��Ϊ���һ�������ñȽ����Լ�һ
	{
		for (j = 0; j < y - 1 - i; j++)//����i�Ǽ���û��Ҫ�Ľ�������Ϊĩβ�������ֵ����Сֵ������õģ�ֻ��ǰ��ļ���
		{
			if (x[j].ID > x[j + 1].ID)//�±�j��ֵ���������ǰ��һ���ͽ��н��������մ�Ļᵽ��������ҪС�����������ж���������
			{
				k = x[j];//�ѵ�j��ֵ��k
				x[j] = x[j + 1];//��jǰ��һ����ֵ��j
				x[j + 1] = k;//��k ��ֵ��j+1ʵ�ֽ���
			}
		}
	}
}

void xuan_ze1(xs* x, int y)
{
	int i, j, min;//min�洢���µ��±�
	xs k;
	for (i = 0; i < y; i++)
	{
		min = i;//minȡ��һ���±�
		for (j = i; j < y; j++)
		{
			if (x[min].ID > x[j].ID)//��min���±���ڵ�j�������ֵ��ִ�У�����ɸѡ��Щ������ֵ��С���±�
			{
				min = j;//��С��min��ֵ���±��min
			}
		}
		k = x[i];//���±�i��ֵ��k
		x[i] = x[min];//����С���±��i��Ϊi�Ǵ��㿪ʼ��Ҳ���ǵ�һ������С��������
		x[min]= k;//�ڰ�i��ֵ��min�Դ˵��ｻ������ʹ�����ʵ��
	}
}

void cha_ru1(xs* x, int y)//��������
{
	int i, j;
	xs k;
	for (i = 1; i < y; i++)
	{
		k = x[i];//k��¼Ҫ��������ֵ
		j = i - 1;//������㿪ʼ������i-1����0�±��1�±��ֵ���бȽ�
		while (j >= 0 && x[j].ID > k.ID)//�жϵ�0���±��ֵ�Ƿ���ڵ�һ���±��ֵ
		{
			x[j + 1] = x[j];//�Ѵ��ֵ�ź���
			j--;//�Լ�һ�˳�ѭ��
		}
		x[j + 1] = k;//�����j��-1������j+1�����±�0���ѽ�С��ֵ��ǰ��
	}
}



void shu_chu(arr* a)
{
	assert(a != NULL);
	assert(a->defi != NULL);
	int i = 0;
	for (i = 0; i < a->len; i++)
	{
		printf("%d\t", a->defi[i]);
	}
	putchar('\n');
}

void mao_pao22(Pyte* x, int y)//ð������
{
	int i, j;//k����������
	int k;

	for (i = 0; i < y - 1; i++)//��Ϊ���һ�������ñȽ����Լ�һ
	{
		for (j = 0; j < y - 1 - i; j++)//����i�Ǽ���û��Ҫ�Ľ�������Ϊĩβ�������ֵ����Сֵ������õģ�ֻ��ǰ��ļ���
		{
			if (x[j] > x[j + 1])//�±�j��ֵ���������ǰ��һ���ͽ��н��������մ�Ļᵽ��������ҪС�����������ж���������
			{
				k = x[j];//�ѵ�j��ֵ��k
				x[j] = x[j + 1];//��jǰ��һ����ֵ��j
				x[j + 1] = k;//��k ��ֵ��j+1ʵ�ֽ���
			}
		}
	}
}

void chai_ru(arr* a, Pyte elem)//����˳���
{
	assert(a != NULL);
	assert(a->defi != NULL);
	a->len++;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	a->defi[a->len - 1] = elem;
}
