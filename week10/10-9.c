#include"ch10.h"

int main(){
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        perror("error!\n");
        exit(-1);
    }
    else if(pid==0)
    {
        printf("child 1 %d is running!\n",getpid());
        exit(108);
    }
    else
    {
        int r1,s1,r2,s2,pid2;
        pid2=fork();
        if(pid2<0)
        {
            perror("error!\n");
            exit(-1);
        }
        else if(pid2==0)
        {
            printf("child 2 %d is running!\n",getpid());
            exit(99);
        }
        else
        {
            r1=waitpid(-1,&s1,0);
            r2=waitpid(-1,&s2,0);
            printf("parent %d will wxit now! r1 = %d, s1= %d\n",getpid(),r1,WEXITSTATUS(s1));
            printf("parent %d will wxit now! r2 = %d, s2= %d\n",getpid(),r2,WEXITSTATUS(s2));
            exit(0);
        }
    }
	return 0;
}
