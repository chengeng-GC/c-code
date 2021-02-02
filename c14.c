#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



//函数指针数组的用途：转移表
//例子：计算器
void menu() {
	printf("**********************\n");
	printf("***1.add      2.sub***\n");
	printf("***3.mul      4.div***\n");
	printf("***     0.exit     ***\n");
	printf("**********************\n");
}
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}

int main() {
	int input = 0;
	int x = 0;
	int y = 0;
	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div};
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		if (input>=1&&input<=4)
		{
			printf("请输入两个数字");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input==0)
		{
			break;
		}
		else {
			printf("选择错误\n");
		}
	
	
	} while (input != 0);


	return 0;
}
