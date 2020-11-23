#include"ch10.h"

void foo(){
    fprintf(stderr,"foo say bye!\n");
}

void bar(){
    fprintf(stderr,"bar say bye!\n");
}

int main(int argc,char **argv){
	atexit(foo);
    atexit(bar);

    //fprintf(stdout,"Oop ~~~~forget a newline!");
    fprintf(stdout,"Oop ~~~~forget a newline!\n");
	sleep(2);
    if(argc>1 && strcmp(argv[1],"exit")==0)
        exit(0);
    if(argc>1 && strcmp(argv[1],"_exit")==0)
        _exit(0);
	return 0;
}
