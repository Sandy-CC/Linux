#include "ch10.h"

int main()
{
	int r1,r2;
    r1=fork();
    r2=fork();
	if(r1<0||r2<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(r1==0)
	{
		printf("child 1 : pid = %d,ppid = %d \n", getpid(),getppid());
		exit(0);
	}
    else if(r2==0)
	{
		printf("child 2 : pid = %d,ppid = %d \n", getpid(),getppid());
		exit(0);
	}
	else
	{
		printf("parent : pid = %d ,r1 = %d ,r2 = %d \n", getpid(),r1,r2);
		return 0;
	}
}
