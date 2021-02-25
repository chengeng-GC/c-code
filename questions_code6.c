#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>

int main() {
	//题目名称：
	//杨辉三角
	//题目内容：
	//在屏幕上打印杨辉三角。
	//1
	//11
	//121
	//1331
	//14641

	int arr[10][10] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i==j)
			{
				arr[i][j] = 1;
			}
			if (i>=2&&j>=1)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	//打印
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
	}

	//题目名称：
	//猜凶手
	//题目内容：
	//日本某地发生了一件谋杀案，I警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
	//以下为4个嫌疑犯的供词：
	//A说：不是我。t
	//B说：是C.t
	//C说：是D.f
	//D说：C在胡说t已知3个人说了真话，1个人说的是假话。
	//现在请根据这些信息，写一个程序来确定到底谁是凶手。
	int killer = 0;
	for (killer = 'a'; killer < 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == "d") + (killer != 'd') == 3)
		{
			//printf("killer is %c\n", killer);
		}
	}

	return 0;
}