#include"ch4.h"

char buf1[]="abcdefghij";
char buf2[]="0123456789";

int main(){
	if((fd=open("file.hole.2",O_WRONLY|O_CREAT|O_APPEND,0644))<0){
		err_exit("Create error!");
	}
	if(write(fd,buf1,10)!=10){
		err_exit("Write error!");
	}
	if(lseek(fd,40,SEEK_SET)==-1){
		err_exit("Lseek error!");
	}
	if(write(fd,buf2,10)!=10){
		err_exit("Write error");
	}
	return 0;
}
