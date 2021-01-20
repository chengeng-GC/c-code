#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//struct 结构体关键字
//创建一个结构体类型
struct Book
{
	char name[20];
	int price;
};
int main() {
	//创建一个结构体类型的变量
	struct Book b1 = { "C语言程序设计",55 };
	printf("书名：%s\n价格：%d\n",b1.name,b1.price);
	struct Book* pb = &b1;//结构体指针
	//改结构体变量的值
	b1.price = 10;
	//数组不能直接改
	strcpy(b1.name,"c++");//syrcpy字符串拷贝,要用string.h
						  
	//getchar()使用，输入键盘字符
	int ch1 = getchar();
	putchar(ch1);//输出字符，效果=↓
	printf("%c\n",ch1);
	//EOF- end of file 值为-1 键盘上输入为 ctrl+z
	/*char ch2 = 0;
	while ((ch2=getchar())!= EOF)
	{
		putchar(ch2);
	}*/
	//缓冲区冲突
	int ch3 = 0;
	char password[20] = { 0 };
	printf("输入密码：\n");
	scanf("%s", password);//输入密码，并存在password数组中
	//缓冲区还剩下一个'\n'或还剩下很多别的东西
	//读取一下，避免下一次getchar冲突读到'\n'
	while (ch3=getchar()!='\n')
	{
	}
	printf("确认（Y/N）\n");
	ch3 = getchar();
	if (ch3 == 'Y') {
		printf("确认成功\n");
	}
	else
	{
		printf("放弃确认\n");
	}



	return 0;

}




