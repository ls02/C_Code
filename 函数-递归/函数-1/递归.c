#include<stdio.h>
int ass(int a);
int main()
{
	int a, b;

	scanf("%d", &a);

	b = ass(a);
	printf("%d", b);
}

int ass(int a)
{
	if (a < 1)
	{
		return 0;
	}//4+3=7+2=9+1=10
	return a + ass(a - 1);
	//�ܽ����ifΪ�������������return Ϊ0����˵��ִ�����˾Ͳ�ִ���������1�ҾͶ�ִ��һ������Ǹ�һ�Ҿ��� ִ��һ��
	//return a���ֵ�ǲ���ģ�ass��a-1����һֱ�仯�ľ����������a����������if����һֱѭ��ֱ�����㣬����ִ��return 0
}