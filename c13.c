#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//void(*)()- 函数指针类型
//下面代码将0强制转换为函数指针类型，并解地址调用该地址的函数
//(*(void(*)())0)();
//函数名是signal，形参是一个int 和一个函数指针（形参是int）  ，返回值是一个函数指针（形参是int）
void(*signal(int, void(*)(int)))(int);

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
	//arr是一个5个元素的整形数组
	//parr1是一个数组，数组有10个元素，每个元素的类型是int*,parr1是指针数组
	//parr2是一个指针，该指针指向了一个数组，数组有10个元素，每个元素的类型是int-parr2是数组指针
	//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针该数组指针指向的数组有5个元素，每个元素是int
	int arr[5];
	int *parr1[10];
	int(*parr2)[10];
	int(*parr3[10])[5];

	//二维数组传参，函数形参的设计只能省略第一个[]
	//因为一个二维数组，可以不知道有多少行，但是必须知道一行多少元素
	 
	//简化函数指针
	//重定义函数指针
	typedef void(*xxx)(int);
	//和上面void(*signal(int, void(*)(int)))(int)同理，但是简化了
	xxx signal(int, xxx);


	//函数指针的数组
	int(*parr4[4])(int, int) = { Add,Sub,Mul,Div };
	//使用
	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		printf("%d\n",parr4[i](2,3));
	}

	return 0;
}


