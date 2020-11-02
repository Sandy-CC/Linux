#include"ch5.h"

int main(){
	char buf[20];
	int ret;

	FILE *fp=fopen("./tmp.txt","w+");
	if(!fp){
		printf("Fail to open file!");
	}
	ret=fwrite("123",sizeof("123"),1,fp);
	printf("We write %d block\n",ret);

	memset(buf,0,sizeof(buf));
	fseek(fp,0,SEEK_SET);
	ret=fread(buf,1,1,fp);
	printf("We read %s, ret is %d\n",buf,ret);
	fwrite("456",sizeof("456"),1,fp);
	fclose(fp);

	return 0;
}
