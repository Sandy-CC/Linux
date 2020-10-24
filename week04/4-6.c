#include"ch4.h"

int main(){
	int d1,d2;
	d1=open("./out.info",O_CREAT|O_TRUNC|O_WRONLY,0644);
	dup2(d1,1);
/*
    d1=dup(STDOUT_FILENO);
*/
    printf("Redirect stdout file!\n");
	return 0;
}
