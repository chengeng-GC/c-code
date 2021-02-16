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
//动态版通讯录
int main() {
	int input = 0;
	//创建通讯录,里面包含data指针和size,capacity
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do {
		menu();
		printf("请选择：\n");
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
		case MODIFY://修改
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT://排序
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			//销毁通讯录-释放动态开辟的内存
			SaveContact(&con);
			DestroyContact(&con);
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input != 0);
	return 0;
}

