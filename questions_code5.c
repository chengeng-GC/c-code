#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>

void move1(int *arr,int sz) {
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		while ( *(arr + left) % 2 == 1) {
			left++;
		}
		while ( *(arr + right) % 2 == 0) {
			right--;
		}
		if (left<right)
		{
			int tmp = *(arr + left);
			*(arr + left)= *(arr + right);
			*(arr + right) = tmp;
		}
	}
}
int main() {
	//��Ŀ���ƣ�
	//����ˮ����
	//��Ŀ���ݣ�
	//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
	int money = 0;
	//scanf("%d",&money);
	int soda = money;
	int full_soda = money;
	int empty_soda = 0;
	while (full_soda) {
	//��
		while (full_soda > 0) {
			full_soda--;
			empty_soda++;
		}
	//��
		while (empty_soda >= 2) {
			empty_soda -= 2;
			full_soda++;
			soda++;
		}
	}
	//printf("��%dԪһ������%dƿ��ˮ\n",money,soda);


	//��Ŀ���ƣ�
	//��������ż��˳��
	//��Ŀ���ݣ�
	//��������ʹ����ȫ����λ��ż��ǰ�档
	int arr[] = { 1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	move1(arr,sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}