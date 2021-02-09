#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//枚举类型
enum Sex {
	//枚举的可能取值
	MALE=1,
	FEMALE=2,
	SECRET=4
};

//联合类型的定义
union Un { 
	char c; 
	int i; 
};
//五个字节
int main() {
	enum Sex s = MALE;
	//·枚举
	//	o枚举类型的定义-如上
	//	o枚举的优点
	//	我们可以使用#define定义常量，为什么非要使用枚举 ? 枚举的优点：
	//		1.增加代码的可读性和可维护性
	//		2.和#define定义的标识符比较枚举有类型检查，更加严谨。
	//		3.防止了命名污染（封装）
	//		4.便于调试
	//		5.使用方便，一次可以定义多个常量
	//	o枚举的使用
	//·联合
	//	o联合类型的定义
	//	联合也是一种特殊的自定义类型这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间（所以联合也叫共用体）。-如上
	//	o联合的特点
	//	联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）。
	//	o联合大小的计算
	//	·联合的大小至少是最大成员的大小。
	//	·当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
}