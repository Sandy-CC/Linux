#include"ch8.h"

static int count=0;

int fun(int x){
    int a=10,b=10,c=10;
    count++;
    printf("count = %d\t",count);
    printf("local a = %8x,b = %8x,c = %8x\n",&a,&b,&c);
    if(x==1)
        return 1;
    return x+fun(x-1);
}

int main()
{
    printf("sum %d = %d\n",1024*1024*10,fun(1024*1024*10));
    return 0;
}
