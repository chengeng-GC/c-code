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
	//题目名称：
	//猜名次
	//题目内容：
	//5位运动员参加了10米台跳水比赛，有人让他们预则比赛结果：
	//A选手说：B第二，我第三；
	//B选手说：我第二，E第四；
	//C选手说：我第一，D第二；
	//D选手说：C最后，我第三；
	//E选手说：我第四，A第一；
	//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
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

	//题目名称：
	//字符串左旋
	//题目内容：
	//实现一个函数，可以左旋字符串中的k个字符。
	//例如：
	//ABCD左旋一个字符得到BCDA
	//ABCD左旋两个字符得到CDAB

	int k = 0;
	scanf("%d",&k);
	char arr[] = "123456789";
	left_move(arr,k);
	printf("%s\n", arr);
	return 0;
}