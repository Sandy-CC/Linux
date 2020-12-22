/*************************************************************************
    > File Name: 12-1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年12月07日 星期一 08时07分12秒
 ************************************************************************/

#include "ch12.h"
int main(int argc,char**argv)
{
	int fd[2],i;
	pid_t k;
	char buf[100];
	memset(buf,0,sizeof(buf));
	pipe(fd);
	k = fork();
	if(k<0){
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0){
		close(fd[1]);
		sleep(1);
		i=read(fd[0],buf,sizeof(buf));
		if(i==0){
			printf("child read failed!\n");
			exit(0);
		}
		else{
			fprintf(stdout,"read from pipe : %s\n",buf);
			exit(1);
		}
	}
	else{
		close(fd[0]);
		sprintf(buf,"%d say hello to %d!",getpid(),k);
		i=write(fd[1],buf,sizeof(buf));
		if(i==0){
			printf("parent write failed!\n");
			exit(0);
		}
		else{
			printf("write to pipe : %s\n",buf);
			exit(1);
		}
		wait(NULL);
		exit(0);
	}
	return 0; 
}

