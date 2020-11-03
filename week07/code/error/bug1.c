#include"../ch7.h"
int *p,x;
int main()
{
	int *q;
    p=(int*)malloc(sizeof(int));
	*p=1;
	q=(int*)malloc(sizeof(int));
    q=&x;
	*q=2;
	printf("*p=%d,*q=%d\n",*p,*q);
	return 0;
}
