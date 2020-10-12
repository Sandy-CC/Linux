#include"ch2.h"

int main(){
	int fd;
	FILE *fp;
	fd=open("./test1.txt",O_RDWR);
	fp=fdopen(fd,"w+");
	fprintf(fp,"test data %s\n","hello world 3-2-8");
	fclose(fp);
}
