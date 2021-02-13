#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASILY 10//雷的数量

//初始化
void initzeboard(char mine[ROWS][COLS], int rows, int cols, char val);

//显示棋盘
void Display_board(char mine[ROWS][COLS], int row, int col);

//埋雷
void random_mine(char mine[ROWS][COLS], int row, int col);

//扫雷
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);