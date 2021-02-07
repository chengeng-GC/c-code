#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//	������Ϣ����
//	strerror һ�� ����ֵ����char*
//		���ش����룬����Ӧ�Ĵ�����Ϣ��
//		������		������Ϣ
//		0			No error
//		1			Operation not permitted
//		2 			No such file or directory
//		errno		��һ��ȫ�ֵĴ�����ı���
//		��c���ԵĿ⺯����ִ�й����У������˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����룬��ֵ��errno��
//
//	�ַ����ຯ����
//		����		������Ĳ����������������ͷ�����
//		iscntrl		�κο����ַ�
//		isspace		�հ��ַ����ո�''����ҳ'\f'������'\n'���س�'\r'���Ʊ��'\t'���ߴ�ֱ�Ʊ��'\v'
//		isdigit		ʮ��������0 - 9
//		isxdigit	ʮ���������֣���������ʮ�������֣�Сд��ĸa - f����д��ĸA - F
//		islower		Сд��ĸa - z
//		isupper		��д��ĸA - Z
//		isalpha		��ĸa - z��A - Z
//		isalnum		��ĸ�������֣�a - Z, A - Z, 0 - 9
//		ispunct		�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ����ɴ�ӡ��
//		isgraph		�κ�ͼ���ַ�
//		isprint		�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�


//�ڴ��������
//memcpy ���� �����ص��ڴ濽��
//void* memcpy(void * destination, const void * source, size_t num); 
//	������memcpy��source��λ�ÿ�ʼ�����num���ֽڵ����ݵ�destination���ڴ�λ�á�
//	���������������\0����ʱ�򲢲���ͣ������
//	�����source��destination���κε��ص������ƵĽ������δ����ġ�

//memmove ���� �����ڴ��ص�����
//void *memmove( void *dest,const void *src,size_t count);

//memset ���� �ڴ�����
//void *memset(void *dest, int c, size_t count);
//	��c���޸ĺ��ֵ
//	��count���޸ļ����ֽ�

//memcmp ���� �ڴ�Ƚ�
//int memcmp(const void* ptr1, const void* ptr2, size_t num);
//	���Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�,��ע�����ֽڸ�����
//	�����ڷ���0�����ڷ��ش���0��С�ڷ���С��0
int main() {
	//���ļ� 
	FILE* pf = fopen("test.txt", "r");
	if (pf==NULL) {
		printf("%s\n",strerror(errno));
	}
	else{
		printf("open file success");
	}
	return 0;
}