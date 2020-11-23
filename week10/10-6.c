#include"ch10.h"

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		printf("10-6 child : pid = %d,ppid = %d \n",getpid(),getppid());
		execl("./test","./test","Hello","World",NULL);
		printf("10-6 child end!\n");
		exit(1);
	}
	else
	{
		int r,s;
		
		r=wait(&s);
		printf("10-6 : r = %d, status = %d\n",r,WEXITSTATUS(s));
		return 0;
	}
}
