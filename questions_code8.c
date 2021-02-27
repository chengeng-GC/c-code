#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
int if_same(char* arr1, char* arr2) {
	int len = strlen(arr1);
	for (int i = 0; i < len; i++)
	{
		char a = *arr1;
		int j = 0;
		for (j=0;j<len-1;j++)
		{
			*(arr1 + j) = *(arr1 + j + 1);
		}
		*(arr1 + j) = a;
		if (strcmp(arr1,arr2)==0) {
			return 1;
		}
		}
	return 0;
}

int FindNum(int arr[3][3], int k, int row, int col) {
	int x = 0;
	int y = col - 1;
	while (x<=row-1&&y>=0) {
		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k) {
			x++;
		}
		else {
			return 1;
		}

	}


	return 0;
}
int main() {
	//题目名称：
	//字符串旋转结果
	//题目内容：
	//写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串
	//例如：给定s1 = AABCD和s2 = BCDAA，返回1
	//		给定s1 = abcd和S2 = ACBD，返回0.
	//AABCD左旋一个字符得到ABCDA
	//AABCD左旋两个字符得到BCDAA
	//AABCD右旋一个字符得到DAABC
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	char s3[] = "abcd";
	char s4[] = "ACBD";
	int ret1 = if_same(s1, s2);
	int ret2 = if_same(s3, s4);
	//printf("%d %d\n", ret1, ret2);


	//题目名称：
	//杨氏矩阵
	//题目内容：
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
	//要求：时间复杂度小于O（N)

	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 1;
	int ret = FindNum(arr, k, 3, 3);
	//printf("%d\n", ret);

	return 0;
}