#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<time.h>
int main(){
	
	FILE *fp;
	time_t seconds;
	pid_t pid1,pid2;
	fp=fopen("./out.dat","a+");//打开out文件
	if(fp==NULL){
		perror("open failed!");
		exit(1);
	}
	
	//创建第一个子进程
	
	if((pid1=fork())<0){
		perror("pid1 fork failed!");
		exit(1);
	}else if(pid1>0){
		wait(NULL);
	}else{
		//第一个子进程写入文件
		seconds=time(NULL);
		fprintf(fp,"%d\t",getpid());
		fprintf(fp,"%ld\n",seconds);
		fflush(fp);
		pid_t pid11,pid12;
		//第一个子进程的第一个子进程
		if((pid11=fork())<0){
			perror("pid11 fork failed!");
			exit(1);
		}else if(pid11>0){
			wait(NULL);
		}else{
			int id=0;
			seconds=time(NULL);
			//第一个子进程的第一个子进程写入文件
			fprintf(fp,"%d\t",getpid());
			fprintf(fp,"%ld\n",seconds);
			exit(1);
		}
		
		//第一个子进程的第二个子进程
		if((pid12=fork())<0){
			perror("pid11 fork failed!");
			exit(1);
		}else if(pid12>0){
			wait(NULL);
		}else{
			int id=0;
			seconds=time(NULL);
			//第一个子进程的第二个子进程写入文件
			fprintf(fp,"%d\t",getpid());
			fprintf(fp,"%ld\n",seconds);
			exit(1);
		}
		
		exit(1);
	}
	
	//创建第二个子进程

	if((pid2=fork())<0){
		perror("pid2 fork failed!");
		exit(1);
	}else if(pid2>0){
		wait(NULL);
	}else{
		//第一个子进程写入文件
		seconds=time(NULL);
		fprintf(fp,"%d\t",getpid());
		fprintf(fp,"%ld\n",seconds);
		fflush(fp);
		pid_t pid21,pid22;
		//第一个子进程的第一个子进程
		if((pid21=fork())<0){
			perror("pid11 fork failed!");
			exit(1);
		}else if(pid21>0){
			wait(NULL);
		}else{
			int id=0;
			seconds=time(NULL);
			//第一个子进程的第一个子进程写入文件
			fprintf(fp,"%d\t",getpid());
			fprintf(fp,"%ld\n",seconds);
			exit(1);
		}
		
		//第一个子进程的第二个子进程
		if((pid22=fork())<0){
			perror("pid11 fork failed!");
			exit(1);
		}else if(pid22>0){
			wait(NULL);
		}else{
			int id=0;
			seconds=time(NULL);
			//第一个子进程的第二个子进程写入文件
			fprintf(fp,"%d\t",getpid());
			fprintf(fp,"%ld\n",seconds);
			exit(1);
		}
		
		exit(1);
		
	}
	
	return 0;
}
