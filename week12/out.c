#include "ch12.h"

int main(int argc, char *argv[])
{
	int i;
	int fd;
	fd=open("out.dat",O_CREAT|O_RDWR|O_APPEND,0644);
	close(1);
	dup(fd);
	printf("dup1 pid = %d\n", getpid());
	for (i = 0; i < argc; ++i)
	{
		printf("argv[%d]:%s\n", i, argv[i]);
	}
	return 0;
}