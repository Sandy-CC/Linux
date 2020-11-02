#include<stdio.h>
#include<string.h>
//confirm gets() is danger

struct Buffer{
    char buf1[8];
    char buf2[8];
}buffer;

int main()
{

	memset(buffer.buf1,'\0', sizeof(buffer.buf1));
	memset(buffer.buf2,'\0', sizeof(buffer.buf2));
    printf("buf1:%s\nbuf2:%s\n", buffer.buf1, buffer.buf2);
    printf("input >= 8 char into buf1: ");
    gets(buffer.buf1);
    fprintf(stdout,  "buf1:%s\nbuf2:%s\n", buffer.buf1, buffer.buf2);
    return 0;
}




















