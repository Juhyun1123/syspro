#include <stdio.h>
#include <unistd.h>

void main(void){
	int pid, gid;
	printf("PARENT: PID = %d GID = %d\n", getpid(), getpgrp());
	pid = fork();
	if(pid == 0){
		printf("CHILD: PID = %d GID = %d\n", getpid(), getpgrp());
	}
}
