#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EASY_COUNT 10  //�׵ĸ���

#define ROW 9          //��ʾ���̵���
#define COL 9          //��ʾ���̵���

#define ROWS ROW+2     //����ʵ�ʵ���
#define COLS COL+2     //����ʵ�ʵ���

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void  DisplayBoard(char board[ROWS][COLS], int row, int col);

//������

void SetMine(char mine[ROWS][COLS], int row, int col, int count);

//����
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
