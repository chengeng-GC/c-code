#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>

int main() {
	//��Ŀ���ƣ�
	//�������
	//��Ŀ���ݣ�
	//����Ļ�ϴ�ӡ������ǡ�
	//1
	//11
	//121
	//1331
	//14641

	int arr[10][10] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i==j)
			{
				arr[i][j] = 1;
			}
			if (i>=2&&j>=1)
			{
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
			}
		}
	}
	//��ӡ
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			//printf("%d ", arr[i][j]);
		}
		//printf("\n");
	}

	//��Ŀ���ƣ�
	//������
	//��Ŀ���ݣ�
	//�ձ�ĳ�ط�����һ��ıɱ����I����ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
	//����Ϊ4�����ɷ��Ĺ��ʣ�
	//A˵�������ҡ�t
	//B˵����C.t
	//C˵����D.f
	//D˵��C�ں�˵t��֪3����˵���滰��1����˵���Ǽٻ���
	//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
	int killer = 0;
	for (killer = 'a'; killer < 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == "d") + (killer != 'd') == 3)
		{
			//printf("killer is %c\n", killer);
		}
	}

	return 0;
}