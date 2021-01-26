#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game1.h"
//定义

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		//1.打印一行的数据
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j<col-1) {
				printf("|");
			}
		}
		printf("\n");
		//2.打印分割行
		if (i<row-1)
		{
			for ( j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
				
			}
			printf("\n");
		}
	}
}


void PlayerMove(char board[ROW][COL], int row, int col) {

	int x = 0;
	int y = 0;
	printf("玩家走：\n");

	while (1) {
		printf("请输入要下的横坐标:");
		scanf("%d", &y);
		printf("请输入要下的竖坐标:");
		scanf("%d", &x);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用,请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			continue;
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1) {
		x = rand() % row+1;
		y = rand() % col+1;
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
		}
	}
}
//返回1表示棋盘满了，0没满
int IsFull(char board[ROW][COL],int row,int col) {
	int i = 0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			if (board[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;

}

char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;
	//横三行
	for ( i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&& board[i][1] == board[i][2]&& board[i][1]!=' ')
		{
			return board[i][0];
		}
	}
	//竖三行
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	//斜
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}

	//都没有，游戏继续
	return 'C';

}