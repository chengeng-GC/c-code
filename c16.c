#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int FindNum(int arr[3][3], int k, int *px, int *py) {
	int x = 0;
	int y = *py - 1;
	while (y >= 0&&x<=*px-1)
	{
		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
	
}

int main() {
	char str1[30] = "abc";
	char str2[30] = "def";
	char str3[30] = "abc";
	//��str1�ַ�����׷��һ��str2�ַ���
	//��strcat
	strcat(str1, str2);
	printf("%s\n", str1);
	//��str3�ַ�����׷��һ��str3�ַ���
	//strcat(str3, str3);err
	//��strcat���У�Ҫ��strncat
	strncat(str3, str3,3);
	printf("%s\n",str3);
	//�ж�str2�ַ����Ƿ���str1�ַ������Ӵ�
	//strstr-���Ӵ���
	char * ret1 = strstr(str1,str2);
	if (ret1 == NULL) {
		printf("����\n");
	}
	else
	{
		printf("��\n");
	}

	//���Ͼ���
	//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ġ�
	//���д�����������ľ����в���ĳ�������Ƿ����,�����ڣ������±�
	//Ҫ��ʱ�临�Ӷ�С��0(N)
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	//�����Ͳ���
	int ret2 = FindNum(arr,k,&x,&y);
	if (ret2==1)
	{
		printf("�ҵ���,�±�Ϊ%d,%d\n",x,y);
	}
	else
	{
		printf("û�ҵ�\n");
	}
	return 0;
}