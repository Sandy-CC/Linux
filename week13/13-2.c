#include "ch13.h"
int main()
{
	int fifo_fd,n,total_bytes = 0;
	char readbuf[PIPE_BUF];
	// 如果FIFO不存在，创建它
	if(access(FIFO_FILE,F_OK)==-1)
		if(mkfifo(FIFO_FILE,0666)!=0)
		{
			printf("Could not create fifo %s\n", FIFO_FILE);
			exit(EXIT_FAILURE);
		}
	// 打开此FIFO文件
	if((fifo_fd = open(FIFO_FILE,O_RDONLY))<0)
	{
		printf("Could not open fifo %s\n", FIFO_FILE);
		exit(EXIT_FAILURE);
	}
	printf("Process %d opened: %s\n", getpid(),FIFO_FILE);
	while((n = read(fifo_fd,readbuf,PIPE_BUF)) > 0)
	{
		printf("%d received %d bytes\n", getpid(),n);
		total_bytes += n;
	}
	close(fifo_fd);
	printf("Process %d received total %d bytes \n", getpid(),total_bytes);
	return 0;
}