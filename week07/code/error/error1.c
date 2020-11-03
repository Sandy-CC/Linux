#include"../ch7.h"
int *p;
int main()
{
	int *q;
	*p=1;
	*q=2;
	printf("*p=%d,*q=%d\n",*p,*q);
	return 0;
}
