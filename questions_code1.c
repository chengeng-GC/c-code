#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
void init(int arr[], int sz) {
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}

}

void print(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n",arr[i]);
	}
}
void Reverse(int arr[], int sz) {
	int i = 0;
	int j = 0;
	for ( i = 0; i < sz/2; i++)
	{
		j = arr[i];
		arr[i] = arr[sz - 1 - i];
		arr[sz - 1 - i] = j;
	}
}


int main(){
	//��Ŀ���ƣ�
	//�������
	//��Ŀ���ݣ�
	//����һ���������飬��ɶ�����Ĳ���
	//1.ʵ�ֺ���init������ʼ������Ϊȫ0
	//2.ʵ��print������ӡ�����ÿ��Ԫ��
	//3.ʵ��reverse���������������Ԫ�ص����á�
	//Ҫ���Լ�������Ϻ����Ĳ���������ֵ��
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	init(arr,sz);
	print(arr,sz);
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
	Reverse(arr, sz);
	print(arr, sz);


	//��Ŀ���ƣ�
	//��������
	//��Ŀ���ݣ�
	//������A�е����ݺ�����B�е����ݽ��н�����������һ����
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 3,6,23,6,7 };
	sz = sizeof(arr1) / sizeof(arr1[0]);
	int j = 0;
	i = 0;
	for ( i = 0; i < sz; i++)
	{
		j = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = j;
		printf("%d\n", arr1[i]);
	}
	

	return 0;
}