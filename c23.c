#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
//д��1  ������������
struct S1 {
	int n;
	int* arr;
};
//д��2 �����ͷţ������ڷ����ٶ�
struct S2 {
	int n;
	int arr[0];//δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
};


int main(){
	//��������
	//	C99�У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ���[��������]��Ա��
	//����������ص㣺
	//	���ṹ�е����������Աǰ���������һ��������Ա��
	//	��sizeof���ص����ֽṹ��С����������������ڴ档
	//	���������������Ա�Ľṹ��malloc���������ڴ�Ķ�̬���䣬���ҷ�����ڴ�Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С
	
	//д��1 ������������
	struct S1* ps = (struct S1*)malloc(sizeof(struct S1));
	ps->arr = malloc(5 * sizeof(int));
	ps->n = 100;
	int i = 0;
	for (i = 0; i < 5; i++) {
		ps->arr[i] = i;
	}
	int* ptr =realloc(ps->arr, 44);
	if (ptr != NULL) {
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++) {
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", ps->arr[i]);
	}
	//�ͷ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	printf("\n");

	//д��2 �����ͷţ������ڷ����ٶ�
	//�������ڴ���������߷����٣�Ҳ�����ڼ����ڴ���Ƭ������ʵ���Ҹ��˾���Ҳû����ˣ��������ܲ���Ҫ����ƫ�����ļӷ���Ѱַ��
	struct S2* ps2 =malloc(sizeof(struct S2)+5*sizeof(int));
	ps2->n = 100;
	int i2 = 0;
	for (i2 = 0; i2 < 5; i2++) {
		ps2->arr[i2] = i2;
	}
	struct S2* ptr2 = realloc(ps2, 44);
	if (ptr2 != NULL) {
		ps2 = ptr2;
	}
	for (i2 = 5; i2 < 10; i2++) {
		ps2->arr[i2] = i2;
	}
	for (i2 = 0; i2 < 10; i2++) {
		printf("%d ", ps2->arr[i2]);
	}
	//�ͷ�
	free(ps2);
	ps2 = NULL;
	return 0;
}