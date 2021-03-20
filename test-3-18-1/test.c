#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define N(x) (((x) & 0x55555555 ) << 1 | ((x) & 0xaaaaaaaa) >> 1)
#define offsetof(Struct, MemberName) (size_t)&(((Struct *)0)->MemberName)

typedef struct S
{
	int a;
	short b;
	char c;
}S;

int main()
{
	S s1 = { 1, 2, 'a' };
	S* s = &s1;
	printf("%d\n", offsetof(S, b));
	printf("%d", (size_t)&s->c);

	return 0;
}