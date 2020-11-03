#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

unsigned int count=0;

typedef struct user{
	int id;
	char name[8];
	char htel[12];
	char tel[12];
}recorder;

recorder* input(void);
int save(recorder* pt);
int  mysort(int way);
int output(void);
