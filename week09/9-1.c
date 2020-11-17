#include "ch09.h"

int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		fprintf(stderr,"failed to fork.Reason(%s)",strerror(errno));
		exit(-1);
	}
	else if(pid==0)
	{
		printf("child : pid = %d,ppid = %d return from fork = %d\n", getpid(),getppid(),pid);
		exit(0);
	}
	else
	{
		printf("parent : pid = %d,ppid = %d return from fork()=%d\n", getpid(),getppid(),pid);
		return 0;
	}
}