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

//�����ṹ��
X_S S[30];
L_S L[3];
B_J B[3];

int Xu_Lie[30] = {0};
int LS_Xu_Lie[3] = { 0 };
int BJ_Xu_Lie[3] = { 0 };

//�˵�����
void Cai_Dan()
{
	printf("****************************************************\n");
	printf("***  1.¼����Ϣ   2.�鿴¼����Ϣ   0.�˳�����    ***\n");
	printf("****************************************************\n");
}

//¼����Ϣѡ��˵�
void XX_CD()
{
	printf("***************************************************\n");
	printf("***    1.¼��ѧ����Ϣ     2.¼���ʦ��Ϣ        ***\n");
	printf("***    3.¼��༶��Ϣ     4.����¼�������Ϣ    ***\n");
	printf("***             0.������һ��                    ***\n");
	printf("***************************************************\n");
}

//ѧ��¼����޸�ѡ��˵�
void LR_XG()
{
	printf("*********************************************\n");
	printf("***         ѧ��¼����޸�ϵͳ            ***\n");
	printf("***  1.¼��   2.�޸�¼��   0.������һ��   ***\n");
	printf("*********************************************\n");
}

//ѧ��¼��ģ��
void Lu_Ru1()
{

	int a=0;
	int Id=0,Nian_L=0;
	float Cj = 0;
	char ch;
	do
	{
		system("cls");
		printf("������һ������0\n���������к�(1-30)>:");
		scanf("%d",&a);
		if (a >= 1 && a <= 30)
		{
			if (Xu_Lie[a-1] != 1)
			{
				Xu_Lie[a-1] = a;
				printf("������ID>:");
				scanf("%d", &Id);
				S[a-1].ID = Id;
				ch = getchar();
				printf("����������>:");
				gets_s(S[a - 1].name);
				printf("�������Ա�>:");
				gets_s(S[a - 1].sex);
				printf("������༶(����İ�>:");
				gets_s(S[a - 1].Ban_Ji);
				printf("������ɼ�>:");
				scanf("%f", &Cj);
				S[a - 1].Cheng_Ji = Cj;
				printf("����������>:");
				scanf("%d", &Nian_L);
				S[a - 1].Nian_Ling = Nian_L;
				printf("¼����ɣ�\n\n");
			}
			else
			{
				printf("�����к��ѱ�¼�����������кţ�\n\n");
			}
		}
		else if (a == 0)
		{
			return;
		}
		else
		{
			printf("������1-30֮������֣�\n\n");
		}
	} while (1);
}

//ѧ�����к������޸�
void XX_Xu_Lie()
{
	system("cls");
	int i = 0;
	int c, Id, Nian_L;
	char ch;
	float Cj;
	printf("���������к�>:");
	scanf("%d", &c);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] == c)
		{
			printf("������ID>:");
			scanf("%d", &Id);
			S[i].ID = Id;
			ch = getchar();
			printf("����������>:");
			gets_s(S[i].name);
			printf("�������Ա�>:");
			gets_s(S[i].sex);
			printf("������༶(����İ������0804)>:");
			gets_s(S[i].Ban_Ji);
			printf("������ɼ�>:");
			scanf("%f", &Cj);
			S[i].Cheng_Ji = Cj;
			printf("����������>:");
			scanf("%d", &Nian_L);
			S[i].Nian_Ling = Nian_L;
			printf("�޸���ɣ�\n\n");
			break;
		}
		if (S[i].ID != c)
		{
			printf("��ID��û��¼��\n\n");
			break;
		}
	}
}


//ѧ�������޸�ģ��
void Xue_Hao()
{
	int i = 0;
	int c,Id,Nian_L;
	char ch;
	float Cj;
	printf("������ID>:");
	scanf("%d", &c);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == c)
		{
			printf("������ID>:");
			scanf("%d", &Id);
			S[i].ID = Id;
			ch = getchar();
			printf("����������>:");
			gets_s(S[i].name);
			printf("�������Ա�>:");
			gets_s(S[i].sex);
			printf("������༶(����İ������0804)>:");
			gets_s(S[i].Ban_Ji);
			printf("������ɼ�>:");
			scanf("%f", &Cj);
			S[i].Cheng_Ji = Cj;
			printf("����������>:");
			scanf("%d", &Nian_L);
			S[i].Nian_Ling = Nian_L;
			printf("�޸���ɣ�\n\n");
			break;
		}
		if(S[i].ID!=c)
		{
			printf("��ID��û��¼��\n\n");
			break;
		}
	}
}

//ѧ���޸�¼����Ϣģ��
void XX_Xiu_Gai()
{
	int a;
	//ʵ��ѧ�š����к��޸�
	do
	{
		system("cls");
		printf("*************************************\n");
		printf("***  1.ѧ���޸�    2.���к��޸�   ***\n");
		printf("***          0.������һ��         ***\n");
		printf("*************************************\n");
		printf("������>:");
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
			printf("ѡ��������������룡\n");
			break;
		}
		
	} while (a);
}


//ѧ����Ϣ¼��ϵͳ
void XX_Xue_Shen()
{
	int a;
	do
	{
		system("cls");
		LR_XG();
		printf("��ѡ��>:");
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
			printf("�����������������\n\n");
		}
	} while (a);
}




//ѧ����Ϣ��ѯ
void CX_XS()//int Xu_Lie[]
{
	system("cls");
	for (int i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] != -1)
		{
			printf("ID>:%d\n����>:%s\n�Ա�>:%s\n����>:%d\n�ɼ�>:%.2f\n�༶>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
		}
			
	}
}

//��ʦ¼�����
void LuRu_Jiao_Shi()
{
	int a,id,nl;
	char ch;
	do
	{
		
		printf("������1-3�����к�\n������һ������0\n");
		printf("������>:");
		scanf("%d", &a);
		if (a >= 1 && a <= 3)
		{
			if (LS_Xu_Lie[a - 1] == -1)
			{
				LS_Xu_Lie[a - 1] = a;
				printf("������ID>:");
				scanf("%d", &id);
				L[a - 1].ID = id;
				printf("����������>:");
				scanf("%d", &nl);
				ch=getchar();
				L[a - 1].Nian_Ling = nl;
				
				printf("����������>:");
				gets_s(L[a - 1].name);
				printf("�������Ա�>:");
				gets_s(L[a - 1].sex);
				printf("¼����ɣ�\n\n");
			}
			else
			{
				printf("�����к��ѱ�¼�����������кţ�\n\n");
			}
		}
		else if (a == 0)
		{
			return;
		}
		else
		{
			printf("������1-3֮������֣�\n\n");
		}
	} while (a);
}

//��ʦѧ���޸�
void Jiao_Shi_Xue_Hao()
{
	system("cls");
	int a,i,id;
	char ch;
	printf("������ѧ��>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("������ID>:");
			scanf("%d", &id);
			L[i].ID = id;
			ch = getchar();
			printf("����������>:");
			gets_s(L[i].name);
			printf("�������Ա�>:");
			gets_s(L[i].sex);
			printf("����������>:");
			scanf("%d", &a);
			printf("�޸����!\n\n");
			break;
		}
		else
		{
			printf("��ѧ��δ�ҵ���\n\n");
			break;
		}

	}
}

//���к��޸�
void Jiao_Shi_Xu_Lie_Hao()
{
	system("cls");
	int a,i,id;
	char ch;
	printf("���������к�>:");
	scanf("%d", &a);
	if (a >= 1 && a <= 3)
	{
		for (i = 0; i < 3; i++)
		{
			if (LS_Xu_Lie[i] == a)
			{
				printf("������ID>:");
				scanf("%d", &id);
				L[i].ID = id;
				ch = getchar();
				printf("����������>:");
				gets_s(L[i].name);
				printf("�������Ա�>:");
				gets_s(L[i].sex);
				printf("����������>:");
				scanf("%d", &a);
				printf("�޸����!\n\n");
				break;
			}
		}
	}
	else
	{
		printf("��������Ч���кţ�\n\n");
	}
	
}

//��ʦ�޸�ϵͳ
void Xiu_Gai_Jiao_Shi()
{
	int a;
	do
	{
		system("cls");
		printf("********************************************\n");
		printf("***             ��ʦ�޸�ϵͳ             ***\n");
		printf("***      1.ѧ���޸�     2.���к��޸�     ***\n");
		printf("***             0.������һ��             ***\n");
		printf("********************************************\n");
		printf("��ѡ��>:");
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
			printf("ѡ�����������ѡ��");
			break;
		}
	} while (a);
}

//��ʦ¼��ϵͳ
void XX_Jiao_Shi()
{
	
	//1.¼�� 2.�޸� 0.������һ��
	int a;
	do
	{
		system("cls");
		printf("****************************************\n");
		printf("***       ��ʦ¼�뼰�޸�ϵͳ         ***\n");
		printf("***  1.¼��   2.�޸�  0.������һ��   ***\n");
		printf("****************************************\n");
		printf("��ѡ��>:");
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
			printf("ѡ�����������ѡ��!\n");
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
		printf("�Ż���һ������0\n������༶���к�>:");
		scanf("%d", &a);
		if (a >= 1 && a <= 3)
		{
			if (BJ_Xu_Lie[a - 1] == -1)
			{
				BJ_Xu_Lie[a - 1] = a;
				printf("������ID>:");
				scanf("%d", &id);
				B[a - 1].Ban_Ji_ID = id;
				printf("������༶����>:");
				scanf("%d", &rs);
				B[a - 1].Ren_Shu = rs;
				ch = getchar();
				printf("������༶��>:");
				gets_s(B[a-1].BJ_nema);
				printf("�������������>:");
				gets_s(B[a-1].BZR_name);
				printf("¼����ɣ�\n\n");
			}
			else if(BJ_Xu_Lie[a]!=-1)
			{
				printf("�����к��ѱ�¼�����������кţ�\n\n");
			}
		}
		else if (a==0)
		{
			return;
		}
		else
		{
			printf("������1-3�ڵ���Ч����!\n\n");
		}
	}while(a);
}

//�༶�޸�ģ��
void XG_Bj_XX()
{
	system("cls");
	int a,i,id,rs;
	char ch;
	printf("������༶���к�>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (BJ_Xu_Lie[i] == a&&BJ_Xu_Lie[i]!=-1)
		{
			printf("������ID>:");
			scanf("%d", &id);
			B[a - 1].Ban_Ji_ID = id;
			printf("������༶����>:");
			scanf("%d", &rs);
			B[a - 1].Ren_Shu = rs;
			ch = getchar();
			printf("������༶��>:");
			gets_s(B[a - 1].BJ_nema);
			printf("�������������>:");
			gets_s(B[a - 1].BZR_name);
			printf("�޸���ɣ�\n\n");
			return;
		}
		else
		{
			printf("�����к�δ¼�룡\n\n");
			return;
		}
	}
	
}

//�༶��Ϣ¼�뼰�޸�
void XX_Ban_Ji()
{
	system("cls");
	int a;
	do
	{
	
		printf("***************************************\n");
		printf("***            �༶ϵͳ             ***\n");
		printf("***  1.¼��༶��Ϣ   2.�޸���Ϣ    ***\n");
		printf("***           0.������һ��          ***\n");
		printf("***************************************\n");
		printf("��ѡ��>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			LR_Bj_XX();//�༶��Ϣ¼��
			break;
		case 2:
			XG_Bj_XX();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n\n");
		}
	} while (a);
}

//�༶ID�޸�
void BJ_ID_XG()
{
	system("cls");
	int a,i,id;
	printf("������༶ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("������ID>:");
			scanf("%d", &id);
			B[i].Ban_Ji_ID = id;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�༶�����޸�
void RS_XG()
{
	system("cls");
	int a,rs,i;
	printf("������༶ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("����������>:");
			scanf("%d", &rs);
			B[i].Ren_Shu = rs;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�༶�ǳ��޸�
void NC_XG()
{
	system("cls");
	int a, i;
	printf("������༶ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("������༶�ǳ�>:");
			gets_s(B[i].BJ_nema);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸İ������ǳ�
void BZR_XG()
{
	system("cls");
	int a, i;
	printf("������༶ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (B[i].Ban_Ji_ID == a)
		{
			printf("������������ǳ�>:");
			gets_s(B[i].BZR_name);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}
//�����޸İ༶
void DD_B_J()
{
	int a;
	do
	{
		system("cls");
		printf("********************************************\n");
		printf("***           �༶�����޸�ϵͳ           ***\n");
		printf("***   1.�޸İ༶�ǳ�   2.�޸İ༶����    ***\n");
		printf("***   3.�޸İ������ǳ�  4.�޸İ༶ID     ***\n");
		printf("***            0.������һ��              ***\n");
		printf("********************************************\n");
		printf("��ѡ��>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			NC_XG();//�ǳ��޸�
			break;
		case 2:
			RS_XG();//�����޸�
			break;
		case 3:
			BZR_XG();//�������ǳ��޸�
			break;
		case 4:
			BJ_ID_XG();//ID�޸�
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��!\n\n");
			break;
		}
	} while (a);
}

//�޸�ѧ������
void XM_XG()
{
	system("cls");
	int a, i;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("����������>:");
			gets_s(S[i].name);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸�ѧ��ID
void ID_XG()
{
	system("cls");
	int a, i,id;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("������ID>:");
			scanf("%d", &id);
			S[i].ID = id;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸�ѧ���Ա�
void XB_XG()
{
	system("cls");
	int a, i;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("�������Ա�>:");
			gets_s(S[i].sex);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸�ѧ������
void NL_XG()
{
	system("cls");
	int a, i, nl;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("������ID>:");
			scanf("%d", &nl);
			S[i].Nian_Ling = nl;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸�ѧ���ɼ�
void CJ_XG()
{
	system("cls");
	int a, i;
	float cj=0;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("������ID>:");
			scanf("%f", &cj);
			S[i].Cheng_Ji = cj;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸�ѧ���༶
void BJ_XGai()
{
	system("cls");
	int a, i;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("������༶>:");
			gets_s(S[i].Ban_Ji);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�����޸�ѧ����Ϣ
void DD_X_S()
{
	int a;
	do
	{
		system("cls");
		printf("****************************************************\n");
		printf("***                ѧ�������޸�ϵͳ              ***\n");
		printf("***     1.�޸�ID     2.�޸�����   3.�޸��Ա�     ***\n");
		printf("***     4.�޸�����   5.�޸İ༶   6.�޸ĳɼ�     ***\n");
		printf("***                 0.������һ��                 ***\n");
		printf("****************************************************\n");
		printf("��ѡ��>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			ID_XG();//ID�޸�
			break;
		case 2:
			XM_XG();//�����޸�
			break;
		case 3:
			XB_XG();//�Ա��޸�
			break;
		case 4:
			NL_XG();//�����޸�
			break;
		case 5:
			BJ_XGai();//�༶�޸�
			break;
		case 6:
			CJ_XG();//�ɼ��޸�
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��!\n\n");
			break;
		}
	} while (a);
}

//�޸Ľ�ʦ����
void J_S_XG()
{
	system("cls");
	int a, i, nl;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("������ID>:");
			scanf("%d", &nl);
			L[i].Nian_Ling = nl;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸Ľ�ʦID
void JS_ID_XG()
{
	system("cls");
	int a, i, id;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (S[i].ID == a)
		{
			printf("������ID>:");
			scanf("%d", &id);
			S[i].ID = id;
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸Ľ�ʦ�Ա�
void JS_XB_XG()
{
	system("cls");
	int a, i;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("�������Ա�>:");
			gets_s(L[i].sex);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}

//�޸Ľ�ʦ����
void JS_XM_XG()
{
	system("cls");
	int a, i;
	printf("������ID>:");
	scanf("%d", &a);
	printf("\n");
	printf("--------------------------------------");
	printf("\n");
	for (i = 0; i < 3; i++)
	{
		if (L[i].ID == a)
		{
			printf("�������Ա�>:");
			gets_s(L[i].name);
			return;
		}
		else
		{
			printf("��IDδ¼�룡\n\n");
			return;
		}
	}
}



//�����޸Ľ�ʦ
void DD_J_S()
{

	int a;
	do
	{
		system("cls");
		printf("*******************************************\n");
		printf("***             ��ʦ�޸�ϵͳ            ***\n");
		printf("***     1.�޸�����      2.�޸�����      ***\n");
		printf("***     3.�޸��Ա�      4.�޸�ID        ***\n");
		printf("***             0.������һ��            ***\n");
		printf("*******************************************\n");
		printf("��ѡ��>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			JS_XM_XG();
			break;
		case 2:
			J_S_XG();//�޸Ľ�ʦ����
			break;
		case 3:
			JS_XB_XG();
			break;
		case 4:
			JS_ID_XG();//��ʦID�޸�
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n\n");
			break;
		}
	} while (a);
}

//����¼����޸�ϵͳ
void DL_XG()
{
	int a;
	do
	{
		system("cls");
		printf("**************************************************\n");
		printf("***             ����¼�뼰�޸�ϵͳ            ****\n");
		printf("***   1.�����޸İ༶     2.�����޸�ѧ����Ϣ    ***\n");
		printf("***   3.�����޸Ľ�ʦ��Ϣ   0.������һ��        ***\n");
		printf("**************************************************\n");
		printf("��ѡ��>:");
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
			printf("ѡ�����������ѡ��\n\n");
			break;
		}
	} while (a);
}

void XS_Lu_Ru()
{
	//1.¼��ѧ����Ϣ 2.¼���ʦ��Ϣ 3.¼��༶��Ϣ 4.����¼��ϵͳ���޸�
	int a;
	do
	{
		system("cls");
		XX_CD();
		printf("��ѡ��>:");
		scanf("%d", &a);
		putchar('\n');
		switch (a)
		{
		case 1:
			XX_Xue_Shen();//ѧ����Ϣ
			return;
		case 2:
			XX_Jiao_Shi();//��ʦ��Ϣ
			break;
		case 3:
			XX_Ban_Ji();//�༶��Ϣ
			break;
		case 4:
			DL_XG();//����¼����޸�
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (a);
	
}

//���г�ʼ��
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

//��ѯ����ѧ����Ϣ
void CX_XS_GR()
{
	
	int a,i;
	printf("������ID��ѯ>:");
	scanf("%d", &a);
	for (i = 0; i < 30; i++)
	{
		if (S[i].ID == a)
		{
			printf("ID>:%d\n����>:%s\n�Ա�>:%s\n����>:%d\n�ɼ�>:%.2f\n�༶>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
			return;
		}
		else
		{
			printf("û�ҵ���ID��\n\n");
			return;
		}
	}
}

//��ѯ����ѧ����Ϣ
void CX_XS_ALL()
{
	
	system("cls");
	int i;
	for (i = 0; i < 30; i++)
	{
		if (Xu_Lie[i] != -1)
		{
		printf("ID>:%d\n����>:%s\n�Ա�>:%s\n����>:%d\n�ɼ�>:%.2f\n�༶>:%s\n", S[i].ID, S[i].name, S[i].sex, S[i].Nian_Ling, S[i].Cheng_Ji, S[i].Ban_Ji);
		
		}
	}
}


//ѧ����Ϣ��ѯ
void CX_XS_XX()
{
	system("cls");
	int a;
	do
	{
		
		printf("************************************************\n");
		printf("***                 �鿴ѧ����Ϣ             ***\n");
		printf("***         1.�鿴����ѧ����Ϣ               ***\n");
		printf("***         2.�鿴������Ϣ    0.������һ��   ***\n");
		printf("************************************************\n");
		printf("������>:");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (a);
}


//��ѯ��ʦ��Ϣ
void CX_JS_XX()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if(LS_Xu_Lie[i]!=-1)

		printf("ID>:%d\n����>:%s\n����>:%d\n�Ա�>:%s\n\n\n",L[i].ID,L[i].name,L[i].Nian_Ling,L[i].sex);

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
			printf("�༶ID>:%d\n�༶����>:%s\n������>:%s\n�༶����>:%d\n\n\n", B[i].Ban_Ji_ID, B[i].BJ_nema, B[i].BZR_name, B[i].Ren_Shu);
		}
	}


}

void CX_ALL()
{

	int a;
	do
	{
		printf("******************************************************\n");
		printf("***                    ��ѯϵͳ                    ***\n");
		printf("***      1.ѧ����Ϣ�鿴       2.��ʦ��Ϣ�鿴       ***\n");
		printf("***      3.�༶��Ϣ�鿴       0.������һ��         ***\n");
		printf("******************************************************\n");
		printf("��ѡ��>:");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			CX_XS_XX();//ѧ����ѯ
			break;
		case 2:
			CX_JS_XX();//��ʦ��Ϣ
			break;
		case 3:
			B_JXX_CX();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}while(a);
}

//��ʼ���
void Ru_Kou()
{
	int a;
	do
	{
		system("cls");
		Cai_Dan();
		printf("��ѡ��>:");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (a);
}

int main()
{
	//��ʼ�����к�
	XLH();
	LSxlh();
	BJxlh();
	//1.�˵����棺�˳����򡢵Ǽǳ��򡢲鿴����
	//2.�Ǽǳ��򣺿��޸ģ��ɸ��Ǳ�ռ�ù������͡�
	//3.�鿴���򣺲��ɱ��޸ģ�ֻ�ܱ��鿴,�˳��鿴����.
	//�ѵǼǽ����װ�ɺ�������������Ҳ��װ�ɺ�����������ú��޸ġ�
	Ru_Kou();//���1


	return 0;
}