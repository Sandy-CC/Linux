#include "ch09.h"


int main()
{
	pid_t pid;
    int l=99;
    int *pt=malloc(sizeof(int));
    char *string="test string!\n";
    *pt=9999;
    printf("%d:--------Before Fork---------",getpid());
    pid = vfork();
    if(pid<0)
    {
        fprintf(stderr,"failed to fork.Reason(%s)",strerror(error));
        exit(-1);
    }
    else if(pid==0)
    {
        printf("child: pid = %d, ppid = %d return from fork = %d\n",getpid(),getppid(),pid);
        printf("child: init g=%d,l=%d,*pt=%d\n",g,l,*pt);
        g++;
        l++;
        (*pt)++;
        printf("child: g=%d %x,l=%d %x,*pt=%d %x\n",g,&g,l,&l,*pt,pt);
        printf("child: string =%s\n",string);
        exit(0);
    }
    else
    {
        sleep(2);
        printf("child: pid = %d, ppid = %d return from fork = %d\n",getpid(),getppid(),pid);
        printf("child: init g=%d,l=%d,*pt=%d\n",g,l,*pt);
        g++;
        l++;
        (*pt)++;
        printf("child: g=%d %x,l=%d %x,*pt=%d %x\n",g,&g,l,&l,*pt,pt);
        printf("child: string =%s\n",string);
        return 0;
    }
}
