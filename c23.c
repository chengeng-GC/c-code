#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
//写法1  不是柔性数组
struct S1 {
	int n;
	int* arr;
};
//写法2 方便释放，有利于访问速度
struct S2 {
	int n;
	int arr[0];//未知大小的-柔性数组成员-数组的大小是可以调整的
};


int main(){
	//柔性数组
	//	C99中，结构中的最后一个元素允许是未知大小的数组，这就叫做[柔性数组]成员。
	//柔性数组的特点：
	//	·结构中的柔性数组成员前面必须至少一个其他成员。
	//	·sizeof返回的这种结构大小不包括柔性数组的内存。
	//	·包含柔性数组成员的结构用malloc函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小
	
	//写法1 不是柔性数组
	struct S1* ps = (struct S1*)malloc(sizeof(struct S1));
	ps->arr = malloc(5 * sizeof(int));
	ps->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++) {
		ps->arr[i] = i;
	}
	int* ptr =realloc(ps->arr, 44);
	if (ptr != NULL) {
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++) {
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", ps->arr[i]);
	}
	//释放
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	printf("\n");

	//写法2 方便释放，有利于访问速度
	//连续的内存有益于提高访问速，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正你跑不了要用做偏移量的加法来寻址）
	struct S2* ps2 =malloc(sizeof(struct S2)+5*sizeof(int));
	ps2->n = 100;
	int i2 = 0;
	for (i2 = 0; i2 < 5; i2++) {
		ps2->arr[i2] = i2;
	}
	struct S2* ptr2 = realloc(ps2, 44);
	if (ptr2 != NULL) {
		ps2 = ptr2;
	}
	for (i2 = 5; i2 < 10; i2++) {
		ps2->arr[i2] = i2;
	}
	for (i2 = 0; i2 < 10; i2++) {
		printf("%d ", ps2->arr[i2]);
	}
	//释放
	free(ps2);
	ps2 = NULL;
	return 0;
}