#include"../ch7.h"
#define N 10
int a[N],i;
int main()
{
	for(i=0;i<N;i++)
    {
		a[i]=i+1;
	}
    	printf("i = %d\n",i);
    a[N]=123456789;
    printf("i = %d\n",i);
	printf("%d\n",a[N]);
	return 0;
}
