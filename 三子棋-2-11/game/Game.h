#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 3
#define COL 3

//���̳�ʼ��
void Board_Initze(char board[ROW][COL], int row, int col);

//��ӡ����
void Display_Board(char board[ROW][COL], int row, int col);

//�������
void player(char board[ROW][COL], int row, int col);

//������
void automan(char board[ROW][COL], int row, int col);

//�ж���Ӯ
char judge(char board[ROW][COL], int row, int col);

//#�������
//*�������
//C�������
//Q����ƽ��