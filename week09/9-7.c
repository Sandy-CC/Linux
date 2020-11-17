#include "ch09.h"


int main()
{
	int pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        perror("Vfork failed!\n");
        exit(-1);
    }
    else if(pid==0)
    {
        printf("child: pid = %d, ppid=  %d\n",getpid(),getppid());
        exit(23);
    }
    else
    {
        y=wait(&s);
        if(WIFEIXTED(s))
            printf("child %d is normal back. The exit code = %d\n",y);
        return 0;
    }
}
