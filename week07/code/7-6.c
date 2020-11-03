#include"ch7.h"
int main(int atgc,char *argv[],char *env[])
{
	extern char** environ;
	int i;
	for(i=0;environ[i];i++)
		printf("environ[%d]=%s\n",i,environ[i]);
	for(i=0;env[i]!=NULL;i++)
		printf("env[%d]=%s\n",i,env[i]);
	printf("PATH = %s\n",getenv("PATH"));
	return 0;
}
