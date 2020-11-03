#include"ch7.h"

int main(int argc,char *argv[])
{
	int x,y;
	if(argc!=3)
	{
		printf("Agument failed!\n");
		exit(0);
	}
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	printf("%d + %d = %d\n",x,y,x+y);
    for(int i=0;i<argc;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}
	return 0;
}
