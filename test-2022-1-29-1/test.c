#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct stu
{
	char name[20];
	int age;
	float score;
}stu;

//int main()
//{
//	stu s1 = { 0 };
//
//	FILE* fp1 = fopen("dataB.txt", "rb");
//	if (!fp1)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	//读文件
//	fread(&s1, sizeof(s1), 1, fp1);
//
//	printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.score);
//
//	fclose(fp1);
//	fp1 = NULL;
//}

int main()
{
	stu s1 = { "张三", 15, 35.22f };

	FILE* fp1 = fopen("dataB.txt", "wb");
	if (!fp1)
	{
		printf("%s\n", strerror(errno));

		return 1;
	}

 //写文件
	fwrite(&s1, sizeof(s1), 1, fp1);

	if (ferror(fp1))
	{
		printf("文件写入失败！\n");
	}
	else if (feof(fp1))
	{
		printf("文件读取错误！\n");
	}

	fclose(fp1);
	fp1 = NULL;

	return 0;
}

//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//}stu;
//
//int main()
//{
//	stu s1 = { "张三", 25, 66.32f };
//	char buff[200] = { 0 };
//
//	//把结构体赚字符串，sscanf则是转回结构体
//	sprintf(buff, "%s %d %f", s1.name, s1.age, s1.score);
//	printf("%s\n", buff);
//
//	stu s2 = { 0 };
//	sscanf(buff, "%s %d %f", s2.name, &(s2.age), &(s2.score));
//
//	printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.score);
//
//	return 0;
//}


//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//}stu;
//
//int main()
//{
//	stu s1 = { "张三", 25, 66.32f };
//	stu s2 = { 0 };
//
//	FILE* pf1 = fopen("data.txt", "r+");
//	if (!pf1)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	//fprintf(pf1, "%s\t%d\t%.2f\n", s1.name, s1.age, s1.score);
//	fscanf(stdin, "%s %d %f", s2.name, &(s2.age), &(s2.score));
//
//	printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.score);
//
//	fclose(pf1);
//	pf1 = NULL;
//
//	return 0;
//}

//int main()
//{
//	char str1[1024] = { 0 };
//	FILE* pf1 = fopen("test.txt", "r");
//	if (!pf1)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//
//	while (fgets(str1, 100, pf1))
//	{
//		printf("%s", str1);
//	}
//
//	fclose(pf1);
//	pf1 = NULL;
//
//	return 0;
//}