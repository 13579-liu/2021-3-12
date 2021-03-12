#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化棋盘
void  InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j]=set;
		}
	}
}

//打印棋盘
void  DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------  扫雷游戏   --------------\n");
	for (i = 0; i <= col; i++)   //打印列标
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);       //打印行标
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------  扫雷游戏   --------------\n");
}
//布置雷的个数
void SetMine(char mine[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		//1-9
		int x = rand() % row + 1;//确保随机生成的雷在棋盘内
		int y = rand() % col + 1;//确保随机生成的雷在棋盘内
		if (mine[x][y]== '0')
		{
			//x,y坐标处没有雷
			mine[x][y] = '1';
			count--;
		}
	}
}

//统计周围雷的个数
int GetMineCont(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] +
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}
//排雷
void FineMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	//9*9-10=71
	while (win<=row*col-EASY_COUNT)
	{
		printf("请输入要排查的坐标:>");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		//1.坐标合法性
		//2.该坐标处是不是雷？不是雷，统计周围雷的个数
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//2. 该坐标处是不是雷，不是雷，统计周围雷的个数
				int count = GetMineCont(mine, x, y);
				show[x][y] = count + '0';//存放的是数字字符
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}