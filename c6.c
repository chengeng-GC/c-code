#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//猜数字游戏
//1.电脑生成一个随机数 rand()和srand()+time() 依赖stdlib.h
//2.猜数字
//3.简易介绍和界面
void menu() {
	printf("***********猜数字游戏**********\n");
	printf("*******************************\n");
	printf("*****   1.play   0.exit   *****\n");
	printf("*******************************\n");
}

void game() {
	int random = rand();//每一次游戏产生的随机数是固定的，要加设置
	printf("随机数已生成，游戏开始\n");
	int guess = 0;
	printf("请输入数字：");
	while (random != guess)
	{
	
		scanf("%d", &guess);
		if (guess < random)
		{
			printf("猜小了，请继续：");
		}
		else if(guess>random)
		{
			printf("猜大了，请继续：");
		}
	}
	printf("恭喜你，猜对了！！！\n");
}

int main() {
	srand((unsigned int)time(NULL));//设置随机函数,拿时间戳来设置
	//时间戳:time函数，需要time.h,有参数,返回类型是long,要强转
	int i = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入无效\n");
			printf("两秒后重新开始\n");
			Sleep(2000);
			break;
		}
	} while (i!=0);
	return 0;
}


