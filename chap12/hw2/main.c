#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 100

int main(void){

	char line[MAX_LINE];
	int fd[2];
	int pid1, pid2, status, i;

	pipe(fd);
	
	if((pid1 = fork()) == 0){
		printf("input string: ");
		fflush(stdout);

		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		
		fgets(line, sizeof(line), stdin);
		printf("%s", line);

		exit(1);
	}else{
		printf("parent process start\n");
	}

	wait(&status);

	if((pid2 = fork()) == 0){

		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		
		read(0, line, MAX_LINE);

		for(i = 0; i < strlen(line); i++){
			if('a' <= line[i] && line[i] <= 'z')
				printf("%c", line[i] - 32);
			else 
				printf("%c", line[i]);
		}
		
		exit(2);
	}

	wait(&status);

	exit(0);
}









