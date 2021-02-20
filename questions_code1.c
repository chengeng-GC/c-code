#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
void init(int arr[], int sz) {
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}

}

void print(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n",arr[i]);
	}
}
void Reverse(int arr[], int sz) {
	int i = 0;
	int j = 0;
	for ( i = 0; i < sz/2; i++)
	{
		j = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = j;
	}
}


int main(){
	//题目名称：
	//数组操作
	//题目内容：
	//创建一个整形数组，完成对数组的操作
	//1.实现函数init（）初始化数组为全0
	//2.实现print（）打印数组的每个元素
	//3.实现reverse（）函数完成数组元素的逆置。
	//要求；自己设计以上函数的参数，返回值。
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr,sz);
	print(arr,sz);
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
	Reverse(arr, sz);
	print(arr, sz);


	//题目名称：
	//交换数组
	//题目内容：
	//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 3,6,23,6,7 };
	sz = sizeof(arr1) / sizeof(arr1[0]);
	int j = 0;
	i = 0;
	for ( i = 0; i < sz; i++)
	{
		j = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = j;
		printf("%d\n", arr1[i]);
	}
	

	return 0;
}