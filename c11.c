#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int check() {
	int a = 1;
	char* p = (char*)&a;
	return *p;
}

int main() {
	/*C�������� 
	1.�������� 
	char short int long float double 
	2.�Զ�������


	�ֽ�����С�ˣ�
    ��ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĸߵ�ַ�У������ݵĸ�λ���������ڴ�ĵ͵�ַ��
	С�ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĵ͵�ַ�У������ݵĸ�λ���������ڴ�ĸߵ�ַ��
	Ϊʲô���д�С��ģʽ֮���أ�
	������Ϊ�ڼ����ϵͳ�У����������ֽ�Ϊ��λ�ģ�ÿ����ַ��Ԫ����Ӧ��һ���ֽڣ�һ���ֽ�Ϊ8bit��
	������C�����г���8bit��char֮�⣬����16bit��short�ͣ�32bit��long�ͣ�Ҫ������ı�������
	���⣬����λ������8λ�Ĵ�����������16λ����32λ�Ĵ����������ڼĴ������ȴ���һ���ֽڣ���ô��Ȼ������һ�����������ֽڰ��ŵ�����
	��˾͵����˴�˴洢ģʽ��С�˴洢ģʽ��

	����һ��16bit��short��x�����ڴ��еĵ�ַΪ0��0010��x��ֵΪ0��1122
	��ô0��11Ϊ���ֽڣ�0��22Ϊ���ֽڡ�
	���ڴ��ģʽ���ͽ�0x11���ڵ͵�ַ�У���0��0010�У�0��22���ڸߵ�ַ�У���0��0011�С�
	С��ģʽ���պ��෴�����ǳ��õġ�86�ṹ��С��ģʽ����kEIL C51��Ϊ���ģʽ��
	�ܶ��ARM��DSP��ΪС��ģʽ��
	��ЩARM��������������Ӳ����ѡ���Ǵ��ģʽ����С��ģʽ��
	
	*/

	//������Ե�ǰ�������ֽ�����ʲô
	int ret = check();
	if (ret == 1) {
		printf("С��");
	}
	else
	{
		printf("���");
	}

		return 0;
}