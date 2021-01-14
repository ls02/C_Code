/*别踩白块儿
1、开始游戏：打开游戏窗口
2、绘制白色方块背景
3、初始化地图：初始化黑色方块的位置
4、玩游戏：鼠标点击正确的黑方块，上三行方块下移
5、判断游戏失败：点击最后一行黑方块进行游戏，点击其他方块游戏结束
6、连接静态音乐库，打开音乐，播放音乐，关闭音乐
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <stdio.h>
#include <easyx.h>	//图形库头文件
#include <time.h>	//时间函数头文件
#include <tchar.h>	//宽字节字符头文件
#pragma comment(lib,"winmm.lib")	//连接静态音乐库

int map[4];	//地图数组：存储黑色方块的位置
int n;	//记录所消除的黑色方块数量

void init()	//初始化地图函数：初始化黑色方块位置
{
	for (int i = 0; i < 4; i++)
	{
		map[i] = rand() % 4;
		//rand函数取随机数，%4限制随机数的取值范围在0、1、2、3之间
	}
	n = 0;	//初始化黑方块消除的数量，游戏开始时默认消除0个
}

void drawmap()	//绘制地图函数
{
	BeginBatchDraw();	//开始批量绘图

	/*绘制白色方块背景*/
	setlinecolor(BLUE);	//设置线条颜色为蓝色
	setfillcolor(RGB(255, 255, 255));	//设置填充颜色为白色

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			//画填充矩形（左上角x坐标，左上角y坐标，右下角x坐标，右下角y坐标）
			fillrectangle(x * 100, y * 120, (x + 1) * 100, (y + 1) * 120);
		}
	}

	/*绘制黑色方块*/
	setfillcolor(RGB(0, 0, 0));	//设置填充颜色为黑色
	for (int i = 0; i < 4; i++)
	{
		//画填充矩形（左上角x坐标，左上角y坐标，右下角x坐标，右下角y坐标）
		fillrectangle(map[i] * 100, i * 120, (map[i] + 1) * 100, (i + 1) * 120);
	}

	EndBatchDraw();	//结束批量绘图
}

int i;	//代表鼠标点击图形窗口界面的x坐标
int j;	//代表鼠标点击图形窗口界面的y坐标

bool play()	//玩游戏函数
{//bool是C++的新增数据类型，其只有两个值，一个为true(真,非0),,另一个是false(假,0)

	MOUSEMSG msg = GetMouseMsg();	//定义一个鼠标信息变量msg，获取当前鼠标消息
	switch (msg.uMsg)
	{
	case WM_LBUTTONDOWN:	//如果鼠标左键按下
		i = msg.y / 120;	//获取二维地图的行
		j = msg.x / 100;	//获取二维地图的列

		if (3 == i && map[3] == j)
		{//判断鼠标点击的是否是最后一行的黑色方块
			for (int m = 3; m > 0; m--)
			{
				//如果点击了最后一行的黑色方块，前几行的黑色方块的位置下移，覆盖最后一行
				map[m] = map[m - 1];
			}
			map[0] = rand() % 4;	//随机给定第一行黑色方块的位置
			n++;	//消除黑色方块的数量+1
		}
		else
			return false;	//点到错误方块返回假，游戏失败
		break;
	}
	return true;	//点到正确的黑色方块返回真，游戏继续
}

void start()	//开始函数：做准备工作
{
	initgraph(4 * 100, 4 * 120);

	srand((unsigned)time(NULL));
	//srand随机数种子：以time()当前时间为基数，随机变化
	//不使用随机种子的随机函数rand是伪随机：只随机第一次产生一次随机数

	mciSendString(L"open JustBlue.mp3", 0, 0, 0);	//打开音乐文件
	mciSendString(L"play JustBlue.mp3", 0, 0, 0);	//播放音乐

	init();	//初始化地图

	while (1)
	{
		drawmap();	//绘制地图函数

		if (false == play())
		{
			TCHAR str[60];	//TCHAR为宽字节字符类型，也就是单个字符宽一点，可以用于存储汉字

			//保存游戏结束的文本信息
			swprintf(str, _T("总共消除了%d个黑色方块！"), n);

			mciSendString(L"close JustBlue.mp3", 0, 0, 0);	//关闭音乐

			//打开一个弹窗，提示相关信息（获取窗口句柄，输出字符串到弹窗，窗口标题，MB_OK为确认按钮）
			MessageBox(GetHWnd(), str, _T("游戏结束"), MB_OK);

			break;
		}
	}
	//getchar();
	closegraph();
	return;
}

int main()
{
	start();	//开始函数


	//getchar();
	return 0;
}