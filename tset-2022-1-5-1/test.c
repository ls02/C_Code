#include <stdio.h>
#include <string.h>

int main()
{
	char str[20] = { 0 };

	int i = 0;

	for (i = 0; i < 10; i++)
	{
		str[i] = getchar();
	}

	printf("%s\n", str);

	return 0;
}

//#include <stdio.h>
//#include <conio.h>
//#include <windows.h>
//int main()
//{
//    char p[20];
//    char* password = "1234";
//    int i = 0;
//    printf("enter your password(«Î ‰»Î√‹¬Î)\n");
//    do
//    {
//        p[i] = getchr();
//        if (p[i] == '\r')
//            break;
//        if (p[i] == '\b')
//        {
//            if (i == 0)
//            {
//                printf("\a");
//                continue;
//            }
//            i = i - 1;
//            printf("\b");
//        }
//        else
//        {
//            i = i + 1;
//            printf("*");
//        }
//    } while (p[i] != '\n' && i < 20);
//    p[i] = '\0';
//    printf("\n’˝»∑√‹¬Î£∫%s; ‰»Î√‹¬Î£∫%s\n", password, p);
//    if (strcmp(p, password) == 0)
//        printf("right!\n");
//    else
//        printf("error!\n");
//    system("pause");
//    return 0;
//}