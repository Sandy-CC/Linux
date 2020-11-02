#include<stdio.h>
#include <stdlib.h>
#include<string.h>

char* readFile(char* filename, int index);
void saveFIle();

int main()
{
	saveFIle();
	char* i;
	i = readFile("test.txt",5);
	printf("item is %s\n", i);
	return 0;
}

//查询指定序号的记录内容
char* readFile(char* filename, int index)
{
	FILE* f;

	if ((f = fopen(filename, "rb")) == NULL)
	{
		printf("open err");
		exit(0);
	}

    //读取记录总数 保存到length
	int length = 0;
	fread(&length, sizeof(int), 1, f);

    //查询序号的溢出判断
	if (index > length)
	{
		printf("out of file length");
	}

	int place = 0;
	int itemSize = 0;
	int i;
    //辅助计算偏移量
	for (i = 0; i < index; i++)
	{
		int size = 0;
		fread(&size, sizeof(int), 1, f);
		place += size;
		itemSize = i == index - 1 ? size : 0;
	}

    //将文件指针定位到要读取的记录起始处
	fseek(f, (length + 1) * sizeof(int) + place - itemSize, SEEK_SET);

	char* item;
	item = malloc(itemSize);
	memset(item, 0, itemSize);

    //从文件中读取相应内容并保存至item
	fread(item, itemSize, 1, f);

	fclose(f);
	return item;
}

//创建符合题意的可查询文件
void saveFIle()
{

	FILE* f = fopen("test.txt", "w+");
	fseek(f, 0, SEEK_END);

    //第一个字（四个字节）记录总数量
	int a = 5;
	fwrite(&a, sizeof(int), 1, f);

    //每一条记录的长度
	int length[] = { 1,2,3,4,5 };
    //每一条记录的具体内容
	char* item[] = { "a", "ab", "abc", "abcd", "abcde" };


	int i = 0;
	for (i = 0; i < a; i++)
	{
		fwrite(&length[i], sizeof(int), 1, f);
	}


	for (i = 0; i < a; i++)
	{
		fwrite(item[i], strlen(item[i]), 1, f);
	}


	fclose(f);
}
