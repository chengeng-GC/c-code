#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//��������,һ��д��.hͷ�ļ���,�����Ķ���д��.c�ļ���
void Swap(int* pa, int* pb);

int main() {
	//goto���,һ�������������ѭ�������ƻ��ԣ�������ʹ��
again:
	printf("��ѭ��\n");
	//goto again;

	//�Ƚ������ַ���-strcmp,����0Ϊ���
	char input[20] = { 0 };
	scanf("%s",input);
	printf("%d\n",strcmp(input,"�Ƚ��ַ���"));

	//һЩ�⺯��
	//strcpy(Ŀ�꣬����Դ) ��string.h
	//memset  -�ڴ�����
	char arr[] = "hello world";
	memset(arr, '*', 5);
	printf("%s\n", arr);

	//����ָ���������ú����ı䵱ǰ�����еı�����ֵ
	int a = 10;
	int b = 20;
	Swap(&a, &b);
	printf("a=%d\nb=%d\n", a, b);

	return 0;
}


//��ַ����
//�������ղ���Ϊָ�룬����ֱ�Ӹı�a��b��ֵ�����ô���ȥ
void Swap(int* pa, int* pb) {
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;

}
