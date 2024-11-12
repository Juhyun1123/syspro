#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 50

int main(void){
	char cmd[MAX_LINE_LENGTH];
	int status;

	while(1){
		printf("pis input cmd : ");
		fgets(cmd, MAX_LINE_LENGTH, stdin);
		cmd[strlen(cmd) - 1] = '\0';

		if(strcmp(cmd, "Exit") == 0) 
			break;
		
		if((status = system(cmd)) != 0)
			exit(1);
	
	}
	
	exit(0);
}
