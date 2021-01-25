#pragma once
#define COL 3
#define ROW 3
#include<stdio.h>

void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Wan_Jia(char board[ROW][COL], int row, int col);
void Dian_Nao(char board[ROW][COL],int row,int col);
char Pan_Duan1(char board[ROW][COL],int row,int  col);
int Pan_Duan(char board[ROW][COL], int row, int col);