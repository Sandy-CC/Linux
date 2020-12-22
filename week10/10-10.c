#include "ch10.h"

int main()
{
	pid_t p1;
	p1=fork();
	if(p1<0)
	{
		printf("error!\n");
		exit(-1);
	}
	else if(p1==0)
	{
		printf("child1 %d is running !\n",getpid());
		while(1);
		exit(108);
	}
	else{
		int r1,r2,s1,s2,p2;
		p2 = fork();
		if(p2<0)
		{
			printf("error!\n");
			exit(-1);
		}
		else if(p2==0)
		{
			printf("child2 %d is running !\n",getpid());
			exit(99);
		}
		else
		{
			r1 = waitpid(p1,&s1,WNOHANG);
			r2 = waitpid(p2,&s2,0);
			printf("parent %d will exit now! r1 = %d, s1 = %d\n",getpid(),r1,WEXITSTATUS(s1));
			printf("parent %d will exit now! r2 = %d, s2 = %d\n",getpid(),r2,WEXITSTATUS(s2));
			exit(0);
		}
	}
	return 0;
}