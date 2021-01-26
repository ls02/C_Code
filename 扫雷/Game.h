#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COL 9
#define ROW 9
#define COLS COL+2
#define ROWS ROW+2
#define DIFFICULTY 10

//��Ϸ��������
void game();

//��ʼ������
void Initialize_board(char board[ROWS][COLS], int row, int col, char val);

//��ӡ����
void exhibit_board(char board[ROWS][COLS], int row, int col);

//������
void assign_mine(char mine[ROWS][COLS], int row, int col);

//�ж��Ƿ�����
void determine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);