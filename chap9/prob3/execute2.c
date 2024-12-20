#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	printf("parental process start\n");

	if(fork() == 0){
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "first fail\n");
		exit(1);
	}

	if(fork() == 0){
		execl("/bin/date", "date", NULL);
		fprintf(stderr, "second fail\n");
		exit(2);
	}

	if(fork() == 0){
		execl("/bin/ls", "ls", "-l", NULL);
		fprintf(stderr, "third fail\n");
		exit(3);
	}

	printf("parental process end\n");
}

