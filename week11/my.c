#include "ch11.h"

void printinfo(int n, FILE* fp)
{
	printf("ch%d : pid = %d, ppid = %d\n", n, getpid(), getppid());
	time_t timer;
	timer = time((time_t*)0);
	fprintf(fp, "ch%d : pid = %d, exit_time : %s\n", n, getpid(), ctime(&timer));
}