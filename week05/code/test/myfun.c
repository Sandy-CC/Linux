#include"my.h"

recorder* input(void){
    recorder *pt;
    pt=(recorder*)malloc(sizeof(recorder*));
    //printf("Please input the id:");
    //scanf("%d",&(pt->id));
    pt->id=++count;
    printf("Please input the name:");
    scanf("%s",pt->name);
    printf("Please input the htel:");
    scanf("%s",pt->htel);
    printf("Please input the tel:");
    scanf("%s",pt->tel);
    return pt;
}

int save(recorder *pt){
	FILE *fp;
	fp=fopen("user.dat","a+");
	if(fp==NULL){
		printf("Fail to open the file!\n");
		exit(0);
	}
    fprintf(fp,"%d %s %s %s\n",pt->id,pt->name,pt->htel,pt->tel);
    fclose(fp);
    return 1;
}

int mysort(int way){
    return 1;
}

int output(void){
    recorder Contacts[count];
    FILE  *fp;
    int i;
    fp=fopen("user.dat","r");
    if(fp==NULL){
		printf("Fail to open the file!\n");
		exit(0);
	}
    fread(Contacts,sizeof(recorder),count,fp);
    printf("\n\nid\tname\thtel\ttel\n");
    for(i=0;i<count;i++){
        printf("%d\t%s\t%s\t%s\n",Contacts[i].id,Contacts[i].name,Contacts[i].htel,Contacts[i].tel);
    }
    fclose(fp);
    return 1;
}
