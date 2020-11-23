#include "ch10.h"

int main()
{
	int r1,r2;
    r1=fork();
	if(r1<0)
	{
		perror("fork1 failed!\n");
		exit(-1);
	}
	else if(r1==0)
	{
		printf("child 1 : pid = %d,ppid = %d \n", getpid(),getppid());
		exit(0);
	}
	else
	{
        r2=fork();
        if(r2<0)
        	{
        		perror("fork2 failed!\n");
        		exit(-1);
        	}
        	else if(r2==0)
        	{
        		printf("child 2 : pid = %d,ppid = %d \n", getpid(),getppid());
        		exit(0);
        	}
        else{
            wait(NULL);
            wait(NULL);
            printf("parent : pid = %d ,r1 = %d ,r2 = %d \n", getpid(),r1,r2);
            return 0;
        }
	}
}
