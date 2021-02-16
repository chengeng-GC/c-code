#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include "save_contact.h"

void menu() {
	printf("************************\n");
	printf("***1.add    2.del    ***\n");
	printf("***3.search 4.modify ***\n");
	printf("***5.show   6.sort   ***\n");
	printf("***7.save   0.exit   ***\n");
	printf("************************\n");
}
//��̬��ͨѶ¼
int main() {
	int input = 0;
	//����ͨѶ¼,�������dataָ���size,capacity
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do {
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY://�޸�
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT://����
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			//����ͨѶ¼-�ͷŶ�̬���ٵ��ڴ�
			SaveContact(&con);
			DestroyContact(&con);
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input != 0);
	return 0;
}

