#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
void reverse(char arr[]) {
	char a;
	int left = 0;
	int right = strlen(arr) - 1;
	while (left < right) {
		a = arr[left];
		arr[left] = arr[right];
		arr[right] = a;
		left++;
		right--;
	}
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
	//字符串逆序
	//题目内容：
	//写一个函数，可以逆序一个字符串的内容
	char arr[] = "abcdefg";
	reverse(arr);
	//printf("%s\n",arr);

	//题目名称：
	//计算求和
	//题目内容：
	//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和
	//其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
	int a = 0;
	//scanf("%d",&a);
	int b = a;
	int sum = 0;
	for (int i = 0; i <5 ; i++)
	{
		sum += b;
		b = b * 10 + a;
	}
	//printf("%d\n",sum);

	//题目名称：
	//打印水仙花数
	//题目内容：
	//求出0~100000之间的所有“水仙花数并输出。
	//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身
	//如：153 = 1^3 + 5^3 + 3^3，则153是一个“水仙花。
	for (int i = 0; i < 100000; i++)
	{
		//计算i的位数
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp/=10) {
			n++;
		}
		//计算i的每一位的n次方之和 sum
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//比较i==sum
		if (i==sum)
		{
			//printf("%d\n", i);
		}
	}
		//题目名称：
		//打印菱形
		//题目内容：
		//输入边长，输出菱形，例子：输入7
		//输出：
//				*
//			   ***
//			  *****
//		     *******
//	        *********
//	       ***********
//	      *************
//	       ***********
//		    *********
//		     *******
//			  *****
//			   ***
//				*
	int n = 0;
	//scanf("%d",&n);
	//打印上半部分
	for (int i = 1; i <= n; i++)
	{
			int k = n  - i;
			int n = 2*i-1;
			while (k>=1)
			{
				printf(" ");
				k--;
			}
			while (n>=1)
			{
				printf("*");
				n--;
			}
			while (k< n-i)
			{
				printf(" ");
				k++;
			}
			printf("\n");
	}
	//打印下半部分
	for ( int i = n-1;  i >=1; i--)
	{
		int k = n - i;
		int n = 2 * i - 1;
		while (k >= 1)
		{
			printf(" ");
			k--;
		}
		while (n >= 1)
		{
			printf("*");
			n--;
		}
		while (k < n - i)
		{
			printf(" ");
			k++;
		}
		printf("\n");
	}



	return 0;
}