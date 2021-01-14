/*��Ȱ׿��
1����ʼ��Ϸ������Ϸ����
2�����ư�ɫ���鱳��
3����ʼ����ͼ����ʼ����ɫ�����λ��
4������Ϸ���������ȷ�ĺڷ��飬�����з�������
5���ж���Ϸʧ�ܣ�������һ�кڷ��������Ϸ���������������Ϸ����
6�����Ӿ�̬���ֿ⣬�����֣��������֣��ر�����
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <stdio.h>
#include <easyx.h>	//ͼ�ο�ͷ�ļ�
#include <time.h>	//ʱ�亯��ͷ�ļ�
#include <tchar.h>	//���ֽ��ַ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")	//���Ӿ�̬���ֿ�

int map[4];	//��ͼ���飺�洢��ɫ�����λ��
int n;	//��¼�������ĺ�ɫ��������

void init()	//��ʼ����ͼ��������ʼ����ɫ����λ��
{
	for (int i = 0; i < 4; i++)
	{
		map[i] = rand() % 4;
		//rand����ȡ�������%4�����������ȡֵ��Χ��0��1��2��3֮��
	}
	n = 0;	//��ʼ���ڷ�����������������Ϸ��ʼʱĬ������0��
}

void drawmap()	//���Ƶ�ͼ����
{
	BeginBatchDraw();	//��ʼ������ͼ

	/*���ư�ɫ���鱳��*/
	setlinecolor(BLUE);	//����������ɫΪ��ɫ
	setfillcolor(RGB(255, 255, 255));	//���������ɫΪ��ɫ

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			//�������Σ����Ͻ�x���꣬���Ͻ�y���꣬���½�x���꣬���½�y���꣩
			fillrectangle(x * 100, y * 120, (x + 1) * 100, (y + 1) * 120);
		}
	}

	/*���ƺ�ɫ����*/
	setfillcolor(RGB(0, 0, 0));	//���������ɫΪ��ɫ
	for (int i = 0; i < 4; i++)
	{
		//�������Σ����Ͻ�x���꣬���Ͻ�y���꣬���½�x���꣬���½�y���꣩
		fillrectangle(map[i] * 100, i * 120, (map[i] + 1) * 100, (i + 1) * 120);
	}

	EndBatchDraw();	//����������ͼ
}

int i;	//���������ͼ�δ��ڽ����x����
int j;	//���������ͼ�δ��ڽ����y����

bool play()	//����Ϸ����
{//bool��C++�������������ͣ���ֻ������ֵ��һ��Ϊtrue(��,��0),,��һ����false(��,0)

	MOUSEMSG msg = GetMouseMsg();	//����һ�������Ϣ����msg����ȡ��ǰ�����Ϣ
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:	//�������������
		i = msg.y / 120;	//��ȡ��ά��ͼ����
		j = msg.x / 100;	//��ȡ��ά��ͼ����

		if (3 == i && map[3] == j)
		{//�ж���������Ƿ������һ�еĺ�ɫ����
			for (int m = 3; m > 0; m--)
			{
				//�����������һ�еĺ�ɫ���飬ǰ���еĺ�ɫ�����λ�����ƣ��������һ��
				map[m] = map[m - 1];
			}
			map[0] = rand() % 4;	//���������һ�к�ɫ�����λ��
			n++;	//������ɫ���������+1
		}
		else
			return false;	//�㵽���󷽿鷵�ؼ٣���Ϸʧ��
		break;
	}
	return true;	//�㵽��ȷ�ĺ�ɫ���鷵���棬��Ϸ����
}

void start()	//��ʼ��������׼������
{
	initgraph(4 * 100, 4 * 120);

	srand((unsigned)time(NULL));
	//srand��������ӣ���time()��ǰʱ��Ϊ����������仯
	//��ʹ��������ӵ��������rand��α�����ֻ�����һ�β���һ�������

	mciSendString(L"open JustBlue.mp3", 0, 0, 0);	//�������ļ�
	mciSendString(L"play JustBlue.mp3", 0, 0, 0);	//��������

	init();	//��ʼ����ͼ

	while (1)
	{
		drawmap();	//���Ƶ�ͼ����

		if (false == play())
		{
			TCHAR str[60];	//TCHARΪ���ֽ��ַ����ͣ�Ҳ���ǵ����ַ���һ�㣬�������ڴ洢����

			//������Ϸ�������ı���Ϣ
			swprintf(str, _T("�ܹ�������%d����ɫ���飡"), n);

			mciSendString(L"close JustBlue.mp3", 0, 0, 0);	//�ر�����

			//��һ����������ʾ�����Ϣ����ȡ���ھ��������ַ��������������ڱ��⣬MB_OKΪȷ�ϰ�ť��
			MessageBox(GetHWnd(), str, _T("��Ϸ����"), MB_OK);

			break;
		}
	}
	//getchar();
	closegraph();
	return;
}

int main()
{
	start();	//��ʼ����


	//getchar();
	return 0;
}