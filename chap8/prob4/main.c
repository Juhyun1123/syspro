#include <stdio.h>
#include <stdlib.h>

static void exit_handler1(void);
static void exit_handler2(void);

int main(void){
	if(atexit(exit_handler1) != 0)
		perror("exit_handler1 update fail\n");
	if(atexit(exit_handler2) != 0)
		perror("exit_handler2 update fail\n");

	printf("main done\n");
	exit(0);
}

static void exit_handler1(void){
	printf("first exit handler\n");
}

static void exit_handler2(void){
	printf("second exit handler\n");
}
