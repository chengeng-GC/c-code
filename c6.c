#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//��������Ϸ
//1.��������һ������� rand()��srand()+time() ����stdlib.h
//2.������
//3.���׽��ܺͽ���
int main() {
	srand((unsigned int)time(NULL));//�����������,��ʱ���������
	//ʱ���:time��������Ҫtime.h,�в���,����������long,Ҫǿת
	int i = 0;
	do
	{
		menu();
		printf("��ѡ��");
		 i = getchar();
		switch (i)
		{
		case 1:
			break;
			game();
		case 0:
			break;
		default:
			printf("������Ч\n");
			printf("��������¿�ʼ\n");
			Sleep(2000);
			break;
		}
	} while (i!=0);
	return 0;
}

void menu() {
	printf("*******************************\n");
	printf("*****   1.play   0.exit   *****\n");
	printf("*******************************\n");
}

void game() {
	int random = rand();//ÿһ����Ϸ������������ǹ̶��ģ�Ҫ������
	printf("����������ɣ���Ϸ��ʼ\n");
	int guess = 0;
	printf("���������֣�");
	while (guess!=random)
	{
		 guess = scanf("%d", guess);
		if (guess<random)
		{
			printf("��С�ˣ��������");
		}
		else
		{
			printf("�´��ˣ��������");
		}
	}
	printf("��ϲ�㣬�¶��ˣ�����");
}
