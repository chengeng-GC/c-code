#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//void(*)()- ����ָ������
//������뽫0ǿ��ת��Ϊ����ָ�����ͣ������ַ���øõ�ַ�ĺ���
//(*(void(*)())0)();
//��������signal���β���һ��int ��һ������ָ�루�β���int��  ������ֵ��һ������ָ�루�β���int��
void(*signal(int, void(*)(int)))(int);

int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
int main() {
	//arr��һ��5��Ԫ�ص���������
	//parr1��һ�����飬������10��Ԫ�أ�ÿ��Ԫ�ص�������int*,parr1��ָ������
	//parr2��һ��ָ�룬��ָ��ָ����һ�����飬������10��Ԫ�أ�ÿ��Ԫ�ص�������int-parr2������ָ��
	//parr3��һ�����飬��������10��Ԫ�أ�ÿ��Ԫ����һ������ָ�������ָ��ָ���������5��Ԫ�أ�ÿ��Ԫ����int
	int arr[5];
	int *parr1[10];
	int(*parr2)[10];
	int(*parr3[10])[5];

	//��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]
	//��Ϊһ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ��
	 
	//�򻯺���ָ��
	//�ض��庯��ָ��
	typedef void(*xxx)(int);
	//������void(*signal(int, void(*)(int)))(int)ͬ�����Ǽ���
	xxx signal(int, xxx);


	//����ָ�������
	int(*parr4[4])(int, int) = { Add,Sub,Mul,Div };
	//ʹ��
	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		printf("%d\n",parr4[i](2,3));
	}

	return 0;
}


