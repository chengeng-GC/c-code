#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int Add(int, int);//声明外部函数
//正常定义函数
int Max(int x, int y) {
	if (x>y)
	{
		return x;
	}
	else
	{
		return y;
	}

}
//宏的定义,宏的使用方式和函数一样
#define MAX(X,Y)(X>Y?X:Y)
int main() {
//常见关键字
	//auto 局部变量前都有，可以省略，代表自动创建自动销毁
	//register  建议把变量定义成寄存器变量
	//寄存器优先级最高，速度最快，总空间小
	register int a = 10;
	//int 定义的变量是有符号的
	//signed int 是全写，sighed（有符号的）可以省略
	//unsigned 无符号的
	//struct 结构体关键字
	//union联合体/共用体关键字

	//typedef类型定义-类型重定义
	typedef unsigned int xxx;
	xxx i = 10;//等于 unsigned int i=10

	//extern-声明外部全局变量，函数
	extern int xx;//全局变量不能是静态的
	extern int Add(int x, int y);
	
	//取地址
	int a = 10;
	printf("%p\n", &a);
	//有一种变量是用来存放地址的-指针变量
	int* p = &a;
	//解引用操作符
	*p = 20;
	//指针大小在32位平台4个字节，64位平台是8个字节
	return 0;
}
