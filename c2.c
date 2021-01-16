
//scanf是C语言提供的
//scanf_s不是标准C语言提供的是VS编译器提供的
//直接使用C语言给的函数会有编译错误或警告，加一条↓就解决
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//常量 

//#define 定义标识符常量
#define MAX 10


//枚举常量,是有值的
enum Sex
{
	MALE,
	FEMALE,
	SECRET
};

int main() {

	//const-常变量（不可变）
	//n是变量，又有常属性（不可变），所以叫常变量
	const int n = 4;
	printf("%d\n",n);
	//使用枚举常量
	printf("%d\n", MALE);
	printf("%d\n", FEMALE);
	printf("%d\n", SECRET);
	enum Sex sex = MALE;
	printf("%d\n", sex);

	//字符串类型
	char a1[] = "你好C语言";
	//或
	char a2[] = { 'a','b','c','\0' };
	//"\0"是字符串的结束标志
	printf("%s\n",a1);
	printf("%s\n", a2);
	//strlen-计算字符串长度
	printf("%d\n", strlen(a2)); 
	//转义字符（以\开始的字符）
	//比如\n换行

	return 0;
}
