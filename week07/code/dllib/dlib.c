#include"../ch7.h"
void dynamic_lib_call(void)
{
	printf("dynamic lib call\n");
}
void dsum(int max){
    int i;
    int sum=0;
    for(i=1;i<=max;i++)
        sum=sum+i;
    printf("sum = %d\n",sum);
}
