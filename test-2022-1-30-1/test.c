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
	stu s1 = { "����", 20, 352.55f };
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
//	stu s1 = { "����", 20, 352.55f };
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
//	stu s1 = { "����", 25, 321.44f };
//	FILE* pf = fopen("data.txt", "w");
//	if (!pf)
//	{
//		printf("%s\n", strerror(errno));
//
//		return 1;
//	}
//
//	fprintf(pf, "������%s\n���䣺%d\n�ɼ���%.2f\n", s1.name, s1.age, s1.score);
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
//	//��ȡ�������ļ���ŵ�s1��
//	fread(&s1, sizeof(s1), 1, pf);
//
//	//ȷ���Ƿ��Ž�ȥ
//	printf("%s\t%d\t%f\n", s1.name, s1.age, s1.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//int main()
//{
//	stu s1 = { "����", 12, 22.42f };
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
//		printf("�����Ѷ��꣬��ȡ����\n");
//	}
//
//	printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.score);
//
//	return 0;
//}

//int main()
//{
//	//���ļ�
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
//	if (feof(pf))//�ж��Ƿ���Ϊ��ȡ��������������ɵ�����
//	{
//		printf("�����Ѷ��꣬��ȡʧ�ܣ�\n");
//	}
//	printf("%s\n%s", str, pstr);
//
//	fclose(pf);//�ر��ļ�
//	pf = NULL;//�ÿշ�ֹ����������Խ����ʡ�
//
//	return 0;
//}

//int main()
//{
//	//���ļ�
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
//	//��ȡһ���ַ�
//	printf("%c\n", ch);
//
//	//ÿ�ζ�ȡ�����ַ�ֱ����ȡ����߶�ȡָ���������ַ�
//	while (~(ch = fgetc(pf)))
//	{
//		printf("%c", ch);
//	}
//
//	//���������ڶ�ȡһ����Ҳ����ʹ��ѭ���ĳɶ�ζ�ȡ��׼�������ڵ�����
//	ch = fgetc(stdin);
//	printf("%c", ch);
//
//	fclose(pf);//�ر��ļ�
//	pf = NULL;//�ÿշ�ֹ����������Խ����ʡ�
//
//	return 0;
//}