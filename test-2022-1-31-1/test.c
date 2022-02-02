#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int ch = 0;
	FILE* fp = fopen("data.txt", "r");
	if (!fp)
	{
		printf("%s\n", strerror(errno));

		return 1;
	}

	while (~(ch = fgetc(fp)))
	{
		printf("%c", ch);
	}

	//如果正常读取完结束会返回一个真
	if (feof(fp))
	{
		printf("正常结束\n");
	}
	//如果读取没错误会返回一个0，如果读取错误会返回也给非零值
	else if (ferror(fp))
	{
		printf("I/O流读取错误\n");
	}

	return 0;
}

//int main()
//{
//	int ch = 0;
//	FILE* fp = fopen("data.txt", "w");
//	if (!fp)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	int count = 0;
//
//	while (count < 10)
//	{
//		fputc('a' + count, fp);
//		count++;
//	}
//
//	//偏移到文件开始进行写入
//	rewind(fp);
//
//	fputs("666", fp);
//
//	fclose(fp);
//	fp = NULL;
//
//	return 0;
//}

//int main()
//{
//	FILE* fp = fopen("data.txt", "r");
//	if (!fp)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	
//	int ch = fgetc(fp);
//	printf("%c\n", ch);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//
//	//当前位置开始偏移
//	fseek(fp, 2, SEEK_CUR);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//	fseek(fp, -1, SEEK_CUR);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//
//	//文件开头开始偏移
//	fseek(fp, 1, SEEK_SET);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//
//	//文件末尾开始偏移
//	fseek(fp, -1, SEEK_END);
//	//返回一个偏移量
//	int count = ftell(fp);
//	ch = fgetc(fp);
//	printf("%c %d\n", ch, count);
//
//	return 0;
//}

//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//}stu;


//int main()
//{
//	stu s1 = { "张三", 25, 300.55f };
//	char buff[200] = { 0 };
//
//	//把结构化的数据转换为字符串，存储到buff里面
//	sprintf(buff, "%s %d %.2f", s1.name, s1.age, s1.score);
//	printf("%s\n", buff);
//
//	stu temp = { 0 };
//	//把一个buff结构化后的字符串，转换为结构化数据存储到temp结构体变量里面
//	sscanf(buff, "%s %d %f", temp.name, &(temp.age), &(temp.score));
//	printf("姓名：%s\t年龄：%d\t成绩：%.2f\n", temp.name, temp.age, temp.score);
//
//	return 0;
//}