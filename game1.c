#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game1.h"
//����

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
		//1.��ӡһ�е�����
		int j = 0;
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j<col-1) {
				printf("|");
			}
		}
		printf("\n");
		//2.��ӡ�ָ���
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
	printf("����ߣ�\n");

	while (1) {
		printf("������Ҫ�µĺ�����:");
		scanf("%d", &y);
		printf("������Ҫ�µ�������:");
		scanf("%d", &x);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��,����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
			continue;
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
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
//����1��ʾ�������ˣ�0û��
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
	//������
	for ( i = 0; i < row; i++)
	{
		if (board[i][0]==board[i][1]&& board[i][1] == board[i][2]&& board[i][1]!=' ')
		{
			return board[i][0];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[0][i];
		}
	}
	//б
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}

	//��û�У���Ϸ����
	return 'C';

}