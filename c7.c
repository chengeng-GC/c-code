#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//函数声明,一般写在.h头文件中,函数的定义写在.c文件中
void Swap(int* pa, int* pb);

int main() {
	//goto语句,一次跳出两层或多层循环，有破坏性，不建议使用
again:
	printf("死循环\n");
	//goto again;

	//比较两个字符串-strcmp,返回0为相等
	char input[20] = { 0 };
	scanf("%s",input);
	printf("%d\n",strcmp(input,"比较字符串"));

	//一些库函数
	//strcpy(目标，拷贝源) 需string.h
	//memset  -内存设置
	char arr[] = "hello world";
	memset(arr, '*', 5);
	printf("%s\n", arr);

	//利用指针做到引用函数改变当前函数中的变量的值
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	printf("a=%d\nb=%d\n", a, b);

	return 0;
}


//传址调用
//函数接收参数为指针，可以直接改变a和b的值，不用传回去
void Swap(int* pa, int* pb) {
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}
