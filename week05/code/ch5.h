#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<time.h>

void err_exit(char *s){
    printf("USAGE:*s is failed!\n");
    exit(1);
}
