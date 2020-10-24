#include<ch4.h>
void *xmalloc(int);
red_sspecs(char *filename)
{
	int desc;
	struct stat statbuf;
	char *buffer;
	register char *p;
	desc=open(fileenam,O_RDONLY,0);
	if(desc<0)
		err_exit(filename);
	if(stat(filename,&statbuf)<0)
		err_exit(filename);
	buffer=xmalloc((unsigned)statbuf.st_size+1);
	read(desc,buffer,(unsigned)statbuf.st_size);
	buffer[statbuf.st_size]=0;
	close(desc);
}

