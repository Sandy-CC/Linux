#include"ch5.h"

int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	printf("Hello world!\n");
	while(1);
	return 0;
}
