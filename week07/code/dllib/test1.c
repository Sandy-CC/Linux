#include"../ch7.h"
extern void dynamic_lib_call(void);
extern void dsum(int max);
int main()
{
	void *dlib=dlopen("./libdlib.so",RTLD_NOW);
	if(!dlib)
	{
		printf("dlopen failed!\n");
		exit(-1);
	}
	void(*dfunc) (void)=dlsym(dlib,"dynamic_lib_call");
    void(*dfunc1) (int)=dlsym(dlib,"dsum");
	if(!dfunc||!dfunc1)
	{
		printf("dfunc is failed!\n");
		exit(-1);
	}
	dfunc();
	dfunc1(10);
	dlclose(dlib);
	return 0;
}
