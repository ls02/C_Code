#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COL 9
#define ROW 9
#define COLS COL+2
#define ROWS ROW+2
#define DIFFICULTY 10

//游戏主体声明
void game();

//初始化棋盘
void Initialize_board(char board[ROWS][COLS], int row, int col, char val);

//打印棋盘
void exhibit_board(char board[ROWS][COLS], int row, int col);

//布置雷
void assign_mine(char mine[ROWS][COLS], int row, int col);

//判断是否是雷
void determine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);