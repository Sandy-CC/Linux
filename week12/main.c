#include "ch12.h"
int main(void){
	int fd1[2],fd2[2],fd3[2],fd4[2];
	pid_t pid1,pid2;
	int count = 0,maxCount = 1;
	char buf[100];
	memset(buf,0,sizeof(buf));
	if(pipe(fd1) < 0 || pipe(fd2) < 0 || pipe(fd3) < 0 || pipe(fd4) < 0){
		perror("pipe failed!\n");
		exit(-1);
	}
	
	pid1 = fork();
	if(pid1 < 0){
		perror("child1 fork failed!\n");
		exit(-1);
	}
	else if(pid1 == 0){
		close(0);
		dup(fd1[0]);
		//close(fd1[0]);
		if(count % 2 == 0){
			count++;
			sprintf(buf,"%d : child1 say to child2!\n",count);
			write(fd1[1],buf,strlen(buf));
		}
		
		
	}
	else{
		pid2 = fork();
		if(pid2 < 0){
			perror("child2 fork failed!\n");
			exit(-1);
		}
		else if(pid2 == 0){
		/*
			close(fd3[1]);
			close(0);
			dup(fd3[0]);
			if(count % 2 == 1){
				count++;
				sprintf(buf,"%d : child2 say to child1!\n",count);
				write(fd1[0],buf,strlen(buf));
			}
			close(fd1[0]);
		*/
			
		}
		else{
			FILE *fp = fopen("./talk.dat","a+");
			// int tmp = 0;
			dup(fileno(fp));
			while(fgets(buf,sizeof(buf),stdin) != NULL && count <= maxCount){
				fputs(buf,stdout);
			}
			
			/*
			while(count < 88){
				if(tmp == count){
					continue;
				}
				tmp = count;
				scanf("%s",buf);
				write(fd,buf,strlen(buf));
				
			}
			*/
			/*
			while(scanf("%s",buf) != -1){
				write(fd,buf,strlen(buf));
			}*/
			fclose(fp);
			return 0;
		}
	}
}