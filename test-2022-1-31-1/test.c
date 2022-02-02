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

	//���������ȡ������᷵��һ����
	if (feof(fp))
	{
		printf("��������\n");
	}
	//�����ȡû����᷵��һ��0�������ȡ����᷵��Ҳ������ֵ
	else if (ferror(fp))
	{
		printf("I/O����ȡ����\n");
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
//	//ƫ�Ƶ��ļ���ʼ����д��
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
//	//��ǰλ�ÿ�ʼƫ��
//	fseek(fp, 2, SEEK_CUR);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//	fseek(fp, -1, SEEK_CUR);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//
//	//�ļ���ͷ��ʼƫ��
//	fseek(fp, 1, SEEK_SET);
//	ch = fgetc(fp);
//	printf("%c\n", ch);
//
//	//�ļ�ĩβ��ʼƫ��
//	fseek(fp, -1, SEEK_END);
//	//����һ��ƫ����
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
//	stu s1 = { "����", 25, 300.55f };
//	char buff[200] = { 0 };
//
//	//�ѽṹ��������ת��Ϊ�ַ������洢��buff����
//	sprintf(buff, "%s %d %.2f", s1.name, s1.age, s1.score);
//	printf("%s\n", buff);
//
//	stu temp = { 0 };
//	//��һ��buff�ṹ������ַ�����ת��Ϊ�ṹ�����ݴ洢��temp�ṹ���������
//	sscanf(buff, "%s %d %f", temp.name, &(temp.age), &(temp.score));
//	printf("������%s\t���䣺%d\t�ɼ���%.2f\n", temp.name, temp.age, temp.score);
//
//	return 0;
//}