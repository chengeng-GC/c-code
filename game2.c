#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game2.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	
	int i = 0;
	int j = 0;
	for ( i = 0; i <= col; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count!=0) {	
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y) {
	return
	board[x - 1][y] +
	board[x - 1][y - 1] +
	board[x][y - 1] +
	board[x + 1][y - 1] +
	board[x + 1][y] +
	board[x + 1][y + 1] +
	board[x][y + 1] +
	board[x - 1][y + 1] - 8 * '0';

}
int IsWin(char board[ROWS][COLS],int row,int col) {
	int i = 0;
	int j = 0;
	int win = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j]=='*')
			{
				win++;
			}
		}
	}
	if (win==EASY_COUNT)
	{
		return 1;
	}
	return 0;

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (1) {
		printf("请输入排查雷的横坐标：");
		scanf("%d", &y);
		printf("请输入排查雷的竖坐标：");
		scanf("%d", &x);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//坐标合法
			//踩雷
			if (mine[x][y]=='1') {
				printf("很遗憾,你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else //不是雷
			{
				//计算坐标周围有几个雷
			int count =get_mine_count(mine,x,y);
			show[x][y] = count + '0';
			if (show[x][y]=='0')
			{
				show[x - 1][y] = get_mine_count(mine, x-1, y) + '0';
					show[x - 1][y - 1] = get_mine_count(mine, x-1, y-1) + '0'; 
					show[x][y - 1] = get_mine_count(mine, x, y-1) + '0';
					show[x + 1][y - 1] = get_mine_count(mine, x+1, y-1) + '0'; 
					show[x + 1][y] = get_mine_count(mine, x+1, y) + '0'; 
					show[x + 1][y + 1] = get_mine_count(mine, x+1, y+1) + '0'; 
					show[x][y + 1] = get_mine_count(mine, x, y+1) + '0'; 
					show[x - 1][y + 1] = get_mine_count(mine, x-1, y+1) + '0'; 
			}
			win =IsWin(show,ROW,COL);
			if (win==1)
			{
				printf("恭喜你，排雷成功\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			DisplayBoard(show, ROW, COL);
			
			}
		}
		else {
			printf("坐标非法，请重新输入\n");
			continue;
		}
	}
}