#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int my_strlen(char str[])
{
	char* start = str;
	char* end = str;
	while (*end != '\0') {
		end++;
	}
	return end - start;

}
int main() {
	//   >>  ���Ʋ�����
	//�ƶ����Ƕ�����λ
	int a = 16;
	int b = a >> 1;
	//���Ʋ�����
	/*1.��������
		�ұ߶�������߲�ԭ����λ
	2.�߼�����
		�ұ߶�������߲�0*/

	//ָ�� �������Ϊ��ַ
	//ָ������
	//������ָ����н����ò�����ʱ���ܹ����ʿռ�Ĵ�С
	//������ָ����һ���߶�Զ��������
	char* pa = NULL;
	int* pb = NULL;

	//Ұָ��  ָ��ָ���λ���ǲ���֪�ģ�����ģ�����ȷ�ģ�û����ȷ���Ƶģ�
	//����1.ָ��δ��ʼ��
	int* pc;
	//����2.ָ��Խ�����
	//��ָ��ָ��ķ�Χ��������ķ�Χʱ������Ұָ��
	/*���Ұָ��
	1.ָ���ʼ��
	2.С��ָ��Խ��
	3.ָ��ָ��ռ��ͷż�ʹ��NULL
	4.ָ��ʹ��֮ǰ�����Ч��*/

	//ָ������
	//ָ��+-����
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int* pd = arr1;
	for (int i = 0; i < sz; i++)
	{
		printf("%d\n",*pd);
		//ָ��+1����������һλ��-1����ǰһλ
		pd = pd + 1;//pd++Ҳһ��
	}

	//ָ��ģ��strlen
	char arr2[] = "bit";
	int len = my_strlen(arr2);
	printf("%d\n", len);
	//��׼�涨��
	//����ָ������ָ����ָ���������һ��Ԫ�غ����Ǹ��ڴ�λ�õ�ָ��Ƚ�
	//��������ָ���һ��Ԫ��֮ǰ���ڴ�λ��ָ����бȽ�

	//ppe�Ƕ���ָ�룬e�ĵ�ַ�����һ��ָ��pe�У�pe�ĵ�ַ����ppe��
	int e = 10;
	int* pe = e;
	int** ppe = pe;
	//ָ������
	int* arr3[3];
	return 0;
}