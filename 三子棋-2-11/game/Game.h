#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 3
#define COL 3

//棋盘初始化
void Board_Initze(char board[ROW][COL], int row, int col);

//打印棋盘
void Display_Board(char board[ROW][COL], int row, int col);

//玩家下棋
void player(char board[ROW][COL], int row, int col);

//电脑人
void automan(char board[ROW][COL], int row, int col);

//判断输赢
char judge(char board[ROW][COL], int row, int col);

//#代表玩家
//*代表电脑
//C代表继续
//Q代表平局