#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
int if_same(char* arr1, char* arr2) {
	int len = strlen(arr1);
	for (int i = 0; i < len; i++)
	{
		char a = *arr1;
		int j = 0;
		for (j=0;j<len-1;j++)
		{
			*(arr1 + j) = *(arr1 + j + 1);
		}
		*(arr1 + j) = a;
		if (strcmp(arr1,arr2)==0) {
			return 1;
		}
		}
	return 0;
}

int FindNum(int arr[3][3], int k, int row, int col) {
	int x = 0;
	int y = col - 1;
	while (x<=row-1&&y>=0) {
		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k) {
			x++;
		}
		else {
			return 1;
		}

	}


	return 0;
}
int main() {
	//��Ŀ���ƣ�
	//�ַ�����ת���
	//��Ŀ���ݣ�
	//дһ���������ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת֮����ַ���
	//���磺����s1 = AABCD��s2 = BCDAA������1
	//		����s1 = abcd��S2 = ACBD������0.
	//AABCD����һ���ַ��õ�ABCDA
	//AABCD���������ַ��õ�BCDAA
	//AABCD����һ���ַ��õ�DAABC
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	char s3[] = "abcd";
	char s4[] = "ACBD";
	int ret1 = if_same(s1, s2);
	int ret2 = if_same(s3, s4);
	//printf("%d %d\n", ret1, ret2);


	//��Ŀ���ƣ�
	//���Ͼ���
	//��Ŀ���ݣ�
	//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
	//Ҫ��ʱ�临�Ӷ�С��O��N)

	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 1;
	int ret = FindNum(arr, k, 3, 3);
	//printf("%d\n", ret);

	return 0;
}