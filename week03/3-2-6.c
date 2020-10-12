#include"ch2.h"
int main(int argc,char *argv[]){
    FILE *fp;
    int i;
    if((fp=fopen("./test1.txt","w"))==NULL)
	    perror("open failed!\n");
    for(i=0;i<argc;i++){
        fprintf(fp,"%s",argv[i]);
        printf("[%d]\t%s\t%ldbyte\n",i,argv[i],strlen(argv[i]));
    }      
    fclose(fp);
    return 0;
}
