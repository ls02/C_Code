#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>

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
//	int i = 0;
//
//	//int ch = fgetc(fp);
//
//	//printf("%c\n", ch);
//
//	int ch = 0;
//	
//	while (~(ch = fgetc(fp)))
//	{
//		printf("%c ", ch);
//	}
//
//	fclose(fp);
//	fp = NULL;
//
//	return 0;
//}

//int main()
//{
//	int ch = fgetc(stdin);
//	printf("%c", ch);
//
//	return 0;
//}

int main()
{
	//FILE* fp = fopen("data.txt", "w");
	//if (!fp)
	//{
	//	printf("%s\n", strerror(errno));
	//	
	//	return 1;
	//}

	//fputs("hello world!\n", stdout);
	//fputs("hello world!\n", fp);

	//fclose(fp);
	//fp = NULL;

	char arr[1000] = { 0 };

	FILE* fp = fopen("data.txt", "r");
	if (!fp)
	{
		printf("%s\n", strerror(errno));

		return 1;
	}

	while (fgets(arr, 100, fp))
	{
		printf("%s", arr);

	}

	fclose(fp);
	fp = NULL;

	return 0;
}