#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 100

int main(void){
	
	int pid, fd[2], n, status;
	char message[MAX_LINE];
	char line[MAX_LINE];

	pipe(fd);

	if((pid = fork()) == 0){
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		
		printf("Recv: [%d] ",getpid());
		
		while(scanf("%s", line) != EOF){
			printf("%s ", line);
		}
		printf("\n");
		
	}else{
		printf("Send: [%d] Hello from PID %d\n",getpid(), getpid());
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		
		printf("Hello from PID %d\n", getpid());
		fflush(stdout);
	}
	
	exit(0);
	
}


