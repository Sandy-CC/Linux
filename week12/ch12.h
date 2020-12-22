#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include <dlfcn.h>
#include <errno.h>
#include <time.h>


// #define INFILE "./in.txt"
// #define OUTFILE "./out.txt"
// #define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

// void err_exit(char*s){

// 	printf("Usage : %s is faild\n",s);
// 	exit(0);
// }
