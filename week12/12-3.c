#include "ch12.h"

int main()
{
	pid_t pid;
	int fd[2];
	char buffer[100];
	if(pipe(fd)!=0)
	{
		perror("pipe failed!\n");
		exit(-1);
	}

	pid = fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}

	else if(pid==0)
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);

		char *argv[] = {"test","hello","world",NULL};
		execvp("./out",argv);
		exit(88);
	}

	else
	{
		wait(NULL);
		close(0);
		dup(fd[0]);
		close(fd[1]);

		// execl("./test");

		// while(gets(buffer)!=NULL)
		// {
		// 	puts(buffer);
		// }
		// return 0;
	}

	return 0;
}