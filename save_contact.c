#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <time.h>
#include "save_contact.h"
static int FindByname(const struct Contact* ps,char name[MAX_NAME]) {
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name)) {
			break;
		}
	}
	return i;
}

void CheckCapacity(struct Contact* ps) {
	if (ps->size == ps->capacity)
	{
		//增容
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL) {
			ps->data = ptr;
			ps->capacity += 2;
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void LoadContact(Contact* ps){
	PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead==NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead)) {
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	
	}

	fclose(pfRead);
	pfRead = NULL;


}

void InitContact(struct Contact* ps) {
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (ps->data == NULL) {
		return;
	}
	ps->size = 0;//设置通讯录最初只有0个元素
	ps->capacity = DEFAULT_SZ;

	//把文件中已经存放的通讯录信息加载到通讯录中
	LoadContact(ps);
}


void AddContact(struct Contact* ps) {
	//检测当前通讯录的容量
	//如果满了，增加空间
	//如果不满，不执行操作
	CheckCapacity(ps);
		printf("请输入名字:\n");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:\n");
		scanf("%d", &ps->data[ps->size].age);
		printf("请输入性别:\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:\n");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功:\n");
}

void ShowContact(const struct Contact* ps) {
	if (ps->size==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//数据
		for ( i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}
void DelContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要删除人的名字：\n");
	scanf("%s",name);
	//查找要删除的人在什么位置
	//找到返回下标
	int pos=FindByname(ps,name);
	//删除
	if (pos == ps->size)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++) {
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要查找的人的名字：\n");
	scanf("%s", name);
	
	int pos = FindByname(ps, name);
	if (pos==-1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps) {
	char name[MAX_NAME];
	printf("请输入要修改的人的名字：\n");
	scanf("%s", name);

	int pos = FindByname(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字:\n");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:\n");
		scanf("%d", &ps->data[pos].age);
		printf("请输入性别:\n");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:\n");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:\n");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功:\n");
	}
}
void SortContact(struct Contact* ps) {
	int i = 0;
	int j = 0;
	struct Contact con;
	InitContact(&con);
	for (j = ps->size; j >=0;j--) {
		for (i = 0; i < j- 1; i++)
		{
			if (ps->data[i].age > ps->data[i + 1].age)
			{
				con.data[0] = ps->data[i];
				ps->data[i] = ps->data[i + 1];
				ps->data[i + 1] = con.data[0];
			}
		}
	}
	printf("排序成功\n");
	
}

void DestroyContact(Contact* ps) {
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(Contact* ps) {
	FILE* pfWrite = fopen("contact.dat","wb");
	if (pfWrite==NULL)
	{
		printf("SaveContact:%s\n",strerror(errno));
		return ;
	}
	//写通讯录中数据到文本文件中
	int i = 0;
	for ( i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;

}

