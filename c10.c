#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int my_strlen(char str[])
{
	char* start = str;
	char* end = str;
	while (*end != '\0') {
		end++;
	}
	return end - start;

}
int main() {
	//   >>  右移操作符
	//移动的是二进制位
	int a = 16;
	int b = a >> 1;
	//右移操作符
	/*1.算数右移
		右边丢弃，左边补原符号位
	2.逻辑右移
		右边丢弃，左边补0*/

	//指针 可以理解为地址
	//指针类型
	//决定了指针进行解引用操作的时候能够访问空间的大小
	//决定了指针走一步走多远（步长）
	char* pa = NULL;
	int* pb = NULL;

	//野指针  指针指向的位置是不可知的（随机的，不正确的，没有明确限制的）
	//成因1.指针未初始化
	int* pc;
	//成因2.指针越界访问
	//当指针指向的范围超出数组的范围时，就是野指针
	/*规避野指针
	1.指针初始化
	2.小心指针越界
	3.指针指向空间释放即使是NULL
	4.指针使用之前检查有效性*/

	//指针运算
	//指针+-整数
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int* pd = arr1;
	for (int i = 0; i < sz; i++)
	{
		printf("%d\n",*pd);
		//指针+1，数组往后一位，-1，往前一位
		pd = pd + 1;//pd++也一样
	}

	//指针模拟strlen
	char arr2[] = "bit";
	int len = my_strlen(arr2);
	printf("%d\n", len);
	//标准规定：
	//允许指向数组指针与指向数组最后一个元素后面那个内存位置的指针比较
	//不允许与指向第一个元素之前的内存位置指针进行比较

	//ppe是二级指针，e的地址存放在一级指针pe中，pe的地址存在ppe中
	int e = 10;
	int* pe = e;
	int** ppe = pe;
	//指针数组
	int* arr3[3];
	return 0;
}