#include "String.h"

typedef struct string string;

void InitString(string* pStr)
{
  assert(pStr);

  //默认开4个大小的空间
  pStr->str = (char*)malloc(sizeof(char) * 4 + 1);
  //检查是否申请成功
  if (!pStr->str)
  {
    printf("内存申请失败！\n");
    
    exit(-1);
  }

  pStr->size = 0;
  pStr->capacity = 4;
  memset(pStr->str, 0, pStr->capacity + 1);
}

void CheckCapacityString(string* pStr)
{
  assert(pStr);

  //检查是否需要扩容
  if (pStr->size >= pStr->capacity)
  {
    pStr->capacity *= 2;
    char* temp = (char*)realloc(pStr->str, sizeof(char) * pStr->capacity + 1);
    if (!temp)
    {
      printf("扩容失败！\n");

      exit(-1);
    }

    pStr->str = temp;
  }
}

void InsertStrString(string* pStr, const char* str, size_t pos)
{
  assert(pStr);

  //检查插入位置是否合法
  if (pos > pStr->size || pos < 0)
  {
    printf("插入失败！此位置无法插入\n");

    return;
  }

  size_t len = strlen(str);
  size_t i = 0;

  //检查是否需要扩容
  pStr->size += len;
  CheckCapacityString(pStr);

  //先把pos位置到size的字符后移str大小的字符
  for (i = 0; i < len; i++)
  {
    pStr->str[pStr->size - len + i] = pStr->str[pos + i];
  }

  pStr->str[pStr->size] = 0;

  //覆盖式插入
  for (i = 0; i < len; i++)
  {
    pStr->str[pos + i] = str[i];
  }
}

void InsertNChString(string* pStr, const char ch, size_t pos, size_t n)
{
  assert(pStr);

  //检查是否在合法位置插入
  if (pos > pStr->size || pos < 0)
  {
    printf("插入失败！此位置无法插入\n");

    return;
  }

  size_t i = 0;
  size_t size = pStr->size;
  //检查是否需要扩容
  pStr->size += n;
  CheckCapacityString(pStr);

  if (size)
  {
      //把pos位置之后的有效在符后移n个字符
      for (i = size; i >= pos; i--)
      {
          pStr->str[i + n] = pStr->str[i];
      }
  }

  pStr->str[pStr->size] = 0;

  //覆盖式插入n个字符
  for  (i = 0; i < n; i++)
  {
    pStr->str[pos + i] = ch;
  }

}

void InsertChString(string* pStr, const char ch, size_t pos)
{
  assert(pStr);

  InsertNChString(pStr, ch, pos, 1);
}

void PushBackChString(string* pStr, const char ch)
{
  assert(pStr);

  InsertChString(pStr, ch, pStr->size);
}

void PushBackStrString(string* pStr, const char* str)
{
  assert(pStr);

  InsertStrString(pStr, str, pStr->size);
}

void IntervalDelete(string* pStr, char* start, char* end)
{
  assert(start && end);

  char* temp = pStr->str;
  size_t len = 0;

  //统计起始位置到end的距离
  while (temp != end)
  {
    temp++;
    len++;
  }

  //拷贝有效字符覆盖区间字符
  while (pStr->str[len])
  {
    *start = pStr->str[len];
    start++;
    len++;
  }
  
  *start = 0;

  pStr->size = strlen(pStr->str);
}

void OptDelete(string* pStr, size_t pos)
{
  assert(pStr);

  //检查插入位置是否合法
  if (pos > pStr->size || pos < 0)
  {
    printf("插入失败！此位置无法插入\n");
    
    return;
  }

  //覆盖删除
  while (pStr->str[pos + 1])
  {
    pStr->str[pos] = pStr->str[pos + 1];
    
    pos++;
  }

  pStr->str[pos] = 0;
  pStr->size--;
}

void PopBackString(string* pStr)
{
  assert(pStr);

  OptDelete(pStr, pStr->size - 1);
}

size_t FindChString(string* pStr, const char ch)
{
  assert(pStr);

  char* temp = pStr->str;
  
  //遍历查找
  while (*temp)
  {
    if (*temp == ch)
    {
      return temp - pStr->str;
    }

    temp++; 
  }

  return -1;
}

size_t FindStrString(string* pStr, const char* str)
{
  assert(pStr);

  return FindChString(pStr, *str);
}

void ResizeString(string* pStr, size_t n)
{
    assert(pStr);

    if (n > 0)
    {
        char* temp = (char*)realloc(pStr->str, sizeof(char) * n);
        if (!temp)
        {
            printf("扩容失败！\n");

            exit(-1);
        }

        pStr->str = temp;
        pStr->capacity = n;
    }
}