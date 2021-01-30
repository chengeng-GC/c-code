#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int check() {
	int a = 1;
	char* p = (char*)&a;
	return *p;
}

int main() {
	/*C语言类型 
	1.内置类型 
	char short int long float double 
	2.自定义类型


	字节序大端小端：
    大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中
	小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位，保存在内存的高地址中
	为什么会有大小端模式之分呢？
	这是因为在计算机系统中，我们是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8bit。
	但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long型（要看具体的编译器）
	另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如果将多个字节安排的问题
	因此就导致了大端存储模式和小端存储模式。

	例如一个16bit的short型x，在内存中的地址为0×0010，x的值为0×1122
	那么0×11为高字节，0×22为低字节。
	对于大端模式，就将0x11放在低地址中，即0×0010中，0×22放在高地址中，即0×0011中。
	小端模式，刚好相反。我们常用的×86结构是小端模式，而kEIL C51则为大端模式。
	很多的ARM，DSP都为小端模式。
	有些ARM处理器还可以由硬件来选择是大端模式还是小端模式。
	
	*/

	//代码测试当前机器的字节序是什么
	int ret = check();
	if (ret == 1) {
		printf("小端");
	}
	else
	{
		printf("大端");
	}

		return 0;
}