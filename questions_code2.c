#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
int count_bit_one1(unsigned int a) {
	int count = 0;
	while (a) {
		if (a % 2 == 1)
		{
			count++;
		}
		a = a / 2;
	}
	return count;
}
int count_bit_one2(int a) {
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a>>i)&1)==1)
		{
			count++;
		}
	}
	return count;
}
int count_bit_one3(int a) {

	int count = 0;
	while (a) {
		a = a & (a - 1);
		count++;
	}
	return count;
}
int get_diff_bit(int m, int n) {
	int count = 0;
	int a = m ^ n;
	while (a) {
		a = a & (a - 1);
		count++;
	}
	return count;
}
void print(int m) {
	int i = 0;
	printf("����λ:");
	for ( i = 30; i >= 0; i-=2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("ż��λ:");
	for ( i = 31; i >=1; i-=2)
	{
		printf("%d ", (m >> i) & 1);
	}
}
void print_arr(int *p, int sz) {
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d\n",*(p+i));
	}
}

int main() {

	//��Ŀ���ƣ�
	//ͳ�ƶ�������1�ĸ�����Ŀ���ݣ�
	//дһ���������ز���������(����)��1�ĸ�����
	//���磺15  00001111  4��1
	//����д��,3���
	int a = 0;
	//scanf("%d", &a);
	int count1 = count_bit_one1(a);
	int count2 = count_bit_one2(a);
	int count3 = count_bit_one3(a);
	//printf("������1��%d�Ķ�����(����)����%d��1\n", a, count1);
	//printf("������2��%d�Ķ�����(����)����%d��1\n", a, count2);
	//printf("������3��%d�Ķ�����(����)����%d��1\n", a, count3);
	//��Ŀ���ƣ�
	//��������в�ͬλ�ĸ���
	//��Ŀ���ݣ�
	//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ��bit)��ͬ��
	//�������ӣ�
	//1999 2299 ������ӣ�7
	int m = 0;
	int n = 0;
	//scanf("%d%d",&m,&n);
	count1 = get_diff_bit(m, n);
	//printf("%d��%d��%d��λ��bit)��ͬ\n",m,n,count1);



	//��Ŀ���ƣ�
	//��ӡ�����Ƶ�����λ��ż��λ
	//��Ŀ���ݣ�
	//��ȡһ���������������������е�ż��λ������λ
	//�ֱ��ӡ������������
	
	//scanf("%d", &m);
	//print(m);
	


	//��Ŀ���ƣ�
	//ʹ��ָ���ӡ��������
	//��Ŀ���ݣ�
	//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
	//arr��һ������һά���顣
	int arr[] = { 1,2,3,4,6,7,5,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//print_arr(arr, sz);


	//��Ŀ���ƣ�
	//����������������������ʱ������
	//��Ŀ���ݣ�
	//����������ʱ������������������������
	//scanf("%d%d",&m,&n);
	//printf("m=%d,n=%d\n",m,n);
	m = n + m;
	n = m - n;//n=m
	m = m - n;//m=n
	//����
	//m=m^n;
	//n=m^m;
	//m=m^n;
	//printf("������:m = %d, n = %d\n",m, n);
	return 0;
}