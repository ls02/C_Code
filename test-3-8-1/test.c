#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#pragma pack(2)//对齐数修改成2
struct Node
{
	int data;
	int leng;
};
#pragma pack()//还原默认，默认是8。

int main()
{


	return 0;
}