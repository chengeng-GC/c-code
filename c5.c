#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
int main(){
//for循环的初始化，调整，判断都可以省略
//如果判断部分被省略，那判断条件恒为真
	for (;;) {
		printf("1");
		break;
	}
//数组长度
	int length = 0;
	int arr[] = { 1,2,3,4,5,6,7 };
	//用数组内存大小除以第一个元素的大小出个数
	length = sizeof(arr) / sizeof(arr[0]);


	//流动打印字符
	char arr1[] = "welcome to project!!!!";
	char arr2[] = "######################";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left<=right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		//延迟 需要windows.h
		Sleep(1000);
		//执行系统命令的函数cls-清空屏幕
		//需要stdlib.h
		system("cls");
		left++;
		right--; 
		//sqrt - 开平方的数学库函数,需要math.h
		
		sqrt(9);
		
	}

	return 0;
}


