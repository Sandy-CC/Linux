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

#define PIPE_BUF 100

#define BUFFER_SIZE 132
#define SERVER_FIFO_NAME "./tmp/serv_fifo"
#define CLIENT_FIFO_NAME "./tmp/client_%d_fifo"

#define FIFO_FILE "./testfifo"
#define TEN_MEG 1000
#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH

void err_exit(char*s){

	printf("Usage : %s is faild\n",s);
	exit(0);
}

struct data_to_pass
{
	pid_t client_pid;
	char data[BUFFER_SIZE];
};
