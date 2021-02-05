#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int FindNum(int arr[3][3], int k, int *px, int *py) {
	int x = 0;
	int y = *py - 1;
	while (y >= 0&&x<=*px-1)
	{
		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
	
}

int main() {
	char str1[30] = "abc";
	char str2[30] = "def";
	char str3[30] = "abc";
	//在str1字符串中追加一个str2字符串
	//用strcat
	strcat(str1, str2);
	printf("%s\n", str1);
	//在str3字符串中追加一个str3字符串
	//strcat(str3, str3);err
	//用strcat不行，要用strncat
	strncat(str3, str3,3);
	printf("%s\n",str3);
	//判断str2字符串是否是str1字符串的子串
	//strstr-找子串的
	char * ret1 = strstr(str1,str2);
	if (ret1 == NULL) {
		printf("不是\n");
	}
	else
	{
		printf("是\n");
	}

	//杨氏矩阵
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的。
	//请编写程序在这样的矩阵中查找某个数字是否存在,若存在，给出下标
	//要求时间复杂度小于0(N)
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	//返回型参数
	int ret2 = FindNum(arr,k,&x,&y);
	if (ret2==1)
	{
		printf("找到了,下标为%d,%d\n",x,y);
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}