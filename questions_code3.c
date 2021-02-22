#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>

void print_table(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d×%d=%d ", i, j, i*j);
		}
		printf("\n");
	}

}
int determine_year(int year) {
	if (year%400==0)
	{
		return 1;
	}
	if (year%4==0)
	{
		if (year%100==0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void print_int(int n) {
	int i = n%10;
	if (n==0)
	{
		return;
	}
	else
	{
		n = n - (n % 10);
		n = n / 10;
		print_int(n);
	}
	printf("%d\n", i);
}

int my_strlen(char* str) {
	int count = 0;
	while(*str != '\0'){
		count++;
		str++;
	}
	return count;
}

void reverse_string(char arr[]) {
	char tmp = arr[0];
	int len = my_strlen(arr);
	arr[0] = arr[len - 1];
	arr[len - 1] = '\0';
	if (my_strlen(arr+1)>=2)
	{
		reverse_string(arr + 1);
	}
	arr[len - 1] = tmp;
}

int DigitSum(unsigned int n) {
	if (n == 0)
	{
		return 0;
	}
	return 	n % 10 +DigitSum(n/10);
		
}

double Pow(int n, int k) {
	if (k==0) {
		return 1;
	}
	else if(k<0)
	{
		return (1.0 / Pow(n, -k));
	}
	return n * Pow(n, k-1);

}
int main(){

	//题目名称：
	//乘去口诀表题目内容：
	//实现一个函数，打印乘去口诀表，口诀表的行数和列数自己指定
	//如：输入9，输出9*9口诀表，输入12，输出12*12的乘去口诀表。
	int n = 0;
	//scanf("%d",&n);
	//print_table(n);

	//题目名称：
	//函数判断闰年
	//题目内容：
	//实现函数判断year是不是闰年。
	//scanf("%d", &n);
	int ret = determine_year(n);
	if (ret == 1) {
		//printf("%d年是闰年\n", n);
	}
	else
	{
		//printf("%d年不是闰年\n", n);
	}

	//题目名称：
	//打印一个数的每一位
	//题目内容：
	//递归方式实现打印一个整数的每一位
	//scanf("%d", &n);
	//print_int(n);


	//题目名称：
	//字符串逆序（递归实现）
	//题目内容：
	//编写一个函数 reverse_string(char*string)（递归实现）
	//实现：将会数字符串中的字符反向排列。
	//要求：不能使用C函数库中的字符串操作函数。
	char arr[] = "abcdef";
	reverse_string(arr);
	//printf("%s\n",arr);



	//题目名称：
	//计算一个数的每位之和（递归实现）
	//题目内容：
	//写一个递归函数DigitSum（n).输入一个非负整数，返回组成它的数字之和
	//例如，调用DigiSum(1729），
	//输入：1729，输出：19
	unsigned int num = 0;
	//scanf("%d", &num);
	ret = DigitSum(num);
	//printf("输入：%d，输出：%d\n", num, ret);

	//题目名称：
	//递归实现n的k次方
	//题目内容：编写一个函数实现n的k次方，使用递归实现。
	int k = 0;
	//scanf("%d%d", &n, &k);
	double doubleret = Pow(n,k);
	//printf("%d的%d次方等于%f\n", n, k, doubleret);





	return 0;
}