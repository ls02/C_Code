#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"

//typedef struct Vector vector;

void TestVector1()
{
	Vector v1;
	v1 = InitVector(4);

	PushBackVector(&v1, 1);
	PushBackVector(&v1, 2);
	PushBackVector(&v1, 3);
	PushBackVector(&v1, 4);
	PushBackVector(&v1, 5);
}

int main()
{
	TestVector1();

	return 0;
}