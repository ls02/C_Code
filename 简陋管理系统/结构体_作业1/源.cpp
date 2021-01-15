#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Xue_Sheng
{
	int ID;
	char name[20];
	char sex[4];
	char Ban_Ji[10];
	float Cheng_Ji;
	int Nian_Ling;
}X_S; 

typedef struct Lao_Shi
{
	int ID;
	char name[10];
	char sex[4];
	int Nian_Ling;
}L_S;

typedef struct Ban_Ji
{
	int Ban_Ji_ID;
	char BJ_nema[20];
	char BZR_name[20];
	int Ren_Shu;
}B_J;

//声明结构体
X_S S[30];
L_S L[3];
B_J B[3];

int Xu_Lie[30] = {0};
int LS_Xu_Lie[3] = { 0 };
int BJ_Xu_Lie[3] = { 0 };

//菜单界面
void Cai_Dan()
{
	printf("****************************************************\n");
	printf("***  1.录入信息   2.查看录入信息   0.退出程序    ***\n");
	printf("****************************************************\n");
}

//录入信息选择菜单
void XX_CD()
{
	printf("***************************************************\n");
	printf("***    1.录入学生信息     2.录入教师信息        ***\n");
	printf("***    3.录入班级信息     4.单独录入个别信息    ***\n");
	printf("***             0.返回上一级                    ***\n");
	printf("***************************************************\n");
}

//学生录入和修改选择菜单
void LR_XG()
{
	printf("*********************************************\n");
	printf("***         学生录入和修改系统            ***\n");
	printf("***  1.录入   2.修改录入   0.返回上一级   ***\n");
	printf("*********************************************\n");
}

//学生录入模块
void Lu_Ru1()
{

	int a=0;
	int Id=0,Nian_L=0;
	float Cj = 0;
	char ch;
	do
	{
		system("cls");
		printf("返回上一级输入0\n请输入序列号(1-30)>:");
		scanf("%d",&a);
		if (a >= 1 && a <= 30)
		{
			if (Xu_Lie[a-1] != 1)
			{
				Xu_Lie[a-1] = a;
				printf("请输入ID>:");
				scanf("%d", &Id);
				S[a-1].ID = Id;
				ch = getchar();
				printf("请输入姓名>:");
				gets_s(S[a - 1].name);
				printf("请输入性别>:");
				gets_s(S[a - 1].sex);
				printf("请输入班级(如八四班>:");
				gets_s(S[a - 1].Ban_Ji);
				printf("请输入成绩>:");
				scanf("%f", &Cj);
				S[a - 1].Cheng_Ji = Cj;
				printf("请输入年龄>:");
				scanf("%d", &Nian_L);
				S[a - 1].Nian_Ling = Nian_L;
				printf("录入完成！\n\n");
			}
			else
			{
				printf("此序列号已被录入过请更换序列号！\n\n");
			}
		}
		else if (a == 0)
		{
			return;
		}
		else
		{
			printf("请输入1-30之间的数字！\n\n");
		}
	} while (1);
}

//学生序列号索引修改
void XX_Xu_Lie()
{
	system("cls");
	int i = 0;
	int c, Id, Nian_L;
	char ch;
	float Cj;
	printf("请输入序列号>:");
	scanf("%d", &c);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] == c)
		{
			printf("请输入ID>:");
			scanf("%d", &Id);
			S[i].ID = Id;
			ch = getchar();
			printf("请输入姓名>:");
			gets_s(S[i].name);
			printf("请输入性别>:");
			gets_s(S[i].sex);
			printf("请输入班级(如八四班就输入0804)>:");
			gets_s(S[i].Ban_Ji);
			printf("请输入成绩>:");
			scanf("%f", &Cj);
			S[i].Cheng_Ji = Cj;
			printf("请输入年龄>:");
			scanf("%d", &Nian_L);
			S[i].Nian_Ling = Nian_L;
			printf("修改完成！\n\n");
			break;
		}
		if (S[i].ID != c)
		{
			printf("此ID，没有录入\n\n");
			break;
		}
	}
}


//学号索引修改模块
void Xue_Hao()
{
	int i = 0;
	int c,Id,Nian_L;
	char ch;
	float Cj;
	printf("请输入ID>:");
	scanf("%d", &c);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == c)
		{
			printf("请输入ID>:");
			scanf("%d", &Id);
			S[i].ID = Id;
			ch = getchar();
			printf("请输入姓名>:");
			gets_s(S[i].name);
			printf("请输入性别>:");
			gets_s(S[i].sex);
			printf("请输入班级(如八四班就输入0804)>:");
			gets_s(S[i].Ban_Ji);
			printf("请输入成绩>:");
			scanf("%f", &Cj);
			S[i].Cheng_Ji = Cj;
			printf("请输入年龄>:");
			scanf("%d", &Nian_L);
			S[i].Nian_Ling = Nian_L;
			printf("修改完成！\n\n");
			break;
		}
		if(S[i].ID!=c)
		{
			printf("此ID，没有录入\n\n");
			break;
		}
	}
}

//学生修改录入信息模块
void XX_Xiu_Gai()
{
	int a;
	//实现学号、序列号修改
	do
	{
		system("cls");
		printf("*************************************\n");
		printf("***  1.学号修改    2.序列号修改   ***\n");
		printf("***          0.返回上一级         ***\n");
		printf("*************************************\n");
		printf("请输入>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Xue_Hao();
			break;
		case 2:
			XX_Xu_Lie();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新输入！\n");
			break;
		}
		
	} while (a);
}


//学生信息录入系统
void XX_Xue_Shen()
{
	int a;
	do
	{
		system("cls");
		LR_XG();
		printf("请选择>:");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:
			Lu_Ru1();
			break;
		case 2:
			XX_Xiu_Gai();
			 break;
		case 0:
			break;
		default:
			printf("输入错误！请重新输入\n\n");
		}
	} while (a);
}




//学生信息查询
void CX_XS()//int Xu_Lie[]
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] != -1)
		{
			printf("ID>:%d\n姓名>:%s\n性别>:%s\n年龄>:%d\n成绩>:%.2f\n班级>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
		}
			
	}
}

//教师录入入口
void LuRu_Jiao_Shi()
{
	int a,id,nl;
	char ch;
	do
	{
		
		printf("请输入1-3的序列号\n返回上一级输入0\n");
		printf("请输入>:");
		scanf("%d", &a);
		if (a >= 1 && a <= 3)
		{
			if (LS_Xu_Lie[a - 1] == -1)
			{
				LS_Xu_Lie[a - 1] = a;
				printf("请输入ID>:");
				scanf("%d", &id);
				L[a - 1].ID = id;
				printf("请输入年龄>:");
				scanf("%d", &nl);
				ch=getchar();
				L[a - 1].Nian_Ling = nl;
				
				printf("请输入姓名>:");
				gets_s(L[a - 1].name);
				printf("请输入性别>:");
				gets_s(L[a - 1].sex);
				printf("录入完成！\n\n");
			}
			else
			{
				printf("此序列号已被录入过请更换序列号！\n\n");
			}
		}
		else if (a == 0)
		{
			return;
		}
		else
		{
			printf("请输入1-3之间的数字！\n\n");
		}
	} while (a);
}

//教师学号修改
void Jiao_Shi_Xue_Hao()
{
	system("cls");
	int a,i,id;
	char ch;
	printf("请输入学号>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &id);
			L[i].ID = id;
			ch = getchar();
			printf("请输入姓名>:");
			gets_s(L[i].name);
			printf("请输入性别>:");
			gets_s(L[i].sex);
			printf("请输入年龄>:");
			scanf("%d", &a);
			printf("修改完成!\n\n");
			break;
		}
		else
		{
			printf("此学号未找到！\n\n");
			break;
		}

	}
}

//序列号修改
void Jiao_Shi_Xu_Lie_Hao()
{
	system("cls");
	int a,i,id;
	char ch;
	printf("请输入序列号>:");
	scanf("%d", &a);
	if (a >= 1 && a <= 3)
	{
		for (i = 0; i < 3; i++)
		{
			if (LS_Xu_Lie[i] == a)
			{
				printf("请输入ID>:");
				scanf("%d", &id);
				L[i].ID = id;
				ch = getchar();
				printf("请输入姓名>:");
				gets_s(L[i].name);
				printf("请输入性别>:");
				gets_s(L[i].sex);
				printf("请输入年龄>:");
				scanf("%d", &a);
				printf("修改完成!\n\n");
				break;
			}
		}
	}
	else
	{
		printf("请输入有效序列号！\n\n");
	}
	
}

//教师修改系统
void Xiu_Gai_Jiao_Shi()
{
	int a;
	do
	{
		system("cls");
		printf("********************************************\n");
		printf("***             教师修改系统             ***\n");
		printf("***      1.学号修改     2.序列号修改     ***\n");
		printf("***             0.返回上一级             ***\n");
		printf("********************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Jiao_Shi_Xue_Hao();
			break;
		case 2:
			Jiao_Shi_Xu_Lie_Hao();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！");
			break;
		}
	} while (a);
}

//教师录入系统
void XX_Jiao_Shi()
{
	
	//1.录入 2.修改 0.返回上一级
	int a;
	do
	{
		system("cls");
		printf("****************************************\n");
		printf("***       教师录入及修改系统         ***\n");
		printf("***  1.录入   2.修改  0.返回上一级   ***\n");
		printf("****************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			LuRu_Jiao_Shi();
			break;
		case 2:
			Xiu_Gai_Jiao_Shi();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (a);
}

void LR_Bj_XX()
{
	int a,id,rs;
	char ch;
	do
	{
		system("cls");
		printf("放回上一级输入0\n请输入班级序列号>:");
		scanf("%d", &a);
		if (a >= 1 && a <= 3)
		{
			if (BJ_Xu_Lie[a - 1] == -1)
			{
				BJ_Xu_Lie[a - 1] = a;
				printf("请输入ID>:");
				scanf("%d", &id);
				B[a - 1].Ban_Ji_ID = id;
				printf("请输入班级人数>:");
				scanf("%d", &rs);
				B[a - 1].Ren_Shu = rs;
				ch = getchar();
				printf("请输入班级名>:");
				gets_s(B[a-1].BJ_nema);
				printf("请输入班主任名>:");
				gets_s(B[a-1].BZR_name);
				printf("录入完成！\n\n");
			}
			else if(BJ_Xu_Lie[a]!=-1)
			{
				printf("此序列号已被录入过请更换序列号！\n\n");
			}
		}
		else if (a==0)
		{
			return;
		}
		else
		{
			printf("请输入1-3内得有效数字!\n\n");
		}
	}while(a);
}

//班级修改模块
void XG_Bj_XX()
{
	system("cls");
	int a,i,id,rs;
	char ch;
	printf("请输入班级序列号>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (BJ_Xu_Lie[i] == a&&BJ_Xu_Lie[i]!=-1)
		{
			printf("请输入ID>:");
			scanf("%d", &id);
			B[a - 1].Ban_Ji_ID = id;
			printf("请输入班级人数>:");
			scanf("%d", &rs);
			B[a - 1].Ren_Shu = rs;
			ch = getchar();
			printf("请输入班级名>:");
			gets_s(B[a - 1].BJ_nema);
			printf("请输入班主任名>:");
			gets_s(B[a - 1].BZR_name);
			printf("修改完成！\n\n");
			return;
		}
		else
		{
			printf("此序列号未录入！\n\n");
			return;
		}
	}
	
}

//班级信息录入及修改
void XX_Ban_Ji()
{
	system("cls");
	int a;
	do
	{
	
		printf("***************************************\n");
		printf("***            班级系统             ***\n");
		printf("***  1.录入班级信息   2.修改信息    ***\n");
		printf("***           0.返回上一级          ***\n");
		printf("***************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			LR_Bj_XX();//班级信息录入
			break;
		case 2:
			XG_Bj_XX();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n\n");
		}
	} while (a);
}

//班级ID修改
void BJ_ID_XG()
{
	system("cls");
	int a,i,id;
	printf("请输入班级ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &id);
			B[i].Ban_Ji_ID = id;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//班级人数修改
void RS_XG()
{
	system("cls");
	int a,rs,i;
	printf("请输入班级ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("请输入人数>:");
			scanf("%d", &rs);
			B[i].Ren_Shu = rs;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//班级昵称修改
void NC_XG()
{
	system("cls");
	int a, i;
	printf("请输入班级ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("请输入班级昵称>:");
			gets_s(B[i].BJ_nema);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改班主任昵称
void BZR_XG()
{
	system("cls");
	int a, i;
	printf("请输入班级ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("请输入班主任昵称>:");
			gets_s(B[i].BZR_name);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}
//单独修改班级
void DD_B_J()
{
	int a;
	do
	{
		system("cls");
		printf("********************************************\n");
		printf("***           班级单独修改系统           ***\n");
		printf("***   1.修改班级昵称   2.修改班级人数    ***\n");
		printf("***   3.修改班主任昵称  4.修改班级ID     ***\n");
		printf("***            0.返回上一级              ***\n");
		printf("********************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			NC_XG();//昵称修改
			break;
		case 2:
			RS_XG();//人数修改
			break;
		case 3:
			BZR_XG();//班主任昵称修改
			break;
		case 4:
			BJ_ID_XG();//ID修改
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择!\n\n");
			break;
		}
	} while (a);
}

//修改学生姓名
void XM_XG()
{
	system("cls");
	int a, i;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入姓名>:");
			gets_s(S[i].name);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改学生ID
void ID_XG()
{
	system("cls");
	int a, i,id;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &id);
			S[i].ID = id;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改学生性别
void XB_XG()
{
	system("cls");
	int a, i;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入性别>:");
			gets_s(S[i].sex);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改学生年龄
void NL_XG()
{
	system("cls");
	int a, i, nl;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &nl);
			S[i].Nian_Ling = nl;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改学生成绩
void CJ_XG()
{
	system("cls");
	int a, i;
	float cj=0;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%f", &cj);
			S[i].Cheng_Ji = cj;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改学生班级
void BJ_XGai()
{
	system("cls");
	int a, i;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入班级>:");
			gets_s(S[i].Ban_Ji);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//单独修改学生信息
void DD_X_S()
{
	int a;
	do
	{
		system("cls");
		printf("****************************************************\n");
		printf("***                学生单独修改系统              ***\n");
		printf("***     1.修改ID     2.修改姓名   3.修改性别     ***\n");
		printf("***     4.修改年龄   5.修改班级   6.修改成绩     ***\n");
		printf("***                 0.返回上一级                 ***\n");
		printf("****************************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ID_XG();//ID修改
			break;
		case 2:
			XM_XG();//姓名修改
			break;
		case 3:
			XB_XG();//性别修改
			break;
		case 4:
			NL_XG();//年龄修改
			break;
		case 5:
			BJ_XGai();//班级修改
			break;
		case 6:
			CJ_XG();//成绩修改
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择!\n\n");
			break;
		}
	} while (a);
}

//修改教师年龄
void J_S_XG()
{
	system("cls");
	int a, i, nl;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &nl);
			L[i].Nian_Ling = nl;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改教师ID
void JS_ID_XG()
{
	system("cls");
	int a, i, id;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (S[i].ID == a)
		{
			printf("请输入ID>:");
			scanf("%d", &id);
			S[i].ID = id;
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改教师性别
void JS_XB_XG()
{
	system("cls");
	int a, i;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("请输入性别>:");
			gets_s(L[i].sex);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}

//修改教师姓名
void JS_XM_XG()
{
	system("cls");
	int a, i;
	printf("请输入ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("请输入性别>:");
			gets_s(L[i].name);
			return;
		}
		else
		{
			printf("此ID未录入！\n\n");
			return;
		}
	}
}



//单独修改教师
void DD_J_S()
{

	int a;
	do
	{
		system("cls");
		printf("*******************************************\n");
		printf("***             教师修改系统            ***\n");
		printf("***     1.修改姓名      2.修改年龄      ***\n");
		printf("***     3.修改性别      4.修改ID        ***\n");
		printf("***             0.返回上一级            ***\n");
		printf("*******************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			JS_XM_XG();
			break;
		case 2:
			J_S_XG();//修改教师年龄
			break;
		case 3:
			JS_XB_XG();
			break;
		case 4:
			JS_ID_XG();//教师ID修改
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n\n");
			break;
		}
	} while (a);
}

//单独录入和修改系统
void DL_XG()
{
	int a;
	do
	{
		system("cls");
		printf("**************************************************\n");
		printf("***             单独录入及修改系统            ****\n");
		printf("***   1.单独修改班级     2.单独修改学生信息    ***\n");
		printf("***   3.单独修改教师信息   0.返回上一级        ***\n");
		printf("**************************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			DD_B_J();
			break;
		case 2:
			DD_X_S();
			break;
		case 3:
			DD_J_S();
			break;
		case 0:
			break;
		default :
			printf("选择错误，请重新选择！\n\n");
			break;
		}
	} while (a);
}

void XS_Lu_Ru()
{
	//1.录入学生信息 2.录入教师信息 3.录入班级信息 4.单独录入系统和修改
	int a;
	do
	{
		system("cls");
		XX_CD();
		printf("请选择>:");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:
			XX_Xue_Shen();//学生信息
			return;
		case 2:
			XX_Jiao_Shi();//老师信息
			break;
		case 3:
			XX_Ban_Ji();//班级信息
			break;
		case 4:
			DL_XG();//单独录入和修改
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (a);
	
}

//序列初始化
void XLH()
{
	int i = 0;
	for (i = 0; i < 30; i++)
	{

		Xu_Lie[i] = -1;
	}
}

void LSxlh()
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{

		LS_Xu_Lie[i] = -1;
	}
}

void BJxlh()
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{

		BJ_Xu_Lie[i] = -1;
	}
}

//查询个人学生信息
void CX_XS_GR()
{
	
	int a,i;
	printf("请输入ID查询>:");
	scanf("%d", &a);
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("ID>:%d\n姓名>:%s\n性别>:%s\n年龄>:%d\n成绩>:%.2f\n班级>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
			return;
		}
		else
		{
			printf("没找到此ID！\n\n");
			return;
		}
	}
}

//查询所有学生信息
void CX_XS_ALL()
{
	
	system("cls");
	int i;
	for (i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] != -1)
		{
		printf("ID>:%d\n姓名>:%s\n性别>:%s\n年龄>:%d\n成绩>:%.2f\n班级>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
		
		}
	}
}


//学生信息查询
void CX_XS_XX()
{
	system("cls");
	int a;
	do
	{
		
		printf("************************************************\n");
		printf("***                 查看学生信息             ***\n");
		printf("***         1.查看所有学生信息               ***\n");
		printf("***         2.查看个人信息    0.返回上一级   ***\n");
		printf("************************************************\n");
		printf("请输入>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			CX_XS_ALL();
			break;
		case 2:
			CX_XS_GR();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (a);
}


//查询教师信息
void CX_JS_XX()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if(LS_Xu_Lie[i]!=-1)

		printf("ID>:%d\n姓名>:%s\n年龄>:%d\n性别>:%s\n\n\n",L[i].ID,L[i].name,L[i].Nian_Ling,L[i].sex);

	}
}

void B_JXX_CX()
{

	system("cls");
	int a;
	for (int i = 0; i < 3; i++)
	{
		if (BJ_Xu_Lie[i] != -1)
		{
			printf("班级ID>:%d\n班级名称>:%s\n班主任>:%s\n班级人数>:%d\n\n\n", B[i].Ban_Ji_ID, B[i].BJ_nema, B[i].BZR_name, B[i].Ren_Shu);
		}
	}


}

void CX_ALL()
{

	int a;
	do
	{
		printf("******************************************************\n");
		printf("***                    查询系统                    ***\n");
		printf("***      1.学生信息查看       2.教师信息查看       ***\n");
		printf("***      3.班级信息查看       0.返回上一级         ***\n");
		printf("******************************************************\n");
		printf("请选择>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			CX_XS_XX();//学生查询
			break;
		case 2:
			CX_JS_XX();//教师信息
			break;
		case 3:
			B_JXX_CX();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	}while(a);
}

//起始入口
void Ru_Kou()
{
	int a;
	do
	{
		system("cls");
		Cai_Dan();
		printf("请选择>:");
		scanf("%d", &a);
		putchar('\n');
		switch(a)
		{
		case 1:
			XS_Lu_Ru();
			break;
		case 2:
			CX_ALL();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (a);
}

int main()
{
	//初始化序列号
	XLH();
	LSxlh();
	BJxlh();
	//1.菜单界面：退出程序、登记程序、查看程序。
	//2.登记程序：可修改，可覆盖被占用过的类型。
	//3.查看程序：不可被修改，只能被查看,退出查看界面.
	//把登记界面封装成函数，其它功能也封装成函数，方便调用和修改。
	Ru_Kou();//入口1


	return 0;
}