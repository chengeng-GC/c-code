#define _CRT_SECURE_NO_WARNINGS
//包含一个叫stdio.h的文件
//std-标准 standard input output
#include <stdio.h>
//局部变量和全局变量的名字建议不要相同一容易误会，产生bug
//当局部变量和全局变量的名字相同的时候，局部变量优先
int i1 = 10;//全局变量
int main() //主函数-程序的入口，int表示返回值类型
{
	float x1 = 45.5f;//局部变量
	printf("HelloWorld\n");
	//打印各种数据类型的大小是多少字节
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof(int));


	//计算两个数的和
	//C语言语法规定，变量要定义在当前代码块的最前面
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//输入数据-使用输入函数scanf
	scanf("%d%d", &num1, &num2);//取地址符号&（取内存地址）
	sum = num1 + num2;
	printf("和为%d\n", sum);

	return 0;
}
//%d-打印整型
//%f-打印浮点数字-打小数
//%p-以地址的形式打印
//%x-打印16进制数字
//%c-打印字符
//%s-打印字符串


