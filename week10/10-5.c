#include"ch10.h"

int main(){
	int r;
	printf("10-5 : pid = %d, ppid = %d \n",getpid(),getppid());
	r=execl("./test","./test","./hello","world",NULL);
	system("./test hello world 2020 11 23\n");
	printf("After Calling!\n");
}
