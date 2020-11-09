#include"../ch8.h"

int main()
{
    int a[5]={10,7,2,1,4};
	void *fpt=dlopen("./libdlib.so",RTLD_NOW);
	if(!fpt){
		printf("dlopen failed!\n");
		exit(0);
	}
	void (*fp1)(void)=dlsym(fpt,"dynamic_lib_fun_call");
    void (*fp2)(int*,int)=dlsym(fpt,"mysort");
	if(!fp1||!fp2)
	{
		printf("Dlsym Failed!\n");
		exit(0);
	}
	fp1();
    fp2(a,5);
	dlclose(fpt);
	return 0;
}
