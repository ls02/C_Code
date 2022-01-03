#pragma once
#include <stdio.h>
#include <stdlib.h>
//1.定义顺序表
//结构体 vector:表的类型
typedef struct 
{
	//1.指针 存储申请的内存的首地址
	int* pV;
	//2.总容量 记录当前的表的最大元素个数
	size_t capacity;
	//3.长度 当前拥有的元素长度
	int size;
}vector;
//初始化
//创建顺序表
//参数: 长度(用作开辟内存的大小)
//返回值: 表
vector InitVector(int n);

//扩容顺序表
//扩容
//参数: 表指针 容量
//返回值: 表指针
vector* CheckCapacityVector(vector* pVector);

//插入
//尾部插入元素
//参数: 表指针 数值
//返回值: 表指针
vector* PushBackVector(vector* pVector, int num);
//任意位置插入元素
//参数: 表指针 数值 位置
//返回值: 表指针
vector* InsertVector(vector* pVector, int num, int pos);

//释放表
//参数 表
//返回值: 无
void DestoryVector(vector temp);

//查找元素
//参数: 表 数值
//返回值: 整形
int FindWithVector(vector temp, int num);

//删除
//删除坐标的元素
//参数: 表指针 坐标
vector* DelPosVector(vector* pVector, int pos);
//删除尾部的元素
//参数: 表指针
//返回值: 表指针
vector* PopBackVector(vector* pVector);
