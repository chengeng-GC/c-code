#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>


void left_move(char* arr, int k) {
	for (int i = 0; i < k; i++)
	{
		char a = *arr;
		int j = 0;
		while (*(arr + j + 1) != '\0')
		{
			*(arr + j) = *(arr + j + 1);
			j++;
		}
		*(arr + j) = a;
	}
}
int main(){
	//��Ŀ���ƣ�
	//������
	//��Ŀ���ݣ�
	//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
	//Aѡ��˵��B�ڶ����ҵ�����
	//Bѡ��˵���ҵڶ���E���ģ�
	//Cѡ��˵���ҵ�һ��D�ڶ���
	//Dѡ��˵��C����ҵ�����
	//Eѡ��˵���ҵ��ģ�A��һ��
	//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int E = 0;
	for ( A = 1; A <= 5; A++)
	{
		for (B = 1; B<= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if (((B == 2) + (A == 3) == 1) && ((B == 2) + (E == 4) == 1) && ((C == 1) + (D == 2) == 1) && ((C == 5) + (D == 3) == 1) && ((E == 4) + (A == 1) == 1)) {
							if (A*B*C*D*E==120)
							{
								//printf("A:%d B:%d C:%d D:%d E:%d \n", A, B, C, D, E);
							}
						}
					}
				}
			}
		}
	}

	//��Ŀ���ƣ�
	//�ַ�������
	//��Ŀ���ݣ�
	//ʵ��һ�����������������ַ����е�k���ַ���
	//���磺
	//ABCD����һ���ַ��õ�BCDA
	//ABCD���������ַ��õ�CDAB

	int k = 0;
	scanf("%d",&k);
	char arr[] = "123456789";
	left_move(arr,k);
	printf("%s\n", arr);
	return 0;
}