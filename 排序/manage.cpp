#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

void mao_pao(int* x, int y)//冒泡排序法
{
	int i, j, k;//k是用来交换

	for (i = 0; i < y - 1; i++)//因为最后一个数不用比较所以减一
	{
		for (j = 0; j < y - 1 - i; j++)//还减i是减少没必要的交换，因为末尾的是最大值或最小值是排序好的，只需前面的即可
		{
			if (x[j] > x[j + 1])//下标j的值如果大于它前面一个就进行交换，最终大的会到最后如果想要小的在最后更改判断条件即可
			{
				k = x[j];//把第j个值给k
				x[j] = x[j + 1];//把j前面一个的值给j
				x[j + 1] = k;//把k 的值给j+1实现交换
			}
		}
	}
}

void xuan_ze(int* x, int y)//选择排序
{
	int i, j, k, min;//min存储最下的下标
	for (i = 0; i < y; i++)
	{
		min = i;//min取第一个下标
		for (j = i; j < y; j++)
		{
			if (x[min] > x[j])//第min个下标大于第j个坐标的值就执行，依次筛选这些数组中值最小的下标
			{
				min = j;//把小于min的值的下标给min
			}
		}
		k = x[i];//把下标i的值给k
		x[i] = x[min];//把最小的下标给i因为i是从零开始的也就是第一个，从小到大排序
		x[min] = k;//在把i的值给min以此到达交互而促使排序的实现
	}
}

void cha_ru(int* x, int y)//插入排序法
{
	int i, j, k;
	for (i = 1; i < y; i++)
	{
		k = x[i];//k记录要被交换的值
		j = i - 1;//数组从零开始的所以i-1，用0下标和1下标的值进行比较
		while (j >= 0 && x[j] > k)//判断第0个下标的值是否大于第一个下标的值
		{
			x[j + 1] = x[j];//把大的值放后面
			j--;//自减一退出循环
		}
		x[j + 1] = k;//这里的j是-1，所以j+1才是下标0，把较小的值放前面
	}
}


void kuai_su(int* x, int l,int h)//快速排序
{
	int i, j, k;
	if (l < h)//l是最低下标，h 是最高下标
	{
		k = x[l];//k中枢变量默认为当前待排序列低位标记中的数据
		i = l;//循环变量
		j = h;//循环变量
		while (i < j)
		{
			while (i < j && x[j] >= k)j--;//如果j大于k的值说明不用排序自减一
			if (i < j)x[i++] = x[j];//j不大于k的值说明需要排序，j的值给ii再自增一
			while (i < j && x[i] <= k)i++;//如果i的值小于k，说明不需要排序，自增一
			if (i < j)x[j--] = x[i];//i的值大于k需要排序，把i的值和j交换j自减一
		}
		x[i] = k;//当i和j相等就把k的值给i
		kuai_su(x, l, i - 1);//递归排序左边的数，左边为较小的数二次排序，自我调用直到全部排序好
		kuai_su(x, j + 1, h);//递归排序右边的数，右边为较大的数二次排序，自我调用直到全都排序好
	}
}

arr* chushihua()//初始化顺序表
{
	arr* tem;
	tem = (arr*)malloc(sizeof(arr));
	assert(tem != NULL);
	tem->defi = (Pyte*)malloc(sizeof(Pyte));
	tem->len = 0;
	return tem;
}

void xiaohui(arr* a)//顺序表销毁
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a->defi);
	free(a);
}

void kongbiao(arr* a)//重置为空表
{
	assert(a != NULL);
	assert(a->defi != NULL);
	free(a->defi);
	a->defi = (Pyte*)calloc(1, sizeof(Pyte));
	a->len = 0;
}



void mao_pao1(xs* x, int y)//冒泡排序法
{
	int i, j;//k是用来交换
	xs k;

	for (i = 0; i < y - 1; i++)//因为最后一个数不用比较所以减一
	{
		for (j = 0; j < y - 1 - i; j++)//还减i是减少没必要的交换，因为末尾的是最大值或最小值是排序好的，只需前面的即可
		{
			if (x[j].ID > x[j + 1].ID)//下标j的值如果大于它前面一个就进行交换，最终大的会到最后如果想要小的在最后更改判断条件即可
			{
				k = x[j];//把第j个值给k
				x[j] = x[j + 1];//把j前面一个的值给j
				x[j + 1] = k;//把k 的值给j+1实现交换
			}
		}
	}
}

void xuan_ze1(xs* x, int y)
{
	int i, j, min;//min存储最下的下标
	xs k;
	for (i = 0; i < y; i++)
	{
		min = i;//min取第一个下标
		for (j = i; j < y; j++)
		{
			if (x[min].ID > x[j].ID)//第min个下标大于第j个坐标的值就执行，依次筛选这些数组中值最小的下标
			{
				min = j;//把小于min的值的下标给min
			}
		}
		k = x[i];//把下标i的值给k
		x[i] = x[min];//把最小的下标给i因为i是从零开始的也就是第一个，从小到大排序
		x[min]= k;//在把i的值给min以此到达交互而促使排序的实现
	}
}

void cha_ru1(xs* x, int y)//插入排序法
{
	int i, j;
	xs k;
	for (i = 1; i < y; i++)
	{
		k = x[i];//k记录要被交换的值
		j = i - 1;//数组从零开始的所以i-1，用0下标和1下标的值进行比较
		while (j >= 0 && x[j].ID > k.ID)//判断第0个下标的值是否大于第一个下标的值
		{
			x[j + 1] = x[j];//把大的值放后面
			j--;//自减一退出循环
		}
		x[j + 1] = k;//这里的j是-1，所以j+1才是下标0，把较小的值放前面
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

void mao_pao22(Pyte* x, int y)//冒泡排序法
{
	int i, j;//k是用来交换
	int k;

	for (i = 0; i < y - 1; i++)//因为最后一个数不用比较所以减一
	{
		for (j = 0; j < y - 1 - i; j++)//还减i是减少没必要的交换，因为末尾的是最大值或最小值是排序好的，只需前面的即可
		{
			if (x[j] > x[j + 1])//下标j的值如果大于它前面一个就进行交换，最终大的会到最后如果想要小的在最后更改判断条件即可
			{
				k = x[j];//把第j个值给k
				x[j] = x[j + 1];//把j前面一个的值给j
				x[j + 1] = k;//把k 的值给j+1实现交换
			}
		}
	}
}

void chai_ru(arr* a, Pyte elem)//插入顺序表
{
	assert(a != NULL);
	assert(a->defi != NULL);
	a->len++;
	a->defi = (Pyte*)realloc(a->defi, sizeof(Pyte) * a->len);
	a->defi[a->len - 1] = elem;
}
