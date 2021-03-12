#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EASY_COUNT 10  //雷的个数

#define ROW 9          //显示棋盘的行
#define COL 9          //显示棋盘的列

#define ROWS ROW+2     //棋盘实际的行
#define COLS COL+2     //棋盘实际的列

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void  DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷

void SetMine(char mine[ROWS][COLS], int row, int col, int count);

//排雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
