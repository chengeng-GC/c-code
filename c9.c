#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "game2.h"

void game() {
	//�׵���Ϣ�洢
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS] = {0};
	//��ʼ����Ϣ
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ��Ϣ
	//DisplayBoard(mine,ROW,COL);
	//DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//ɨ��
	FindMine(mine,show, ROW, COL);
}

//ɨ����Ϸ
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ��\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��!\n");
			break;
		}
	} while (input!=0);
}

int main() {
	test();
	return 0;
}