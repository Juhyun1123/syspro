#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	printf("parental Process start\n");

	if(fork() == 0){
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "first fail\n");
		exit(1);
	}

	printf("parental process end\n");
}
