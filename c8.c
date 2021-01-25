#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game1.h"
void game()
{
	char ret = 0;
	//二维数组-存放棋盘信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢C继续，*玩家赢，#电脑赢，Q平局
		ret=IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret=='*')
	{
		printf("玩家赢\n");
	}
	else if (ret=='#')
	{
		printf("电脑赢\n");
	}
	else if (ret=='Q')
	{
		printf("平局\n");
	}
}

void menu() {
	printf("************************\n");
	printf("*****1.play  0.exit*****\n");
	printf("************************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	} while (input!=0);
}

int main() {
	//数组
	//数组的创建必须要给一个常量才行，变量不行
	//数组内元素的类型是统一的

	//三子棋测试
	test();


	return 0;
}