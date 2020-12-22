#include "my.c"

int main()
{
	FILE *fp;
	fp=fopen("log.dat","a+");

	pid_t pid1;
	pid1 = fork();
	if(pid1 < 0)
	{
		perror("pid1 fork failed!\n");
		exit(-1);
	}

	else if(pid1 == 0)
	{
		pid_t pid11;
		pid11 = fork();
		if(pid11 < 0)
		{
			perror("pid11 fork failed!\n");
			exit(-1);
		}
		else if(pid11 == 0)
		{
			wait(NULL);
			sleep(2);
			printinfo(11,fp);
			exit(0);
		}
		else
		{
			wait(NULL);
			sleep(2);
			printinfo(1,fp);
			exit(0);
		}
	}
	else
	{
		pid_t pid2;
		pid2 = fork();
		if(pid2 < 0)
		{
			perror("pid2 fork failed!\n");
			exit(-1);
		}
		else if(pid2 == 0)
		{
			pid_t pid21;
			pid21 = fork();
			if(pid21 < 0)
			{
				perror("pid21 fork failed!\n");
				exit(-1);
			}
			else if(pid21 == 0)
			{
				wait(NULL);
				sleep(2);
				printinfo(21,fp);
				exit(0);
			}
			else
			{
				wait(NULL);
				sleep(2);
				printinfo(2,fp);
				exit(0);
			}
		}
		else
		{
			wait(NULL);
			sleep(2);
			printinfo(0,fp);
			fclose(fp);
			exit(0);
		}
	}
	return 0;
}