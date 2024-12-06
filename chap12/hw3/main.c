#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024

int upper(char *line);
int commandPipe(char *command1, char *command2);

int main(int argc, char *argv[]){
	char line[MAX_LINE];
	char *command1, *command2;

	printf("[shell]");
	fgets(line, sizeof(line), stdin);

	if(strchr(line,'|') != NULL){
		command1 = strtok(line, "| \n");
		command2 = strtok(NULL, "| \n");
		commandPipe(command1, command2);
	}else{
		upper(line);
	}
}

int commandPipe(char *command1, char *command2){
	int fd[2];
	pipe(fd);

	if(fork() == 0){
		close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		
		execlp(command1, command1, NULL);
		perror("pipe");
	}else{
	
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		printf("a");
		execlp(command2, command2, NULL);
		perror("pipe");
	}
}



int upper(char *line){

	int fd[2];
	int status, i;

	pipe(fd);
	
	if(fork() == 0){
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		
		printf("%s", line);

		exit(1);
	}else{
		printf("parent process start\n");
	}

	wait(&status);

	if(fork() == 0){

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










