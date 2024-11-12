#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAXLINE 100
#define MAXARG 50

int stringSlice(char cmd[],char *args[]){
	char *ptr;
	char *next;
	int i = 0;
	
	args[i] = strtok_r(cmd, " ", &next);
	if(args[i] == NULL) return i;

	for(i = 1; i < MAXARG; i++){
		args[i] =  strtok_r(NULL, " ", &next);
		if(args[i] == NULL) break;
	}
	
	return i;
}

int main(void){
	char cmd[MAXLINE];
	char *args[MAXARG];
	int status;
 	int pid;

	while(1){
		int len;
		int pid;
		int ch;

		printf("pis input cmd : ");
		fgets(cmd, MAXLINE, stdin);
		cmd[strlen(cmd) - 1] = '\0';
	
		len = stringSlice(cmd, args);
		ch = args[len - 1][0] == '&' ? 0 : 1;
		
		if(ch == 0)
			args[len - 1] = NULL;

		
		if((pid = fork()) == 0){
			if(!ch){ 
				int chStatus;

				if(fork() == 0){
					execvp(args[0], args);
					exit(1);
				}else{
					printf("[%d] child process start\n", getpid());
				}

				wait(&chStatus);
				if(WEXITSTATUS(chStatus) != 0) exit(1);
              	
                printf("[%d] child process end %d\n", getpgrp(), getpid());
				exit(0);
			}

			execvp(args[0], args);
            exit(1);
			
		}else{
			printf("[%d] Parent process start\n", getpid());
		}
		
		if(ch){
			waitpid(pid, &status, 0);

			if(WEXITSTATUS(status) != 0){
				printf("Parent process end\n");
				break;
			}else{
				printf("SUCCESS\n\n");
			}
		}
	}

	printf("Exit\n");
	exit(0);
}
