#include"ch2.h"

int main(){
	int fd;
	fd=open("./test1.txt",O_CREAT,0644);
	printf("file fd = %d\n",fd);
	close(fd);
	return 0;
}
