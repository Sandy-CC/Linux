#include"ch8.h"

int main()
{
    int *pt=NULL;
    int i,max;
    max=1024*1024;
    for(i=0;i<max;i++)
    {
        pt=(int *)malloc(i*max);
        if(!pt)
        {
            perror("malloc failed!\n");
            exit(-1);
        }
        else
        {
            printf("malloc %d MB\n",i);
            free(pt);
        }
    }
	return 0;
}
