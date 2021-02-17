#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
struct S
{
	int n;
	float score;
	char arr[10];
};

int main(){
	//C语言文件操作

	//	·什么是文件
	//	磁盘上的文件是文件。
	//	但是在程序设计中，我们一般谈的文件有两种：程序文件、数据文件
	//	程序文件
	//		包括源程序文件（后缀为.c），目标文件（windows环境后缀为.obj），可执行程序（windows环境后缀为exe)。
	//	数据文件
	//		文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件。
	
	//	·文件名
	//	一个文件要有一个唯一的文件标识，以便用户识别和引用。
	//	文件名包含3部分：文件路径 + 文件名主干 + 文件后缀
	//	例如：c:\code\test.txt
	//	为了方便起见，文件标识常被称为文件名。
	//	·文件类型
	//	根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
	//	数据在内存中以二进制的形式存储，如果不加转换的输出到外存，就是二进制文件。
	//	如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。以ASCII字符的形式存储的文件就是文本文件。
	//	字符一律以ASCII形式存储，数值型数据既可以用ASCII形式存储，也可以使用二进制形式存储。
	//	如有整数10000，如果以ASCl码的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输出，则在磁盘上只占4个字节（VS2013测试）。
	int a = 10000;
	FILE* pf1 = fopen("test.txt", "wb");
	fwrite(&a, 4, 1, pf1);//二进制的形式写到文件中
	fclose(pf1);
	pf1 = NULL;
	
	//	·文件缓冲区
	//	ANSIC标准采用“缓冲文件系统“处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在
	//	使用的文件开辟一块文件缓冲区”从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘
	//	上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后再从缓冲区逐
	//	个地将数据送到程序数据区（程序变量等）。缓冲区的大小根据C编译系统决定的。
	
	//	·文件指针
	//	缓冲文件系统中，关键的概念是文件类型指针”，简称文件指针”。
	//	每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件的名字，文件状态及
	//	文件当前的位置等）。这些信息是保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE
	
	//  不同的C编译器的FILE类型包含的内容不完全相同，但是大同小异。
	//	每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息，使用者不必关心细节。
	//	一般都是通过一个FILE的指针来维护这个FILE结物的变量，这样使用起来更加方便。

	//	定义pf是一个指向FILE类型数据的指针变量。可以使pf指向某个文件的文件信息区（是一个结构体变量）。通过该文
	//	件信息区中的信息就能够访问该文件。也就是说，通过文件指针变量能够找到与它关联的文件
	
	//	·文件的打开和关闭
	//	文件在读写之前应该先打开文件，在使用结束之后应该关闭文件。
	//	在编写程序的时候，在打开文件的同时，都会返回一个FILE*的指针变量指向该文件，也相当于建立了指针和文件的关系。
	//	ANSIC规定使用fopen函数来打开文件，fclose来关闭文件。 
	//	打开：
	//	FILE * fopen ( const char* filename,const char * mode); 
	//	文件使用方式						含义							如果指定文件不存在			
	//	"r"(只读)			为了输入数据，打开一个已经存在的文本文件		出错					
	//	"w"(只写)			为了输出数据，打开一个文本文件					建立一个新的文件		
	//	"a"(追加)			向文本文件尾添加数据							出错			
	//	"rb"(只读)			为了输入数据，打开一个二进制文件				出错			
	//	"wb"(只写)			为了输出数据，打开一个二进制文件				建立一个新的文件			
	//	"ab"(追加)			向一个二进制文件尾添加数据						出错				
	//	"r+"(读写)			为了读和写，打开一个文本文件					出错				
	//	"w+"(读写)			为了读和写，建立一个新的文件					建立一个新的文件		
	//	"a+"(读写)			打开一个文件，在文件尾进行读写					建立一个新的文件       
	//	"rb+"(读写)			为了读和写打开一个二进制文件					出错                  
	//	"wb+"(读写)			为了读和写，新建一个新的二进制文件				建立一个新的文件                 
	//	"ab+"(读写)			打开一个二进制文件，在文件尾进行读和写		 	建立一个新的文件					    
	//	相对路径
	//	fopen("text.txt", "r");
	//	..表示上一级路径
	//	.表示当前路径
	//	fopen("../text.txt", "r");
	//	绝对路径的写法
	//	fopen("C:\\asdasd\\text.txt","r");
	//	关闭：
	//	int fclose(FILE* stream);

	//	·文件的顺序读写
	//	功能											函数										适用于						
	//	字符输入函数	int fgetc(FILE* stream)														所有输入流								
	//	字符输出函数	int fputc(FILE* stream)														所有输出流									
	//	文本行输入函数	char* fgets(char* string,int n,FILE* stream)								所有输入流																	
	//	文本行输出函数	char* fputs(const char* string,int n,FILE* stream)							所有输出流					
	//	格式化输入函数	int fscanf(FILE* stream,const char* format[,argument]...)					所有输入流										
	//	格式化输出函数	int fprintf(FILE* stream,const char* format[,argument]...)					所有输出流								
	//	二进制输入		size_t fread(const void* buffer,size_t size,size_t count,FILE* stream)		文件																				
	//	二进制输出		size_t fwrite(const void* buffer,size_t size,size_t count,FILE* stream)		文件						
	//	FILE* pf = fopen("xxx.txt","看情况定");
	//	if (pf == NULL) {
	//		return 0;
	//	}
	//	字符输入输出
	//	int ch = fgetc(pf);
	//	printf("%c", ch);
	//	fputc(pf);
	//	文本行输入输出
	//	char buf[1024] = { 0 };
	//	fgets(buf, 100, pf);
	//	printf("%s", buf);
	//	fputs(buf, 100, pf);
	//	格式化的形式输入输出
	//	struct S s = { 100,3.14f,"bit" };
	//	fprintf(pf, "%d %f %s", &(s.n),&(s.score),s.arr);
	//	struct S tmp = { 0 };
	//	fscanf(pf,"%d %f %s",&(tmp.n),&(tmp.score),tmp.arr);
	//	sscanf是从字符串中读取格式化的数据
	//	sprintf是把格式化数据输出成（存储到）字符串
	//	二进制输入输出
	//	fwrite(&s,sizeof(struct S),1,pf);
	//	fread(&tmp,sizeof(struct S),1,pf);
	//	printf("%d %f %s",&(tmp.n),&(tmp.score),tmp.arr);

	//	从键盘输入
	//	输出到屏幕
	//	键盘&屏幕都是外部设备
	//	键盘 - 标准输入设备 - stdin
	//	屏幕 - 标准输出设备 - stdout
	//	是一个程序默认打开的两个流设备
	int ch = fgetc(stdin);
	fputc(ch, stdout);
	//	·文件的随机读写
	//	根据文件指针的位置和偏移量来定位文件指针。
	//	fseek
	//	int fseek(FILE* stream, long int offset(偏移量), int origin(文件指针的当前位置));
	//	FILE* pf=fopen("xxx.txt","r");
	//	if(pf==NULL){
	//		return 0;			
	//	}
	//	1.定位文件指针
	//	origin有三个选项
	//	SEEK_CUR 文件指针的当前位置
	//	SEEK_END 文件的末尾位置
	//	SEEK_SET 文件起始位置
	//	fseek(pf,2,SEEK_CUR);
	//	2.读取文件									
	//	int ch=fgetc(pf);													
	//	fclose(pf);														
	//	pf=NULL;												
	//	ftell											
	//	返回文件指针相对于起始位置的偏移量					
	//	1ong int fte11(FILE* stream);								
	//	int pos=ftell(pf);									
	//	printf("%d\n",pos);								
	//	rewind												
	//	让文件指针的位置回到文件的起始位置								
	//	void rewind(FILE* stream);								
	//	rewind(pf);													
	//	·文件结束的判定								
	//  被错误使用的feof	
	//	int feof(FlLE *stream)
	//	牢记：在文件读取过程中，不能用feof函数的返回值直接用来判断文件的是否结束。									
	//	而是应用于当文件读取结束的时候，判断是读取失败结束，还是遇到文件尾结束。								
	//	1.文本文件读取是否结束，判断返回值是否为EOF（fgetc)，或者NULL（fgets)								
	//		fgetc判断是否为EOF																				
	//		fgets判断返回值是否为NULL												
	//	2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数			
	//		fread判断返回值是否小于实际要读的个数							
	//	
	return  0;
}