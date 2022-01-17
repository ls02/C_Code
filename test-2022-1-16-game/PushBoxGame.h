#pragma once
#include <stdio.h>
#include <Windows.h>

#define ROW 10
#define COL 10

extern void Game();

extern void DisplayBoard(int board[ROW][COL]);

extern void MovePlayer(int board[ROW][COL]);

extern void PushBox(int board[ROW][COL], int y, int x, char ch);

extern void MovePlay(int board[ROW][COL], int y, int x);

extern int JudgeVictory(int board[ROW][COL]);