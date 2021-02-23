#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
void reverse(char arr[]) {
	char a;
	int left = 0;
	int right = strlen(arr) - 1;
	while (left < right) {
		a = arr[left];
		arr[left] = arr[right];
		arr[right] = a;
		left++;
		right--;
	}
}
double Pow(int n, int k) {
	if (k==0) {
		return 1;
	}
	else if(k<0)
	{
		return (1.0 / Pow(n, -k));
	}
	return n * Pow(n, k-1);

}
int main(){
	//��Ŀ���ƣ�
	//�ַ�������
	//��Ŀ���ݣ�
	//дһ����������������һ���ַ���������
	char arr[] = "abcdefg";
	reverse(arr);
	//printf("%s\n",arr);

	//��Ŀ���ƣ�
	//�������
	//��Ŀ���ݣ�
	//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮��
	//����a��һ�����֣����磺2 + 22 + 222 + 2222 + 22222
	int a = 0;
	//scanf("%d",&a);
	int b = a;
	int sum = 0;
	for (int i = 0; i <5 ; i++)
	{
		sum += b;
		b = b * 10 + a;
	}
	//printf("%d\n",sum);

	//��Ŀ���ƣ�
	//��ӡˮ�ɻ���
	//��Ŀ���ݣ�
	//���0~100000֮������С�ˮ�ɻ����������
	//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
	//�磺153 = 1^3 + 5^3 + 3^3����153��һ����ˮ�ɻ���
	for (int i = 0; i < 100000; i++)
	{
		//����i��λ��
		int n = 1;
		int tmp = i;
		int sum = 0;
		while (tmp/=10) {
			n++;
		}
		//����i��ÿһλ��n�η�֮�� sum
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, n);
			tmp /= 10;
		}
		//�Ƚ�i==sum
		if (i==sum)
		{
			//printf("%d\n", i);
		}
	}
		//��Ŀ���ƣ�
		//��ӡ����
		//��Ŀ���ݣ�
		//����߳���������Σ����ӣ�����7
		//�����
//				*
//			   ***
//			  *****
//		     *******
//	        *********
//	       ***********
//	      *************
//	       ***********
//		    *********
//		     *******
//			  *****
//			   ***
//				*
	int n = 0;
	//scanf("%d",&n);
	//��ӡ�ϰ벿��
	for (int i = 1; i <= n; i++)
	{
			int k = n  - i;
			int n = 2*i-1;
			while (k>=1)
			{
				printf(" ");
				k--;
			}
			while (n>=1)
			{
				printf("*");
				n--;
			}
			while (k< n-i)
			{
				printf(" ");
				k++;
			}
			printf("\n");
	}
	//��ӡ�°벿��
	for ( int i = n-1;  i >=1; i--)
	{
		int k = n - i;
		int n = 2 * i - 1;
		while (k >= 1)
		{
			printf(" ");
			k--;
		}
		while (n >= 1)
		{
			printf("*");
			n--;
		}
		while (k < n - i)
		{
			printf(" ");
			k++;
		}
		printf("\n");
	}



	return 0;
}