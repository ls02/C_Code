#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef struct stu
{
	char name[20];
	int age;
	float score;
}stu;

int main()
{
	stu s1 = { "张三", 20, 352.55f };
	stu s2 = { 0 };
	FILE* pf = fopen("dataB.txt", "wb");
	if (!pf)
	{
		printf("%s\n", strerror(errno));

		return 1;
	}

	fwrite(&s1, sizeof(stu), 1, pf);

	fclose(pf);
	pf = NULL;

	return 0;
}

//int main()
//{
//	stu s1 = { "张三", 20, 352.55f };
//	stu s2 = { 0 };
//	FILE* pf = fopen("dataB.txt", "wb");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fwrite(&s1, sizeof(stu), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	pf = fopen("dataB.txt", "rb");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fread(&s2, sizeof(stu), 1, pf);
//
//	printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	stu s1 = { "张三", 25, 321.44f };
//	FILE* pf = fopen("data.txt", "w");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fprintf(pf, "姓名：%s\n年龄：%d\n成绩：%.2f\n", s1.name, s1.age, s1.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	char* str = "Hello world";
//	FILE* pf = fopen("data.txt", "w");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fputs(str, pf);
//
//	printf("%s\n", str);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//int main()
//{
//	int ch = 0;
//	FILE* pf = fopen("data.txt", "w");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	ch = getchar();
//	fputc(ch, pf);
//	printf("%c", ch);
//
//	return 0;
//}



//int main()
//{
//	stu s1 = { 0 };
//	FILE* pf = fopen("dataB.txt", "rb");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	//读取二进制文件存放到s1里
//	fread(&s1, sizeof(s1), 1, pf);
//
//	//确认是否存放进去
//	printf("%s\t%d\t%f\n", s1.name, s1.age, s1.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	stu s1 = { "张三", 12, 22.42f };
//	FILE* pf = fopen("dataB.txt", "wb");
//
//
//	fwrite(&s1, sizeof(s1), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	stu s1 = { 0 };
//	FILE* fp = fopen("data.txt", "r");
//	if (!fp)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fscanf(fp, "%s %d %f", s1.name, &(s1.age), &(s1.score));
//	if (ferror(fp))
//	{
//		printf("数据已读完，读取错误！\n");
//	}
//
//	printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.score);
//
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	char str[20] = { 0 };
//	char* pstr = 0;
//
//	pstr = fgets(str, 8, pf);
//	if (feof(pf))//判断是否因为读取完整个数据流造成的问题
//	{
//		printf("数据已读完，读取失败！\n");
//	}
//	printf("%s\n%s", str, pstr);
//
//	fclose(pf);//关闭文件
//	pf = NULL;//置空防止被误操作造成越界访问。
//
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	int ch = 0;
//
//	ch = fgetc(pf);
//
//	//读取一个字符
//	printf("%c\n", ch);
//
//	//每次读取单个字符直到读取完或者读取指定个数的字符
//	while (~(ch = fgetc(pf)))
//	{
//		printf("%c", ch);
//	}
//
//	//从输入流内读取一个，也可以使用循环改成多次读取标准输入流内的数据
//	ch = fgetc(stdin);
//	printf("%c", ch);
//
//	fclose(pf);//关闭文件
//	pf = NULL;//置空防止被误操作造成越界访问。
//
//	return 0;
//}