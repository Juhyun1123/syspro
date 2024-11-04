#include <stdio.h>
#include <unistd.h>

int main(void){
	printf("my provess number: [%d]\n", getpid());
	printf("my parent process number: [%d]\n", getppid());

	return 0;
}
