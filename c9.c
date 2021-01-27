#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game2.h"

void game() {
	//雷的信息存储
	//布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查出的雷的信息
	char show[ROWS][COLS] = {0};
	//初始化信息
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印信息
	//DisplayBoard(mine,ROW,COL);
	//DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//扫雷
	FindMine(mine,show, ROW, COL);
}

//扫雷游戏
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
			printf("扫雷\n");
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
	test();
	return 0;
}