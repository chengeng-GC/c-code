#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//ָ�����͵����壺
//1.ָ�����;�����ָ������ò������ܷ��ʼ����ֽڣ�
//char - p�� * p������1���ֽڣ�int - p��"p����4���ֽ�
//2.ָ�����;�����ָ�� + 1�� - 1���ӵĻ��߼����Ǽ����ֽڣ�
//char*p��p + 1������һ���ַ���int*p��p + 1������һ������ - 4���ֽ�

void print2(int(*p)[5], int x, int y)
{
	int i = 0;
	for (i = 0;i < x;i++)
	{
		int j = 0;
			for (j = 0;j < y;j++)
			{
				//printf("%d",*(*(p+i)+j));
				printf("%d ", (*(p + i))[j]);
			
			}
			printf("\n");
	}
}
int main() {
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	//���Ϊ -1,-1,255
	printf("%d,%d,%d\n",a, b, c);
	//ָ��������ָ��
	//��ȡָ�������ַ
	char* arr[5];
	char* (*pa)[5] = &arr;
	printf("%c\n", (*pa[0]));
	int arr2[10] = { 0 };
	int(*pb)[10] = &arr2;
	printf("%d\n", (*pb)[0]);
	//ͨ��ָ�������ά����
	int arr3[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	print2(arr3, 3, 5);//arr-������-������������Ԫ�ص�ַ


	return 0;
}