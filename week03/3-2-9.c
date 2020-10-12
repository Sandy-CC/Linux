#include"ch2.h"
int main(){
	FILE *fp;
	char buf[80];
	memset(buf,0,sizeof(buf));
	fp=fopen("./test2.txt","a");
	fputs("\tappend new information",fp);
	fp=freopen("./test2.txt","r",fp);
	fgets(buf,sizeof(buf),fp);
	printf("Content of file is %s\n",buf);
	fclose(fp);
	return 0;
}
