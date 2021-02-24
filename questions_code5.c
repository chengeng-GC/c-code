#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>

void move1(int *arr,int sz) {
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		while ( *(arr + left) % 2 == 1) {
			left++;
		}
		while ( *(arr + right) % 2 == 0) {
			right--;
		}
		if (left<right)
		{
			int tmp = *(arr + left);
			*(arr + left)= *(arr + right);
			*(arr + right) = tmp;
		}
	}
}
int main() {
	//题目名称：
	//喝汽水问题
	//题目内容：
	//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
	int money = 0;
	//scanf("%d",&money);
	int soda = money;
	int full_soda = money;
	int empty_soda = 0;
	while (full_soda) {
	//喝
		while (full_soda > 0) {
			full_soda--;
			empty_soda++;
		}
	//换
		while (empty_soda >= 2) {
			empty_soda -= 2;
			full_soda++;
			soda++;
		}
	}
	//printf("给%d元一共能有%d瓶汽水\n",money,soda);


	//题目名称：
	//调整奇数偶数顺序
	//题目内容：
	//调整数组使奇数全部都位于偶数前面。
	int arr[] = { 1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	move1(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}