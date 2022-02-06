#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct string
{
  char* str;
  
  //实际元素个数
  size_t size;
  
  //总容量
  size_t capacity;
}string;

//字符串初始化
extern void InitString(string* pStr);

//手动调整大小
extern void ResizeString(string* pStr, size_t n);

//检查扩容
extern void CheckCapacityString(string* pStr);

//增接口
//尾插一个字符
extern void PushBackChString(string* pStr, const char ch);
//尾插一个字符串
extern void PushBackStrString(string* pStr, const char* str);
//在pos位置插入n个字符
extern void InsertNChString(string* pStr, const char ch, size_t pos, size_t n);
//在pos位置插入一个字符
extern void InsertChString(string* pStr, const char ch, size_t pos);
//在pos位置插入一个字符串
extern void InsertStrString(string* pStr, const char* str, size_t pos);

//删接口
//尾删一个字符
extern void PopBackString(string* pStr);
//删除pos位置的字符
extern void OptDelete(string* pStr, size_t pos);
//删除一个区间
extern void IntervalDelete(string* pStr, char* start, char* end);

//查找接口
//查找单个字符
extern size_t FindChString(string* pStr, const char ch);
//查找字符串
extern size_t FindStrString(string* pStr, const char* str);
#endif