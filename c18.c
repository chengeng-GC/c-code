#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//	错误信息报告
//	strerror 一参 返回值类型char*
//		返回错误码，所对应的错误信息。
//		错误码		错误信息
//		0			No error
//		1			Operation not permitted
//		2 			No such file or directory
//		errno		是一个全局的错误码的变量
//		当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到errno中
//
//	字符分类函数：
//		函数		如果他的参数符合下列条件就返回真
//		iscntrl		任何控制字符
//		isspace		空白字符：空格''，换页'\f'，换行'\n'，回车'\r'，制表符'\t'或者垂直制表符'\v'
//		isdigit		十进制数字0 - 9
//		isxdigit	十六进制数字，包括所有十进制数字，小写字母a - f，大写字母A - F
//		islower		小写字母a - z
//		isupper		大写字母A - Z
//		isalpha		字母a - z或A - Z
//		isalnum		字母或者数字，a - Z, A - Z, 0 - 9
//		ispunct		标点符号，任何不属于数字或者字母的图形字符（可打印）
//		isgraph		任何图形字符
//		isprint		任何可打印字符，包括图形字符和空白字符


//内存操作函数
//memcpy 三参 处理不重叠内存拷贝
//void* memcpy(void * destination, const void * source, size_t num); 
//	·函数memcpy从source的位置开始向后复制num个字节的数据到destination的内存位置。
//	·这个函数在遇到\0’的时候并不会停下来。
//	·如果source和destination有任何的重叠，复制的结果都是未定义的。

//memmove 三参 处理内存重叠拷贝
//void *memmove( void *dest,const void *src,size_t count);

//memset 三参 内存设置
//void *memset(void *dest, int c, size_t count);
//	·c是修改后的值
//	·count是修改几个字节

//memcmp 三参 内存比较
//int memcmp(const void* ptr1, const void* ptr2, size_t num);
//	·比较从ptr1和ptr2指针开始的num个字节,（注意是字节个数）
//	·等于返回0，大于返回大于0，小于返回小于0
int main() {
	//打开文件 
	FILE* pf = fopen("test.txt", "r");
	if (pf==NULL) {
		printf("%s\n",strerror(errno));
	}
	else{
		printf("open file success");
	}
	return 0;
}