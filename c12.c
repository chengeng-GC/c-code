#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//指针类型的意义：
//1.指针类型决定了指针解引用操作符能访问几个字节：
//char - p； * p访问了1个字节，int - p；"p访问4个字节
//2.指针类型决定了指针 + 1， - 1，加的或者减的是几个字节；
//char*p；p + 1，跳过一个字符，int*p；p + 1，跳过一个整形 - 4个字节

void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0;i < x;i++)
	{
		int j = 0;
			for (j = 0;j < y;j++)
			{
				//printf("%d",*(*(p+i)+j));
				printf("%d ", (*(p + i))[j]);
			
			}
			printf("\n");
	}
}
int main() {
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	//输出为 -1,-1,255
	printf("%d,%d,%d\n",a, b, c);
	//指针数组是指针
	//获取指针数组地址
	char* arr[5];
	char* (*pa)[5] = &arr;
	printf("%c\n", (*pa[0]));
	int arr2[10] = { 0 };
	int(*pb)[10] = &arr2;
	printf("%d\n", (*pb)[0]);
	//通过指针遍历二维数组
	int arr3[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print2(arr3, 3, 5);//arr-数组名-数组名就是首元素地址


	return 0;
}