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
	//��ά����-���������Ϣ
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж���ӮC������*���Ӯ��#����Ӯ��Qƽ��
		ret=IsWin(board, ROW, COL);
		if (ret!='C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	else if (ret=='#')
	{
		printf("����Ӯ\n");
	}
	else if (ret=='Q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������\n");
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
	//����
	//����Ĵ�������Ҫ��һ���������У���������
	//������Ԫ�ص�������ͳһ��

	//���������
	test();


	return 0;
}