#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>

//int main()//���ֲ��ҷ�
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int len = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int hen = sz - 1;
//	int mid = 0;
//	int k;
//
//	scanf("%d", &k);
//
//	while (len <= hen)
//	{
//		mid = (len + hen) / 2;
//		if (arr[mid] > k)
//		{
//			hen = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			len = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d", mid);
//			break;
//		}
//	}
//
//	if (len > hen)
//	{
//		printf("�Ҳ�����\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int hen = sz - 1;
//	int len = 0;
//	int i = 0;
//
//	int k = 9;
//
//	while (len<=hen)
//	{
//		int mid = (len + hen) / 2;
//		if (arr[mid]>k)
//		{
//			hen = mid-1;
//		}
//		else if (arr[mid] < k)
//		{
//			len = mid+1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±��ǣ�%d",mid);
//			break;
//		}
//	}
//
//	if (len > hen)
//	{
//		printf("�Ҳ�����\n");
//	}
//
//	return 0;
//}

//int main()//n�Ľ׳����
//{
//	int a;
//	int i = 0;
//	int ret = 1;
//	int k = 0;
//
//	scanf("%d", &a);
//
//	for (i = 1; i <= a; i++)
//	{
//		ret *= i;
//		k += ret;
//	}
//	printf("%d\n", k);
//	return 0;
//}

//int main()
//{
//	int a;
//	int i = 0;//n�Ľ׳�
//	int ret = 2;
//
//	scanf("%d",&a);
//
//	for (i = 1; i <= a; i++)
//	{
//		ret *=i;
//	}
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	do//��ִ��һ������
//	{
//		printf("%d ", i);//��ʱ��i=1
//		i++;//��ʱ��i=1
//	} while (i <= 10);//��ʱ��i=2������10����ѭ��
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//
//	for (i = 1; i <= 10; i++)//��ӡ1-10���������ʽ1ֻ����for��ʼ��ʱ��ִ��һ�Σ���Ҳ�ǵ�һ��ִ�е�
//	{//���ʽ2�ǵڶ���ִ�е������ж��Ƿ����ѭ�����ʽ3�����ִ�е���������ѭ��
//		printf("%d ", i);//��ӡi��ֵÿִ��һ�ξʹ�ӡһ��
//		continue;//����Ĵ��벻ִ�е��ǲ�Ӱ��i++����Ϊi++ִ��˳�������һ��Ҳ�����ڴ����ִ�����˲�ִ����
//	}
//	//ִ��˳���ǣ���һ�����ʽ1���ڶ������ʽ2��������for�����������ݣ����ĸ����ʽ3
//	return 0;
//}

//int main()
//{
//	char mima[10] = { 0 };
//	
//	printf("����������:>");
//	scanf("%d", mima);//�س���Ϊ�������������ûس�����ʱ�Ļ��������лس�
//	int ch1;
//	while ((ch1 = getchar()) != '\n')//������ջ�����
//	{
//		;
//	}
//	printf("��ȷ��(Y/N):>");
//	int ch = getchar();//��ʱӦ�õȴ��û����뵫�ǻ������лس���ֱ���������Ի�����Լ����뿴���Ľ��
//
//	if (ch == 'Y')
//	{
//		printf("ȷ�ϳɹ���\n");
//	}
//	else
//	{
//		printf("ȷ��ʧ�ܣ�\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//
//	while ((ch = getchar()) != EOF)//��ȡʧ��EOF�ͽ���EOF��ctrl+z��EOF
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	
//	ch = getchar();//����һ���ַ���ch
//	putchar(ch);//���ch�����ֵ
//
//	
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (i == 5)
//			continue;//�������5����Ĵ��벻ִ��
//		printf("%d ", i);//��ӡ����1,2,3,4���ͻ���ѭ������ӡһֱ�˲���ȥ
//		i++;//��ִ�д�ʱ��i����ı����Ի������ѭ��
//	}
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//
//	while (i <= 10)
//	{
//		if (i == 5)//���i����5��������ѭ��Ҳ���ǹ���ӡ��4�Σ����������
//			break;
//		printf("%d ", i);
//		i++;
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 1;
//
//	while (a<=10)//����������ִ�У����a������10��һֱִ��
//	{
//		printf("%d ", a);//ûִ��һ�δ�ӡһ��
//		a++;//�˳�ѭ��������
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	if(a)//������Ӵ�����ֻ����һ�������if �����ݣ�
//		printf("haha\n");
//	printf("999");
//
//	if (a)//��ʱ�����������������if��������
//	{
//		printf("heh");
//		printf("6666");
//	}
//
//	return 0;
//}

//int mian()
//{
//	int a = 10;
//
//	switch (a)//������Ϊ�ж�����
//	{
//		case 1:
//			printf("����һ\n");//�����������1���������������û��break��ȫ�����ֱ������
//			break;
//		case 2:
//			printf("���ڶ�\n");//Ҫô����break����Ҫôȫ��ִ����
//			break;
//		case 3:
//			printf("������\n");
//			break;
//		case 4:
//			printf("������\n");
//			break;
//		case 5:
//			printf("������\n");
//			break;
//		case 6:
//			printf("������\n");
//			break;
//		case 7:
//			printf("������\n");
//			break;
//		default://defulat������ϵ�caseû�������ִ��deflaut
//			printf("�������\n");
//			break;
//	}
//
//	return 0;
//}

//int mian()
//{
//	int a = 10;
//
//	if (a != 2)//���������2��ִ����������ݵ��ھͲ�ִ�У����������жϡ�
//	{
//		printf("hehe");
//	}
//	else if (a == 4)//else if��������ifΪ�����ж���һ��else if
//	{
//		printf("666\n");
//	}
//	else//else�����������ifû�������ʱ��ִ��
//	{
//		printf("haha\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	
//	if (a)//���û����ֻ�����֣�����Ϊ�棬��Ϊ�٣����Ϊ��ִif��������ݣ����Ϊ�٣���ִ��
//	{
//		printf("hehe\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int j = 1;
//	int i = 0;
//	int n = 1;
//	int k = 0;
//
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)//��ӵĽ׳�
//	{
//		j *= i;
//	return 0;
//}

//int main()
//{
//	int b;
//	int k;
//	k = b = 1;
//	printf("%d %d", k, b);
//	return 0;
//}