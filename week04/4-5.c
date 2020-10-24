#include"ch4.h"

int main(){
	int d1,d2;
	char buf[5];
	memset(buf,0,5);
	d1=open("file.hole",O_RDONLY);
	d2=dup(d1);
	printf("d1=%d,d2=%d",d1,d2);
	lseek(d1,5,SEEK_SET);
	read(d2,buf,4);
	printf("buf:%s\n",buf);
	return 0;
}
