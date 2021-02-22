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
			printf("%d��%d=%d ", i, j, i*j);
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

	//��Ŀ���ƣ�
	//��ȥ�ھ�����Ŀ���ݣ�
	//ʵ��һ����������ӡ��ȥ�ھ����ھ���������������Լ�ָ��
	//�磺����9�����9*9�ھ�������12�����12*12�ĳ�ȥ�ھ���
	int n = 0;
	//scanf("%d",&n);
	//print_table(n);

	//��Ŀ���ƣ�
	//�����ж�����
	//��Ŀ���ݣ�
	//ʵ�ֺ����ж�year�ǲ������ꡣ
	//scanf("%d", &n);
	int ret = determine_year(n);
	if (ret == 1) {
		//printf("%d��������\n", n);
	}
	else
	{
		//printf("%d�겻������\n", n);
	}

	//��Ŀ���ƣ�
	//��ӡһ������ÿһλ
	//��Ŀ���ݣ�
	//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
	//scanf("%d", &n);
	//print_int(n);


	//��Ŀ���ƣ�
	//�ַ������򣨵ݹ�ʵ�֣�
	//��Ŀ���ݣ�
	//��дһ������ reverse_string(char*string)���ݹ�ʵ�֣�
	//ʵ�֣��������ַ����е��ַ��������С�
	//Ҫ�󣺲���ʹ��C�������е��ַ�������������
	char arr[] = "abcdef";
	reverse_string(arr);
	//printf("%s\n",arr);



	//��Ŀ���ƣ�
	//����һ������ÿλ֮�ͣ��ݹ�ʵ�֣�
	//��Ŀ���ݣ�
	//дһ���ݹ麯��DigitSum��n).����һ���Ǹ����������������������֮��
	//���磬����DigiSum(1729����
	//���룺1729�������19
	unsigned int num = 0;
	//scanf("%d", &num);
	ret = DigitSum(num);
	//printf("���룺%d�������%d\n", num, ret);

	//��Ŀ���ƣ�
	//�ݹ�ʵ��n��k�η�
	//��Ŀ���ݣ���дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
	int k = 0;
	//scanf("%d%d", &n, &k);
	double doubleret = Pow(n,k);
	//printf("%d��%d�η�����%f\n", n, k, doubleret);





	return 0;
}