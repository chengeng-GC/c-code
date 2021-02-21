#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
int count_bit_one1(unsigned int a) {
	int count = 0;
	while (a) {
		if (a % 2 == 1)
		{
			count++;
		}
		a = a / 2;
	}
	return count;
}
int count_bit_one2(int a) {
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a>>i)&1)==1)
		{
			count++;
		}
	}
	return count;
}
int count_bit_one3(int a) {

	int count = 0;
	while (a) {
		a = a & (a - 1);
		count++;
	}
	return count;
}
int get_diff_bit(int m, int n) {
	int count = 0;
	int a = m ^ n;
	while (a) {
		a = a & (a - 1);
		count++;
	}
	return count;
}
void print(int m) {
	int i = 0;
	printf("奇数位:");
	for ( i = 30; i >= 0; i-=2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("偶数位:");
	for ( i = 31; i >=1; i-=2)
	{
		printf("%d ", (m >> i) & 1);
	}
}
void print_arr(int *p, int sz) {
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d\n",*(p+i));
	}
}

int main() {

	//题目名称：
	//统计二进制中1的个数题目内容：
	//写一个函数返回参数二进制(补码)中1的个数。
	//比如：15  00001111  4个1
	//三种写法,3最精简
	int a = 0;
	//scanf("%d", &a);
	int count1 = count_bit_one1(a);
	int count2 = count_bit_one2(a);
	int count3 = count_bit_one3(a);
	//printf("（方法1）%d的二进制(补码)中有%d个1\n", a, count1);
	//printf("（方法2）%d的二进制(补码)中有%d个1\n", a, count2);
	//printf("（方法3）%d的二进制(补码)中有%d个1\n", a, count3);
	//题目名称：
	//求二进制中不同位的个数
	//题目内容：
	//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位（bit)不同？
	//输入例子：
	//1999 2299 输出例子：7
	int m = 0;
	int n = 0;
	//scanf("%d%d",&m,&n);
	count1 = get_diff_bit(m, n);
	//printf("%d和%d有%d个位（bit)不同\n",m,n,count1);



	//题目名称：
	//打印二进制的奇数位和偶数位
	//题目内容：
	//获取一个整数二进制序列中所有的偶数位和奇数位
	//分别打印出二进制序列
	
	//scanf("%d", &m);
	//print(m);
	


	//题目名称：
	//使用指针打印数组内容
	//题目内容：
	//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
	//arr是一个整形一维数组。
	int arr[] = { 1,2,3,4,6,7,5,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//print_arr(arr, sz);


	//题目名称：
	//交换两个变量（不创建临时变量）
	//题目内容：
	//不允许创建临时变量，交换两个整数的内容
	//scanf("%d%d",&m,&n);
	//printf("m=%d,n=%d\n",m,n);
	m = n + m;
	n = m - n;//n=m
	m = m - n;//m=n
	//或者
	//m=m^n;
	//n=m^m;
	//m=m^n;
	//printf("交换后:m = %d, n = %d\n",m, n);
	return 0;
}