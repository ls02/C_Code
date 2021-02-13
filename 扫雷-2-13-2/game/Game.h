#pragma once
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASILY 10//�׵�����

//��ʼ��
void initzeboard(char mine[ROWS][COLS], int rows, int cols, char val);

//��ʾ����
void Display_board(char mine[ROWS][COLS], int row, int col);

//����
void random_mine(char mine[ROWS][COLS], int row, int col);

//ɨ��
void mine_sweeping(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);