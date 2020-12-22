#include "ch12.h"

int main()
{
	int fd1[2],fd2[2],i;
	pid_t k;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pipe(fd1);
	pipe(fd2);
	// if((pipe(fd))<0)
	// {
	// 	perror("pipe failed!\n");
	// 	exit(-1);
	// }
	k = fork();
	if(k<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd2[0]);
		i=read(fd1[0],buf,sizeof(buf));
		if(i<=0)
		{
			printf("child recieve failed!\n");
		}
		else
		{
			fprintf(stdout, "child %d recieve %s from parent! Total = %lu\n", getpid(),buf,strlen(buf));
		}
		sprintf(buf,"%d recieve %lu from %d\n",getpid(),strlen(buf),getppid());
		write(fd2[1],buf,strlen(buf));
		close(fd2[1]);
		close(fd1[0]);
		exit(0);
	}
	else
	{
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"%d say hello to %d\n",getpid(),k);
		i=write(fd1[1],buf,sizeof(buf));
		read(fd2[0],buf,sizeof(buf));
		printf("%d : %s\n", getpid(),buf);
		
		wait(NULL);
		close(fd1[1]);
		close(fd2[0]);
		return 0;
	}
}